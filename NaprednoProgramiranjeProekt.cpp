#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct covidMK

{
string grad;
int novi;
int ozdraveni;

    covidMK(const string& grad, int novi, int ozdraveni)

    : grad(grad), novi(novi), ozdraveni(ozdraveni){}

bool operator>(const covidMK& c) const
    {
        return novi > c.novi; //sporedba za sortiranje po novi
    }

};

struct SortPointers
{
    bool operator()(const covidMK* a, const covidMK* b) const
    {
        return *a > *b;
    }
};

int main()
{
vector<covidMK*> vcmk; //definiranje na vektorot
//8zapisi
vcmk.push_back(new covidMK( "Skopje", 149, 149));
vcmk.push_back(new covidMK( "Kumanovo", 8, 8));
vcmk.push_back(new covidMK( "Bitola", 36, 25));
vcmk.push_back(new covidMK( "Prilep", 20, 6));
vcmk.push_back(new covidMK( "Tetovo", 2, 2));
vcmk.push_back(new covidMK( "Kavadarci", 17, 14));
vcmk.push_back(new covidMK( "Veles" , 11, 2));
vcmk.push_back(new covidMK( "Ohrid" , 10, 2));

for(const auto* c: vcmk)

cout <<c->grad <<" "<< c->novi << " " << c->ozdraveni<< '\n';

cout<<endl<<"Sortirani:"<<endl;
sort(vcmk.begin(), vcmk.end(), SortPointers());

for(const auto* c: vcmk)

cout <<c->grad <<" "<< c->novi << " " << c->ozdraveni<< '\n';

//vector vo nadvoreshen fajl
ofstream outFile ("INKI921.covid2903.txt");
for (const auto& e: vcmk) outFile<<e<<endl;

for(auto* c: vcmk)
delete c;

}
