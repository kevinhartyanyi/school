#ifndef HEADER
#define HEADER

#include <set>
#include <vector>
#include <algorithm>

template <class T>
struct TRUE
{
    bool operator()(const T& t)
    {
        return true;
    }
};

template<class T, class F = TRUE<T>>
class set_multi_util
{
private:
    std::set<T>& s;
    std::vector<T> v;
public:
    set_multi_util(std::set<T>& s): s(s) 
    {
        v.resize(s.size());
        std::copy(s.begin(),s.end(), v.begin());
    }
    set_multi_util& insert(const T& t)
    {
        v.push_back(t);
        s.insert(t);
        return *this;
    }
    int count(const T& t) const
    {
        return std::count(v.begin(),v.end(),t);
    }
};



#endif // !HEADER