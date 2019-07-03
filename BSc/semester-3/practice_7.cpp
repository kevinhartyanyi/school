#include <iostream>

struct Elem
{
    int data;
    Elem(const int& data): data(data) {}
    Elem(): data(0) {};
    Elem(Elem* e): data(e->data) {std::cout << "*" << "\n";};
    Elem& operator=(const Elem& e) {data = e.data; return *this;};
    friend std::ostream& operator <<(std::ostream& os, const Elem& elem);
};

std::ostream& operator <<(std::ostream& os, const Elem& elem)
{
    os << elem.data << "\n";
    return os;
}

int main()
{
    Elem* ap = new Elem();
    ap->data = 20;
    Elem* ap2 = new Elem(ap);
    Elem a(5);
    Elem a2(ap);
    Elem a3;
    a.data = 1;
    a2.data = 10;
    ap->data = 40;
    ap->data = 12;
    
    std::cout << a << a2 << a3 << *ap << *ap2 << "\n";


    Elem e(5);
    Elem e2(2);
    Elem e3;
    e3 = e = e2;
    std::cout << e << e2 << e3 << "\n";

    
    Elem* p = new Elem(5);
    Elem* p2 = new Elem();
    Elem* p3 = p;
    p->data = 1;
    p3->data = 10;
    std::cout << *p << *p2 << *p3; 

    delete p;
    delete p2;

    std::cout <<"H";
}