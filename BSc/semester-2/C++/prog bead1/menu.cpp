#include <iostream>
#include "menu.h"

//Polinom poli(2);

void Menu::Run()
{
    int v;
    do{
        v=MenuPrint();
        switch(v)
        {
            case 1:
                Add();
                Kiir();
                break;
            case 2:                
                Kiir();
                break;
            case 3:
                Helyiertek();
                Kiir();
                break;
            case 4:
                Osszead();
                Kiir();
                break;
            case 5:
                Szorzas();
                Kiir();
                break;
            case 6:
                CopyKonstruktorTeszt();
                break;
            case 7:
                ErtekadasTeszt();
                break;
            case 8:
                TerhelesTeszt();
                break;
            default:
                std::cout<<"\nKilepes!\n";
                break;

        }
    }while(v!=0);
}

int Menu::MenuPrint()
{
    //Letrehoz();
    const int n=8;
    int valasz;
    std::cout<<"\n****************************************\n";
    std::cout<<"0. Kilepes\n";
    std::cout<<"1. Polinomba berak\n";
    std::cout<<"2. Polinomot kiirja\n";
    std::cout<<"3. Helyiertek szamitas\n";
    std::cout<<"4. Polinom osszeadas\n";
    std::cout<<"5. Polinom szorzas\n";
    std::cout<<"6. Copy konstruktor tesztelese\n";
    std::cout<<"7. Ertekadas operator tesztelese\n";
    std::cout<<"8. Terheles teszt (mennyi elemet tudunk a Polinomba tenni)\n";
    std::cout<<"****************************************\n";
    do{
        std::cout<<"Valasztott: ";
        std::cin>>valasz;
    }while(valasz<0 || valasz>n);

    return valasz;
}

void Menu::Letrehoz()
{
    bool hiba = false;
    do{
    std::cout << "Mielott elkezdjuk hozzon letre egy Polinomot." <<std::endl;
    try
    {
       Polinom teszt;        
    }catch(Polinom::Hiba rossz)
    {
        
        hiba = true;
        if(rossz == Polinom::HibasErtek)
        {
            std::cout << "Hibas erteket adott meg" << std::endl;
        }
        else
        {
            std::cout << "Hiba" << std::endl;
        }
    }
    
    }while(hiba);
}

void Menu::Add()
{
    int ujadat;
    std::cout << "Milyen szamot rakjunk a Polinomba?" << std::endl;
    std::cin >> ujadat;
    try
    {
        p.Add(ujadat);
    }catch(Polinom::Hiba rossz)
    {
        if(rossz == Polinom::NincsElegMemoria)
        {
            std::cout << "Nincs eleg memoria." << std::endl;
        }
        else
        {
            std::cout << "Hiba." << std::endl;
        }
    }
}

void Menu::Kiir()
{
    std::cout << "Polinom tartalma: " << std::endl;
    p.kiiras();
}

void Menu::Helyiertek()
{
    int helyi;
    std::cout << "Milyen szamnak a helyierteket szeretne?" << std::endl;
    std::cin >> helyi;
    std::cout << "Helyiertek: ";
    std::cout << p.Helyertek(helyi) << std::endl;
}

void Menu::Osszead()
{
    Polinom a(3,"4 2 1");
    Polinom b(5,"1 7 10 6 8");
    Polinom c = a + b;
    std::cout << "Elso Polinom" << std::endl;
    a.kiiras();
    std::cout << "Masodik Polinom" << std::endl;
    b.kiiras();
    std::cout << "Osszeg Polinom" << std::endl;
    c.kiiras();
}

void Menu::Szorzas()
{
    Polinom a(3,"4 2 1"); 
    std::cout << "Polinom" << std::endl;
    a.kiiras();    
    int szam; 
    std::cout << "Irja be mivel szeretne megszorozni a Polinomot:" << std::endl;
    std::cin >> szam;  
    Polinom c = a * szam;
    std::cout << "Szorzat Polinom" << std::endl;
    c.kiiras();
}

void Menu::CopyKonstruktorTeszt()
{
    Polinom masolat = p;
    std::cout << "Az eredeti: " << std::endl;    
    std::cout << p;
    std::cout << "A masolat: " << std::endl;    
    std::cout << masolat;
    int uj = 0;
    std::cout<<"Rakjon valamit az eredeti Polinomba:";
    std::cin >> uj;
    p.Add(uj);

    std::cout<<"Rakjon valamit a masolt Polinomba:";
    std::cin >> uj;
    masolat.Add(uj);
    

    std::cout<<"Ellenorizze, hogy nem kulonbozik" <<std::endl;
    std::cout<<"Eredeti: " << p;
    std::cout<<"Masolt: " << masolat;
}

void Menu::ErtekadasTeszt()
{
    std::cout<<"Eredeti Polinom:" << p;
    std::cout<<"Letrehozunk egy uj Polinomot." << std::endl;
    int m;
    
    //Itt tesztelhetjük azt a kivételt, ha negatív vagy nulla méretet
    //adunk meg a sor konstruktorának.
    try{
        Polinom uj;
        std::cout<<"Tegyen valamit az uj Polinomba" << std::endl;
        int adat = 0;        
        std::cin>>adat;
        uj.Add(adat);
        std::cout<<"Az uj adat utan a Polinom: " << std::endl;
        std::cout << uj;
        uj = p;
        std::cout<<"uj = Eredeti ertekadas utan az uj tartalma:\n"<< uj <<std::endl;
        std::cout<<"Ertekadas utan az Eredeti tartalma:\n"<< p << std::endl;
        std::cout<<"Tegyen valamit az uj-ba" << std::endl;
        std::cin>>adat;
        uj.Add(adat);
        std::cout<<"Az uj tartalma a beteves utan:\n"<<uj;
        std::cout<<"Tegyen valamit az Eredetibe" << std::endl;
        std::cin>>adat;
        p.Add(adat);
        std::cout<<"Az Eredeti tartalma a beteves utan:\n"<<p;
        p = p;
        std::cout<<"Eredeti = Eredeti ertekadas utan:" << std::endl;
        std::cout<<p<<std::endl;

    }catch(Polinom::Hiba rossz)
    {
        if (rossz == Polinom::NincsElegMemoria)
        {
            std::cout<<"Nincs eleg memoria." << std::endl;
        }
        else
        {
             std::cout<<"Hiba." << std::endl;
        }
    }
}

void Menu::TerhelesTeszt()
{
    
    Polinom terhel;
    std::cout<<"A Polinom pillanatnyi elemszamat kovetheti:" << std::endl;
    try
    {
        int i = 1;
        while(true)
        {
            std::cout << i << std::endl;
            terhel.Add(i);
            ++i;
        }
    }catch(Polinom::Hiba rossz)
    {
        if (rossz == Polinom::NincsElegMemoria)
        {
            std::cout<<"Nincs eleg memoria" << std::endl;            
        }
        else
        {
            std::cout <<"Hiba" << std::endl;
        }
    }
}