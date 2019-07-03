#include <iostream>

double pi = 3.14;

class Test
{
    const int c;
    int& r;
public:
    Test(int x):c(x),r(x) {}
};



class All
{
protected:
    int x,y;
public:
    All(int x = 0, int y = 0):x(x),y(y) {std::cout << "All constructer" << "\n";}
    virtual void area()
    {
        std::cout << "All area" << "\n";
    }
    All& operator=(const All& a)
    {
        std::cout << "All = operator" << "\n";
        x = a.x;
        y = a.y;
    }
    virtual ~All() {std::cout << "All destructer" << "\n";}
};


class Circle : public All
{
    int* r;

public:
    Circle(int radius = 0):r(new int(radius)) {std::cout << "Circle constructer" << "\n";}
    Circle& operator=(const Circle& c)
    {
        *r = *c.r;
        std::cout << "Circle = operator" << "\n";
    }
    Circle(const Circle& c):r(new int(*c.r)) 
    {
        std::cout << "Circle copy constructer" << "\n";        
    }
    Circle operator*(const Circle& c)
    {
        return Circle(*r*(*c.r));
    }
    void Out()
    {
        std::cout <<"Circle area" << *r << "\n";
    }
    ~Circle()
    {        
        std::cout << "Circle destructer" << "\n";
        delete r;
    }
    friend Circle operator*(const int& i, const Circle& c);

    void area()
    {
        std::cout << pi**r**r << "\n";
    }
    
};

class Rectangle : public All
{
    
public:
    Rectangle(int x = 0, int y = 0):All(x,y) {std::cout << "Rectangle constructer" << "\n";}

    Rectangle(const Rectangle& r) : All(r.x,r.y)
    {
        std::cout << "Rectangle copy constructer" << "\n";                
    }

    void area() override
    {
        std::cout << "Rectangle area" << x*y << "\n";
    }
    ~Rectangle() {std::cout << "Rectangle destructer" << "\n";}
};



Circle operator*(const int& i, const Circle& c)
{
    return Circle(*c.r*i);
}

void f(Circle c)
{
    c.Out();
}


int main()
{
    Circle c(3);
    Circle c2(2);
    c.Out();
    c = c2;
    c.Out();    
    c.operator=(Circle(10));
    c.Out();

    Circle c3(c);
    Circle c4 = c;
    c3.Out();

    f(c2);
    c4.Out();
    std::cout <<sizeof(Circle) <<"\n";

    Circle c5(3);
    c5 = c5*2;
    c5 = 2*c5;
    c5.Out();

    
    Rectangle rect(3,3);

    All* t[1];
    t[0] = &rect;
    t[1] = &c;
    t[0]->area();
    t[1]->area();

    Rectangle rect2(rect);

    All* a;
    a = new Rectangle(3,2);
    delete a;  

    

    
    
}