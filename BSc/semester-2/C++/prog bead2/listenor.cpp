#include "listenor.h"
#include <sstream>
#include <iostream>

Listenor::Listenor (std::string filename)
{
    x.open(filename.c_str());
    if(x.fail())
    {
        std::cout << "Nem sikerult megnyitni a fajlt." << std::endl;
        throw FILEERROR;
    }    
}

void Listenor::read()
{
    std::string n;
    std::getline(x,n);
    if(x.fail())
    {        
        sx = abnorm;        
    }
    else
    {
        end = false;        
        sx = norm;
        std::stringstream ss(n);
        ss >> dx.name;
        ss >> dx.team;
        ss >> dx.location;
        ss >> dx.place;
    }
}


void Listenor::Next()
{
    if(sx == norm)
    {
        akt.score = 0;
        akt.name = dx.name;
        while(sx == norm && akt.name == dx.name)
        {
            switch (dx.place)
            {
                case 1: akt.score += 25; break;
                case 2: akt.score += 18; break;
                case 3: akt.score += 15; break;
                case 4: akt.score += 12; break;
                case 5: akt.score += 10; break;
                case 6: akt.score += 8; break;
                case 7: akt.score += 6; break;
                case 8: akt.score += 4; break;
                case 9: akt.score += 2; break;
                case 10: akt.score += 1; break;              
            }
            
            read();
        } 
        std::cout << akt.name <<" " << akt.score << std::endl;       
    }
    else
    {
        end = true;
        sx = abnorm;
    }
} 