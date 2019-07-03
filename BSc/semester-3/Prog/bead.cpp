#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <regex>
#include <fstream>




/*
std::string replace(const int& max, const std::string& string)
{
   return std::regex_replace(string, std::regex(" "),"     ");
}
*/

void align(const std::vector<std::string>& base_vector, std::vector<std::string>& new_vector, const int& max)
{
    std::transform(base_vector.begin(),base_vector.end(), new_vector.begin(), 
    [&max](const std::string& line)
    {
        int spaces = std::count(line.begin(),line.end(),' ');
        
        if (line.size() == max || spaces == 0) {
            return line;
        }
        
        int needed_spaces = max-line.size();

        std::string rep((needed_spaces/spaces)+1,' ');
    
        if (needed_spaces % spaces == 0) {
            return std::regex_replace(line, std::regex(" "),rep);
        }
        else {
            std::string tmp = std::regex_replace(line, std::regex(" "),rep);
            std::string::iterator it = std::find(tmp.begin(),tmp.end(),' ');
            if(it != tmp.end())
                tmp.insert(*it,"  ");
            return tmp;
        }        
    });
}


int main()
{
    std::vector<std::string> lines;

    std::ifstream file("text1.txt");
    if(file.fail())
        return -1;

    std::string line;
    while (std::getline(file,line))
        lines.push_back(line);
    
    
    int max_size = std::max_element(lines.begin(),lines.end(),[](const std::string& a, const std::string& b) {return a.size() < b.size();})->size();

    std::vector<std::string> aligned_lines(lines.size());

    align(lines, aligned_lines, max_size);
    for(std::string l : aligned_lines)    
        std::cout << l << "\n";


    file.close();

    return 0;
}
