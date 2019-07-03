#include <iostream>


void f(int& i)
{      
    i = 10;
    std::cout << i << std::endl;
}

void f2(const int& i)
{
    std::cout << i << std::endl;
}

int sum(int t[])
{
    
    int s = 0;
    for(int i = 0; i < 10; ++i)
    {
        s += t[i];
    }
    return s;
}

int main()
{
    int t[10];
    t[0] = 20;
    int* p = t;
    std::cout << *(p+1) << std::endl;
    p = &t[0];
    std::cout << *(p+2) << std::endl;

    /* for(int i = 0; 1; ++i)
    {
        t[i] = i;
        std::cout << i << t[i] <<std::endl;
    } */
    int a = 5;
    p = &a;
    std::cout << *p << std::endl;
    *p = 10;    
    std::cout << a << std::endl;

    double d;
    *(&d) = 2.3;    
    std::cout << d << std::endl;
    
    int b = 10;
    int& r = b;
    b = 20;
    std::cout << r << std::endl;
    r = 3;
    std::cout << b << std::endl;
    int& r2 = *(&b);
    r2 = 7;
    std::cout << b << std::endl;

    // p = &10;

    
    std::cout << sizeof('i')  << std::endl;
    std::cout << sizeof("i")  << std::endl;

    char c[] = {'h','e', 'l','l','o'};
    char c2 = 'A';
    char* p2 = c;
    char c3 = 'h'+'c';
    char c4 = 'M';

    std::cout << c << std::endl;
    std::cout << &c4 << std::endl;
    std::cout << &c4+2 << std::endl;    
    std::cout << *(c+2) << std::endl;


    int n = 5;
    f(n);
    std::cout << n << std::endl;

    f2(2);

    int t2[11] = {1,2,3,4,5,6,7,8,9,10,11};

    std::cout << t2[2] << std::endl;
    std::cout << 2[t2] << std::endl;
    std::cout << *(t2+2) << std::endl;
    std::cout << *(2+t2) << std::endl;

    std::cout << **(&t2) << " " << &t2 << " " << t2 << std::endl;


    int v = 4;
    int* e = &*&v;
    int** e2 = &e;
    int*** e3 = &e2;

    std::cout << *e << std::endl;
    std::cout << **e2  << " " << &v << " " << e << " " << e2 << " " << *e2 << std::endl;

    int* h = &v;
    int* h2 = h;
    h = h2;
    *h = 3;
    *h2 = 15;
    v  = 7;

    std::cout << *&v << " " << *h2 << " " << *h << std::endl;
    

    return 0;
}

