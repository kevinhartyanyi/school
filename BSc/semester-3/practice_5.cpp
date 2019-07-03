#include <iostream>


class A
{
public:
    A(int i) {std::cout << "Int"; }
    A() {std::cout << "Default";}
    A &operator=(const A &a) {std::cout << "=";}
    A(const A &a) {std::cout << "Copy";}
    bool operator==(const A &a1) {std::cout << "=="; return true;}
    ~A() { std::cout << "Delete";}
};


int main()
{
    A a;
    A a2(3);
    A a3(a);
    A a4 = a3;
    if (a == a2)
    {
        
    }
}