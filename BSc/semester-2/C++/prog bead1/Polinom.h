#include <iostream>
#include <vector>

#ifndef _POLINOM_H_
#define _POLINOM_H_

class Polinom
{
private:
    int _maxHossz;//Polinom max hossza
    int _currentHossz;//Polinom jelenlegi hossza
    int* _polinom;//Polinom ertekeit tartalmazo dinamikus tomb
public:
    enum Hiba{HibasMeret, NincsElegMemoria, HibasErtek};  
    Polinom(int hossz,std::string adat); //1. megadasi lehetoseg     
    Polinom(std::vector<int> vector);//2. megadasi lehetoseg
    Polinom(int m);//3. megadasi lehetoseg
    Polinom();//Csak a menu reszhez
    ~Polinom() {delete[] _polinom;}
    
    Polinom(const Polinom& other);//Masolo konstruktor
    Polinom& operator = (const Polinom& other);//Ertekadas operator

    void Add(int uj);//Ertek hozzaadas a Polinomhoz
    void kiiras() const;//Kiirjuk a Polinom tartalmat
    int Helyertek(int szam) const;//Helyetesitesi ertek kiszamitasa a parameterkent kapott szambol

    Polinom osszead(const Polinom& other) const;//Osszeadja a parameterkent kapott Polinommal
    Polinom szorzas(const int szam) const;//Osszeszorozza a parameterkent kapott szammal a Polinomot

    friend Polinom operator + (const Polinom& a, const Polinom& b);
    friend Polinom operator * (const Polinom& a, int szam);
    friend std::ostream& operator << (std::ostream& o, const Polinom& p);


    

};

#endif