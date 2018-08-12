#include "Allatok.h"
#include <iostream>

using namespace std;

void Allatok::Kiir()
{
    cout << _nev << "-nek a kedve " << _kedv  <<endl;
}

void Hal::Nap(char kedv)
{
        
    switch(kedv)
    {
        case 'j': Valtkedv(1); break;
        case 'a': Valtkedv(-3); break;
        case 'r': Valtkedv(-5); break;
    }
}

void Madar::Nap(char kedv)
{
    
    switch(kedv)
    {
        case 'j': Valtkedv(2); break;
        case 'a': Valtkedv(-1); break;
        case 'r': Valtkedv(-3); break;
    }
}

void Kutya::Nap(char kedv)
{
    
    switch(kedv)
    {
        case 'j': Valtkedv(3); break;
        case 'a': Valtkedv(0); break;
        case 'r': Valtkedv(-10); break;
    }
}