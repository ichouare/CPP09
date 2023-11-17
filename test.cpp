#include <iostream>
#include <string>


std::string trim(std::string original)
{
    unsigned int begin_index = 0;
    unsigned int i = 0;
    if(original.size() == 0)
        return "";
    while(isblank(original[i])&& i <= original.size())
    {
        begin_index++;
        i++;
    }
    i = original.size() - 1;
    while(isblank(original[i]) != 0)
    {
    std::cout << i << " <<" <<  original[i]  << ">>" << std::endl;
        i--;

    }
    std::cout << i << " " << std::endl;
     if(begin_index == original.size())
        return "";
    return original.substr(begin_index, (i - begin_index) + 1);
}


int main()
{
   std::string filename = trim("                                                                     ussam                                              ");
   std::cout  << "|" << filename << "|" << std::endl;
}