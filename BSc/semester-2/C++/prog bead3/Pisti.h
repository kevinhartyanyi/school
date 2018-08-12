#ifndef _PISTI_H_
#define _PISTI_H_

#include "Allatok.h"
#include <vector>

class Pisti
{
public:
    static Pisti* Instance();
    void Ujallat(char faj, std::string nev, int kedv);
    void Nap(char kedv);
    std::vector<int> Test(char kedv);
    ~Pisti();
private:       
    Pisti() {};
    static Pisti* _instance;
    std::vector<Allatok*> allatok;///////////
};

#endif