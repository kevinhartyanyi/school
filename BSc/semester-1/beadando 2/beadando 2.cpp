#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int Db = 0;
    int seged;
    for (int i = 1; i <= N; ++i)
    {
        cin >> seged;
        if (seged < 10)
        {
            ++Db;
        }
    }

    cout << Db;

    return 0;
}
