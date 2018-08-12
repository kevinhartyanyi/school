#include <iostream>
#include "Polinom.h"
#include <vector>
#include "menu.h"

//#define NORMAL_MODE_
#ifdef NORMAL_MODE_

int main()
{   
    Menu Teszt;
    Teszt.Run();
    
    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Polinom.h"

TEST_CASE("konstruktorok", "[Polinom]")
{
    Polinom p;
    CHECK(0 == p.Helyertek(2));
    
    Polinom p2(3,"2 5 6");
    CHECK(72 == p2.Helyertek(2));

    CHECK_THROWS(Polinom p3(0,"2 3"));
    CHECK_THROWS(Polinom p4(-3,"2 3 4"));
    CHECK_THROWS(Polinom p5(3,"2 a 4"));
    CHECK_THROWS(Polinom p6(3,"azz 1"));

    std::vector<int> vector(3,2);
    Polinom p7(vector);
    CHECK(6 == p7.Helyertek(1));

}

TEST_CASE("Ertek hozzaadas", "[Polinom]")
{
    Polinom p;
    p.Add(2);
    CHECK(6 == p.Helyertek(3)); 

    p.Add(1);
    CHECK(15 == p.Helyertek(3));
}

TEST_CASE("Helyiertek", "[Polinom]")
{
    Polinom p;
    p.Add(10);
    CHECK(100 == p.Helyertek(10)); 

    CHECK(-20 == p.Helyertek(-2)); 

    p.Add(2);
    CHECK(-12 == p.Helyertek(-2)); 
}

TEST_CASE("Copy konstruktor", "[Polinom]")
{
    Polinom p(2,"1 2");
    p.Add(3);
    p.Add(4);

    Polinom p2 = p;

    CHECK(p.Helyertek(2) == p.Helyertek(2)); 

    p.Add(5);
    p2.Add(2);  

    CHECK(p.Helyertek(2) != p2.Helyertek(2));   
}

TEST_CASE("Ertekadas operator", "[Polinom]") {
    
    Polinom p(2,"3 6");
    Polinom p2(3,"3 1 8");

    p2 = p;
    
    CHECK(p.Helyertek(2) == p2.Helyertek(2)); 
    CHECK(p.Helyertek(5) == p.Helyertek(5)); 
    

    Polinom p3(1,"4");
    p3 = p2 = p;
    CHECK(p.Helyertek(2) == p2.Helyertek(2)); 
    CHECK(p2.Helyertek(2) == p3.Helyertek(2)); 
    CHECK(p3.Helyertek(2) == p.Helyertek(2)); 

    p = p;
    CHECK(p.Helyertek(2) == p.Helyertek(2)); 
}

TEST_CASE("Osszeadas", "[Polinom]") {
    
   Polinom p(2,"1 2");
   Polinom p2(2,"5 3");
   Polinom p3(6,"2 9 7 3 8 3");
   Polinom p5(1,"10");

    Polinom p4 = p + p2;
    CHECK(p4.Helyertek(1) == 11);

    p4 = p2 + p3;
    CHECK(p4.Helyertek(1) == 40);


    p4 = p + p3;
    
    CHECK(p4.Helyertek(1) == 35);

}

TEST_CASE("szorzas", "[Polinom]") {
    

    Polinom p(2,"1 2");

    Polinom p2 = p * 2;
    CHECK(p2.Helyertek(2) == 20);  

    p2 = p * 0;    
    CHECK(p2.Helyertek(2) == 0); 

    p2 = p * -1; 
    CHECK(p2.Helyertek(2) == -10);  
   
}

#endif