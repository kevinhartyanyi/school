#include "Allatok.h"
#include "Pisti.h"
#include <iostream>
#include <fstream>


using namespace std;


string Feltolt(Pisti *pisti, string fajl)
{
    ifstream x(fajl);
    if(x.fail())
    {
        cout << "HIBA" << endl;
        exit(1);
    }    
    
    int allatok;
    x >> allatok;
    for(int i = 0; i < allatok; ++i)
    {
        char faj;
        string nev;
        int kedv;
        x >> faj >> nev >> kedv;
        pisti->Ujallat(faj, nev, kedv);
        cout << "Nev: " << nev << " kedv: " << kedv << " faj: " << faj << endl;
    }
    string re;
    x >> re;
    return re;
}


#define NORMAL_MODE
#ifdef NORMAL_MODE
int main()
{
    Pisti *pisti = Pisti::Instance();//////////////////////////////
    

    string napok = Feltolt(pisti, "test.txt");    
    
    for(char c : napok)
    {
        pisti->Nap(c);
    }
        

    return 0;
}
#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("1", "test1.txt") 
{
    Pisti *pisti = Pisti::Instance();

    string napok = Feltolt(pisti, "test1.txt");
    vector<int> mind;
    for(int i = 0; i < napok.size(); ++i)
    {
        mind = pisti->Test(napok[i]);
        if(i == 0)
        {
            CHECK(mind[0] == 61);
            CHECK(mind[1] == 82);
            CHECK(mind[2] == 53);
        }
        else if(i == 1)
        {
            CHECK(mind[0] == 58);
            CHECK(mind[1] == 81);
            CHECK(mind[2] == 53);
        }
        else
        {
            CHECK(mind[0] == 53);
            CHECK(mind[1] == 78);
            CHECK(mind[2] == 43);
        }
    }
    for(char c : "rrrrrrrrrrrr")
    {
        mind = pisti->Test(c);
    }
    CHECK(mind[0] == -1);
    CHECK(mind[1] == 42);
    CHECK(mind[2] == -1);

}


#endif