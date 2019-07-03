#include <iostream>
using namespace std;


class Count
{
public:
    static int c;
    Count() { ++c; }
    ~Count() {--c;}
};
    int Count::c = 0;

int main()
{

    Count c;
    Count c2;
    Count c3;
    cout << Count::c << endl;
    
    
    return 0;
}
