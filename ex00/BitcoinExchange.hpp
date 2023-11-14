#ifndef BTC_H
#define BTC_H

#include <iostream>
#include <fstream>
#include <map>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>


 struct m_date{
    int date[3];
    int min_date[3];
    std::string line;
    std::map<std::string, float> price;
    std::map<std::string, float>::iterator it;
};

void Btc(std::string file_Input, std::string Data);
std::string trim(std::string original);
int ft_isalpha(std::string str , int cnt);
int check_date(m_date& m_d);
int check_date_data(m_date m_d);
int parser_date_data(std::string key);
int parser_date(std::string key, m_date& Date);
void check_files(std::string file_Input, std::string Data, std::fstream& file_1, std::fstream& file_2);
void   available_date(m_date& items);
void read_data_file(std::fstream& file_1,m_date& items);
#endif