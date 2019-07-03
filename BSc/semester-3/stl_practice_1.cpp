#include <iostream>
#include <set>


class Circle
{
private:
    int r;
    int x;
    int y;
public:
    Circle(int r = 1, int x = 0, int y = 0):r(r),x(x),y(y) { }
    friend bool operator<(const Circle& c, const Circle& c2);
    friend bool operator==(const Circle& c,  const Circle& c2);   
    
    ~Circle() { }
};

bool operator<(const Circle& c, const Circle& c2)
{
    
    if (c.r < c2.r) {
        return true;
    }
    return false;
    
}
bool operator==(const Circle& c,  const Circle& c2)
{
    std::cout << c.r << " " << c2.r << std::endl;
    
    if (c.r == c2.r && c.x == c2.x && c.y == c2.y) {
        return true;
    }
    return false;
    
}


int main()
{
    
    /* std::set<int> s;

    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(2); */

    std::set<Circle> s2;
    Circle c(3,4);
    Circle c2(1,4);
    Circle c3(3,2);

    s2.insert(c);
    s2.insert(c2);
    s2.insert(c3);
    
    
    std::cout << s2.size();    
    
    return 0;
}
