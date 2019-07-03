#include <iostream>
using namespace std;

template<typename T>
class C
{
public:
    void f() {}
    static int x;
};


template<>
class C<bool>
{
public:
    int f;
    class x {};
};


template<typename T>
void f()
{
    typename C<T>::x a;
}


int main()
{
    f<bool>();    
    
    return 0;
}
