#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "listenor.h"

TEST_CASE("Egyetlen csapat", "[t0.txt]")
{
    Listenor l("t0.txt");
    Scores e;
    l.First();
    e = l.Current();
    CHECK(e.name == "Asterix");
    CHECK(e.score == 20);
    l.Next();
    e = l.Current();
    CHECK(e.name == "Luffy");
    CHECK(e.score == 28);    
    
}

TEST_CASE("Sok csapat", "[text.txt]")
{
    Listenor l2("text.txt");
    Scores e;
    l2.First();
    e = l2.Current();
    CHECK(e.name == "Rem");
    CHECK(e.score == 25);
    l2.Next();
    e = l2.Current();
    CHECK(e.name == "Zeref");
    CHECK(e.score == 14);   
    l2.Next();
    e = l2.Current();
    CHECK(e.name == "Kate");
    CHECK(e.score == 16);  
    
}

TEST_CASE("Ugyanannyi pont", "[t1.txt]")
{
    Listenor l2("t1.txt");
    Scores e;
    l2.First();
    e = l2.Current();
    CHECK(e.name == "Kate");
    CHECK(e.score == 0);
    l2.Next();
    e = l2.Current();
    CHECK(e.name == "Katarina");
    CHECK(e.score == 0);   
    l2.Next();
    e = l2.Current();
    CHECK(e.name == "Rem");
    CHECK(e.score == 0);  
    
}
