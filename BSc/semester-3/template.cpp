#include <iostream>


using namespace std;

template<typename T>
const T& maxa(const T& a, const T& b)
{
    return a < b ? b : a;
}

template<typename T>
void spec(const T& a)
{
    cout << "normal" << "\n";
}

template<>
void spec(const bool& a)
{
    cout << "spec" << "\n";
}

template<int i>
struct Fact
{
    static const int x = Fact<i-1>::x*i;
};

template<>
struct Fact<0>
{
    static const int x = 1;
};

void h()
{
    int i;
    cout << i << "\n";
    i = 55;
}




int main()
{
    
    cout << maxa(3.7,6.7);
    cout << "\n";
    spec(3);
    spec<bool>(3);
    spec(true);

    
    
    cout << Fact<5>::x;
    h(); // random
    h(); // 55

    int i;
    cin >> i;
    int *t = new int[i];
    delete []t;
    
}