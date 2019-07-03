#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int main()
{
    ifstream f;
    f.open("mirror.txt");
    if(f.fail())
        cout << "Error while loading the file" << endl;

    stack<char> verem;    
    char c = ' ';

    bool in = true; 
    
    while(f >> c)
    {  
        cout << c << endl;
        if(in)
        {
            if(c != '#')
                verem.push(c);
            else if(!verem.empty())
                in = false;
        }
        else
        {
            if(c != '#')
            {
                if(verem.top() == c)
                {
                    verem.pop();
                    if(verem.empty())
                        in = true;
                }
                else
                    break;
            }
            else
                in = true;
        } 
             
    }
    f.close();

    if(verem.empty())
        cout << "Mirrored" << endl;
    else
        cout << "Not mirrored" << endl;

    



    return 0;
}