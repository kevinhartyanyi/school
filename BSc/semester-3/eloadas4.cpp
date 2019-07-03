#include "eloadas4.h"
#include <iostream>

void g();

int main()
{
    extern int x;

    int t[][2] = {{1,2},{2,3},{3,4}};

    int (*p)[2] = t;
    int size = sizeof(t) / sizeof(t[0]);
    
    std::cout << size;
}