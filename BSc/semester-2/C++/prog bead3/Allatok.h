#ifndef _ALLATOK_H_
#define _ALLATOK_H_
#include <string>

class Allatok
{
public:
    bool el() {return _kedv > 0;}     
    virtual void Nap(char kedv) {};
    void Kiir();
    int Kedv() {return _kedv;}
    std::string Nev() {return _nev;} ;

protected:
    Allatok(std::string nev, int kedv = 0): _nev(nev), _kedv(kedv) { } 
    void Valtkedv(int ertek) {_kedv += ertek;}  

private:
    std::string _nev;
    int _kedv;
};

class Hal : public Allatok
{
public:
    Hal(std::string nev, int kedv = 0): Allatok(nev, kedv) {}
    void Nap(char kedv) override;
};

class Madar : public Allatok
{
public:
    Madar(std::string nev, int kedv = 0): Allatok(nev, kedv) {}
    void Nap(char kedv) override;
};

class Kutya : public Allatok
{
public:
    Kutya(std::string nev, int kedv = 0): Allatok(nev, kedv) {}
    void Nap(char kedv) override;
};

#endif

