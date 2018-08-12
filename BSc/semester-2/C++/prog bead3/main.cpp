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


