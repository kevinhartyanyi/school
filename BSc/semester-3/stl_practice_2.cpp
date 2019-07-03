#include <iostream>
#include <set>
#include <vector>
#include <algorithm>


template<typename Container, typename T>
bool search(const Container& cont, const T& t)
{
    for (typename Container::const_iterator i = cont.begin(); i != cont.end(); ++i)
    {    
        if (*i == t) {
            return true;
        }
    }
    return false;        
}


int main()
{
    std::set<int> s;
    s.insert(3);
    s.insert(3);
    s.insert(1);
    s.insert(2);

    std::vector<int> v;
    v.push_back(2);
    v.push_back(4);
    v.push_back(1);

    std::cout << search(v,1);
    std::cout << search(s,1);


    std::vector<int>::iterator it = std::find(v.begin(),v.end(),1);
    
    
    if(it != v.end())
    {
        std::cout << "Found " << it-v.begin() << "\n";
        std::cout << v[it-v.begin()] << "\n";
        std::cout << *it << " " << *v.begin() << " " <<*v.end() <<   "\n";        
    }

    
    
    return 0;
}
