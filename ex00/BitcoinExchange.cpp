#include "./BitcoinExchange.hpp"

// void count_separators(std::string str)
// {
//     int i = 0;

//     while()
// }


std::string trim(std::string original)
{
    unsigned int begin_index = 0;
    unsigned int i = 0;
    if(original.size() == 0)
        return "";
    while(isblank(original[i]) != 0 && i <= original.size())
    {
        begin_index++;
        i++;
    }
    i = original.size() - 1;
    while(isblank(original[i]) != 0 && i != 0)
        i--;
     if(begin_index == original.size())
        return "";
    return original.substr(begin_index, i + 1);
}

int ft_isalpha(std::string str , int cnt)
{
   unsigned int i = 0;
    while(i < str.size())
    {
        if(cnt == 2 && (std::isdigit(str[i]) || str[i] == 32 || str[i] == '\n'))
            i++;
       else  if(std::isdigit(str[i]))
            i++;
        else if( i != 0 && str[i] == '.')
            i++;
        else{
            // std::cout << "exit" << "|" << str[i] << cnt << "|" << std::endl;
            return -1;
        }
    }
    return 0;
}

int check_date(m_date m_d)
{
    int max_days_in_month[12]= {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i = 0;
    while(i < 3)
    {
        if(m_d.date[0] < 2009 
            || (m_d.date[0] == 2009 && m_d.date[1] == 1 && m_d.date[2] == 1) 
            || m_d.date[1] < 0 || m_d.date[1] > 12 || m_d.date[2] < 0 || m_d.date[2] > max_days_in_month[m_d.date[1]] )
            return (0);
        
        i++;
    }
    return 1;
}

int parser_date(std::string key)
{
    m_date Date;
    
    std::vector<std::string> date;
    std::vector<std::string>::iterator it;
    int i = 0;
    int pos = 0;
    while(key.size())
    {
        pos = key.find("-");
        if(pos != -1)
        {
            date.push_back(key.substr(0, key.find("-")).data());
            key = key.substr(key.find("-") + 1 , key.size());
        }
        else
        {
            date.push_back(key.data());
            key = "";
        }
        i++;
    }
    if(i != 3)
        return 0;
    it = date.begin();
    i = 0;
    while(it != date.end())
    {
        if(ft_isalpha(*it, i) == -1)
            return 0;
        Date.date[i] = static_cast<int>(atof((*it).data()));
    it++;
    i++;
    }
    if(check_date(Date) == 0)
        return 0;
    return 1;
}

// Btc::Btc(){}

void Btc(std::string file_Input, std::string Data)
{
    m_date items;
    std::fstream file_1;
    std::fstream  file_2;
    try{
      file_1.open(file_Input.data(), std::ios::in);
      file_2.open(Data.data(), std::ios::in);
        if(!file_1.is_open() || !file_2.is_open())
            throw -1;
        while(std::getline(file_1, items.line, '\n'))
        {
                std::string key = items.line.substr(0,  items.line.find(","));
                std::string value = items.line.substr(items.line.find(",") + 1, strlen(items.line.data()));
                items.price.insert(std::pair<std::string, double>(key, static_cast<double>(atof(value.data())))); // check insert fucntion if is avalible in c++98 
        }

        // int 
        while(std::getline(file_2, items.line, '\n'))
        {
            // items.line = trim(items.line);
                // std::cout <<"|" <<  items.line  << "|" << items.line.size()<< std::endl;
            int pos = items.line.find("|");
            if(pos == -1 && items.line.size() != 0)
            {
                std::cout << "Error: bad input =>" << std::endl;

            }
            else
            {
                std::string key = items.line.substr(0,  pos);
                std::string value = items.line.substr(pos + 1, strlen(items.line.data()));
                key = trim(key);
                value = trim(value);
                
                double number  = static_cast<double>(atof(value.data()));
                if(ft_isalpha(value, 2) == -1 && trim(value) != "value")
                    {
                        std::cout << "Error: bad input : " <<"|" <<  trim(value) << "|" << std::endl;
                    }
                else if(number > 1000)
                    std::cout << "Error: too large a number"  << std::endl;
                else if(number < 0)
                    std::cout << "Error: not a positive number"  << std::endl;
                else
                {
                    // std::cout << "key:   " << key  << "  "<<  "value :   " << value << std::endl;
                   
                   if(parser_date(key) != 0 )
                    {
                       
                        // std::cout  << key << std::endl;
                        items.it = items.price.find(key);
                        if(items.it == items.price.end())
                        {
                            items.it = items.price.lower_bound(key);
                            items.it--;
                            std::cout << key << " => " << number << " = " << (float)(items.it->second * number) << std::endl; 
                        }
                        else
                        {
                            std::cout << key << " => " << number << " = " << (float)(items.it->second * number) << std::endl; 
                        }
                   }
                    else  if(trim(key) != "date" && items.line.size())
                    {
                        // std::cout << "|" << key << "|" <<std::endl;
                        std::cout << "Error: bad input"<< std::endl;
                    }   
                }
            } 
        }
    }
    catch(...)
    {
        std::cout << "Error: bad input =>" << std::endl;
    }
}

