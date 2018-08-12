#include <iostream>
#include "Polinom.h"
#include <string>
#include <vector>
#include <math.h>



Polinom::Polinom(int hossz,std::string adat)//1. megadasi lehetoseg
{
    //Tomb hossz ellenorzes
    if(hossz <= 0)
    {
        throw HibasMeret;
    }
    _maxHossz = hossz;//Max hossz   
    _polinom = new int[hossz];
    int k = 0; //String index
    int c = 0; //Tomb index
    while(k < adat.length())
    {
        if(adat[k] != ' ')
        {
            std::string uj = "";//Ebben lesz az uj ertek amelyet a tombhoz adunk            
            int j = k;
            while(j < adat.length() && adat[j] != ' ')//Uj ertek feltoltese
            {
                if(!isdigit(adat[j]))
                {
                    throw HibasErtek;
                }

                uj += adat[j];
                j++;
            }            
            k += (j-k);            
            _polinom[c] = atoi(uj.c_str());
            ++c; 
        }        
        ++k;  
    }
    _currentHossz = c;//Jelenlegi hossz
}

Polinom::Polinom(std::vector<int> vector)//2. megadasi lehetoseg
{
    if(vector.size() == 0)
    {
        throw HibasMeret;
    }

    _currentHossz = vector.size();
    _maxHossz = vector.size();
    _polinom = new int[_maxHossz];

    for(int i = 0; i < vector.size(); ++i)
    {
        _polinom[i] = vector[i];
    }
}

Polinom::Polinom(int m)//3. megadasi lehetoseg
{   
    _polinom = new int[10];
    _maxHossz = 10;
    _currentHossz = 0;

    std::string stop = "";//Ciklus kilepeshez
    
    while(stop != "Stop")
    {
        std::cout<<"Irja be az uj erteket a Polinomnak\n('Stop', ha nem akar uj erteket): ";
        std::cin >> stop;

        if(stop != "Stop") 
        {
            for(int i = 0; i < stop.length(); ++i)//stop ellenorzese
            {
                if(!isdigit(stop[i]))
                {
                    throw HibasErtek;
                }
            }
            int ujertek = atoi(stop.c_str());            
            Add(ujertek);//Lejjebb definialt fuggveny
        }
    }
}

Polinom::Polinom()
{
    _maxHossz = 0;
    _currentHossz = 0;
    _polinom = new int[0];
}


void Polinom::kiiras() const//Polinom kiirasa
{
    for(int i = 0; i < _currentHossz; ++i)
    {        
        if(i > 0)
        {
            std::cout << _polinom[i] << "x" << "^" << i+1 << " ";            
        }
        else
        {
            std::cout << _polinom[i] << "x ";
        }
    }
    std::cout << std::endl;
}

void Polinom::Add(int uj)//Ertek hozzadasa a mar meglevo Polinomhoz
{
    if(_currentHossz < _maxHossz)//Ha meg van hely akkor felvesszuk az ujat
    {
        _polinom[_currentHossz] = uj;
        ++_currentHossz;
        //++_maxHossz;
    }
    else//Ha nincs hely, akkor kibovitjuk a tombot +1 hellyel
    {
        
        int* ujadat =  new (std::nothrow) int[_maxHossz+1];

        if(ujadat == NULL)
        {
            throw NincsElegMemoria;
        }
    
        for(int i = 0; i < _maxHossz; ++i)
        {
            ujadat[i] = _polinom[i];        
        }        

        ujadat[_maxHossz] = uj;           
        delete[] _polinom;
        _polinom = new int[_maxHossz+1];//Ujra elkeszitjuk a polinomot (1-el nagyobban)
        for(int i = 0; i < _maxHossz+1; ++i)
        {
             _polinom[i] = ujadat[i];            
        }
        
        delete[] ujadat;
        ++_currentHossz;
        ++_maxHossz;
    }
}

int Polinom::Helyertek(int szam) const//Helyetesitesi ertek kiszamitasa
{
    double osszeg = 0;//A vegso osszeg
    for(int i = 0; i < _currentHossz; ++i)
    {
        osszeg += (double)_polinom[i] * pow((double)szam, i+1);
    }

   return osszeg;
}

Polinom::Polinom(const Polinom& other)//Masolo konstruktor
{
    _maxHossz = other._maxHossz;
    _currentHossz = other._currentHossz;    
    _polinom = new int[_currentHossz];
    for(int i = 0; i < _currentHossz; ++i)
    {
        _polinom[i] = other._polinom[i];
    }
}

Polinom& Polinom::operator = (const Polinom& other)//Ertekadas operator
{
    if(this == &other)//Ha a = a
    {
        return *this;
    }

    delete[] _polinom;
    _polinom = new int[_currentHossz];
    _maxHossz = other._maxHossz;
    _currentHossz = other._currentHossz;
    for(int i = 0; i < _currentHossz; ++i)
    {
        _polinom[i] = other._polinom[i];
    }

    return *this;
}

Polinom Polinom::osszead(const Polinom& other) const//Osszeadas
{
    std::vector<int> ujPolinom;//Vector amibol az uj Polinom lessz
    int meddig;//Meddig menjunk osszeadassal
    int max;//Maradek
    if(_currentHossz < other._currentHossz)
    {
        meddig = _currentHossz;   
        max = other._currentHossz;     
    }
    else
    {
        meddig = other._currentHossz;   
        max = _currentHossz;     
    }

    for(int i = 0; i < meddig; ++i)//Addig megyunk amig van mindket Polinomban ugyan olyan hatvanyu x
    {        
        ujPolinom.push_back(_polinom[i] + other._polinom[i]);//Feltoltjuk a vectort az osszadaott ertekekkel 
    }

    for(int i = meddig; i < max; ++i)//Maradek(ha van) feltoltese
    {
        if(max == _maxHossz)
        {
            ujPolinom.push_back(_polinom[i]);
        }
        else
        {
            ujPolinom.push_back(other._polinom[i]);
        }
    }

    return (Polinom(ujPolinom));
}

Polinom Polinom::szorzas(const int szam) const//Szorzas
{
    std::vector<int> ujPolinom;//Vector amibol az uj Polinom lessz

    for(int i = 0; i < _currentHossz; ++i)
    {        
        ujPolinom.push_back(_polinom[i] * szam);//Feltoltjuk a vectort a szorzott ertekekkel 
    }

    return (Polinom(ujPolinom));
}

Polinom operator + (const Polinom& a, const Polinom& b)
{
    Polinom ujPoli = a.osszead(b);

    return ujPoli;
}

Polinom operator * (const Polinom& a, int szam)
{
    Polinom ujPoli = a.szorzas(szam);

    return ujPoli;
}

std::ostream& operator <<(std::ostream& o, const Polinom& p)
{
    for(int i = 0; i < p._currentHossz; ++i)
    {        
        if(i > 0)
        {
            o << p._polinom[i] << "x" << "^" << i+1 << " ";            
        }
        else
        {
            o << p._polinom[i] << "x ";
        }
    }
    o << std::endl;

    return o;
}

