#include <iostream>

using namespace std;

int main()
{
    int madarak;
    int feszkek;
    cin>>madarak>>feszkek;

    int X[madarak];
    int Y[madarak];
    int territorium[madarak];

    int kivul = 0;

    for (int i = 0; i < madarak; i++)
    {
        cin>>X[i]>>Y[i]>>territorium[i];
    }


    for (int i = 1; i <= feszkek; i++)
    {

        for (int j = 1; j <= feszkek; j++)
        {
            bool mehet = true;
            for (int m = 0; m<madarak;m++)
            {
                /*if (j < X[m]-territorium[m])
                {
                    kivul++;
                }
                else if (j > X[m]+territorium[m])
                {
                    kivul++;
                }
                else if (i < Y[m]-territorium[m])
                {
                    kivul++;
                }
                else if (i > Y[m]+territorium[m])
                {
                    kivul++;
                }
                else
                {

                }*/

                if (j >= (X[m]-territorium[m]) && j <= (X[m]+territorium[m]) && i >= (Y[m]-territorium[m]) && i <= (Y[m]+territorium[m]) && mehet )
                {
                    kivul++;
                    mehet = false;
                }
            }

        }
    }

    cout << (feszkek*feszkek)-kivul;


    return 0;
}
