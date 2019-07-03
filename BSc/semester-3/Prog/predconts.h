#ifndef HEADER
#define HEADER
#include <iostream>
template <class Cont, class F, class T>
class predicate_containers
{
    Cont& a;
    Cont& b;
    const F& f;
public:
    predicate_containers(Cont& a, Cont& b,const F& f): a(a), b(b), f(f)
    {
        a.clear();
        b.clear();

    }
    predicate_containers& insert(const T& t)
    {
            //std::cout << t << "aba\n";
        if(f(t))
        {
            //std::cout << t << "\n";
            a.push_back(t);
        }
        else
        {

            //std::cout << t << "\n";
            b.push_back(t);
        }
        return *this;
    }
};

#endif