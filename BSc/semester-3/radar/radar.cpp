#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct cord
{
    double x;
    double y;
};

struct circle
{
    cord cordinates;
    string radius;
};

struct radar
{
    cord cordinates;
    string first;
    string second;
};



int main()
{

    ifstream file("text.txt");
    string line;
    

    if(file.fail())
        cout << "No file";
    else
    {
        getline(file, line);
        int cities = stoi(line);        
        radar radars[3];
        vector<circle> city;        

        for(int i = 0; i < 3+cities; ++i)
        {
            getline(file, line);
            stringstream ss(line);
            string s;
            if(i < 3)
            {                
                ss >> s;                
                radars[i].cordinates.x = stod(s);
                ss >> s;
                radars[i].cordinates.y = stod(s);
                ss >> radars[i].first;                
                ss >> radars[i].second;                
            }
            else
            {
                circle c;
                ss >> s;                
                c.cordinates.x = stod(s);
                ss >> s;
                c.cordinates.y = stod(s);
                ss >> s;
                c.radius = s;
                city.push_back(c);
            }
        }






    }
    file.close();
}
