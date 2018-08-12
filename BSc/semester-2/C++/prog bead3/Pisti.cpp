#include "Pisti.h"
#include <iostream>

using namespace std;

Pisti* Pisti::_instance = nullptr;

Pisti::~Pisti()
{
    for(int i = 0; i < allatok.size(); ++i)
    {
        delete allatok[i];
    }
}

Pisti* Pisti::Instance()
{
    if(_instance == nullptr)
        _instance = new Pisti();
    return _instance;
}

void Pisti::Ujallat(char faj, string nev, int kedv)
{
    switch(faj)
    {
        case 'H': allatok.push_back(new Hal(nev, kedv)); break;
        case 'M': allatok.push_back(new Madar(nev,kedv)); break;
        case 'K': allatok.push_back(new Kutya(nev,kedv)); break;
    }
}

void Pisti::Nap(char kedv)
{
    for(Allatok* a : allatok)
    {
        
        if(a->el())
        {
            a->Nap(kedv);
            a->Kiir();
        }
        else
            cout << a->Nev() << " meghalt" << endl;
    }
    
}



////////////////////////////////////

vector<int> Pisti::Test(char kedv)
{
    vector<int> re;
    for(Allatok* a : allatok)
    {
        a->Nap(kedv);
        if(a->el())
            re.push_back(a->Kedv());
        else
            re.push_back(-1);
    }
    return re;
    
}
