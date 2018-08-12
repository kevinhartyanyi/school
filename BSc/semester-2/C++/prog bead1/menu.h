#ifndef MENU_H_
#define MENU_H_
#include "Polinom.h"

class Menu
{    
    
    public:
        Menu(){};        
        void Run();
    private:
        int MenuPrint();
        void Add();
        void Kiir();
        void Helyiertek();
        void Osszead();
        void Szorzas();
        void CopyKonstruktorTeszt();
        void ErtekadasTeszt();
        void TerhelesTeszt();
        Polinom p;
        void Letrehoz();
        

};

#endif // MENU_H_
