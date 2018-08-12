#include "listenor.h"
#include <iostream>

int main()
{
    std::string filename = "";
    std::cout << "Irja be a fajl nevet: ";
    std::cin >> filename;    
    Listenor l(filename);
    l.First();    
    int max = l.Current().score;
    Scores elem = l.Current();
    l.Next();
    //std::cout << l.End() << std::endl; 
    while(!l.End())
    {
        if(l.Current().score > max)
        {
            max = l.Current().score;
            elem = l.Current();
        }

        l.Next();
    }

    std::cout << "Jelenleg a bajnoksagot " << elem.name << " vezeti.";
    return 0;

}