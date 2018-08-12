#ifndef _LISTENOR_H_
#define _LISTENOR_H_

#include "list.h"
#include <fstream>

class Listenor
{
public:
    enum Status{abnorm, norm};
    enum Exceptions{FILEERROR};

    Listenor(std::string filename);
    void First() {read(); Next();};
    void Next();
    Scores Current() const {return akt;};
    bool End() const {return end;};


private:
    bool end;
    void read();
    Scores akt;
    List dx;
    Status sx;
    std::ifstream x;
};

#endif