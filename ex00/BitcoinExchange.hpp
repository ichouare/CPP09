#ifndef BTC_H
#define BTC_H

#include <iostream>
#include <fstream>
#include <map>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

 struct m_date{
    int date[3];
    std::string line;
    std::map<std::string, double> price;
    std::map<std::string, double>::iterator it;
    int count;
};

void Btc(std::string file_Input, std::string Data);
// class Btc{

//     public:
        
//     private:
//     Btc();
//     std::fstream file_1;
//     std::fstream file_2;
//     std::string line;
//     std::map<std::string, double> price;
//     std::map<std::string, double>::iterator it;


// };


#endif