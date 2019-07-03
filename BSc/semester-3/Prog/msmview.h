#ifndef HEADER
#define HEADER
#include <set> 
#include <vector>
#include <iostream>
#include <algorithm>

template <class T>
class multisets_merge_view
{
private:
    const std::multiset<T> original1;
    const std::multiset<T> original2;
    std::multiset<T>& ref1;
    std::multiset<T>& ref2;
    std::vector<T> unio;

public:

    /* struct iterator
    {
        int i;
        std::multiset<T>& m;
        iterator()
    };

    iterator begin() {return ;}
    iterator end() {return ;} */

    multisets_merge_view(std::multiset<T>& a, std::multiset<T>& b): ref1(a), ref2(b), original1(a), original2(b)
    {

    typename std::multiset<T>::iterator it = a.begin();

        while(it != a.end()){
            unio.push_back(*it);
            ++it;
        }
        it = b.begin();
        while(it != b.end()){
            unio.push_back(*it);
            ++it;
        }
        std::sort(unio.begin(), unio.end());

        int size1 = a.size();
        int size2 = b.size();
        a.clear();
        b.clear();
        for (int i = 0; i < unio.size(); i++)
        {
            
            if (i < size1) {
                a.insert(unio[i]);
            }
            else {
                b.insert(unio[i]);
            }
        }
        
    }



    ~multisets_merge_view()
    {
        ref1 = original1;
        ref2 = original2;
    }
};

#endif // !HEADER
