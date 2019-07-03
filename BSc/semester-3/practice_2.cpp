#include <iostream>
#include <string>

using namespace std;

void ki(const string &c)
{
    cout << c <<"\n";
}
void ki(const int c)
{
    cout << c <<"\n";
}
void ki(const int* c)
{
    cout << *c <<"\n";
}

int f()
{
    int a = 2;
    cout << a << endl;
    return a;
}
int h()
{
    int a = 5;
    cout << a << endl;
    return a;
}
int g(int a)
{
    cout << a << endl;
    return a;
}

int main()
{
    int b = 10;
    auto c = 20;
    int d = 20;
   
   int* z = &d;

    int& a = *z;
    a = 30;
    c = 23;

    static int p = 7;    
    int* j = &b;
    int** l = &j;

    int** r = new int*(&p);
    string s = "zxy";
    cout << (s < "abc") << '\n';

    g('A');
    h();

   
   void* v = &c;
   auto* v2 = &c;
   cout << *v2;


        
    

}