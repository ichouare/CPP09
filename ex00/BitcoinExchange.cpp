#include "./BitcoinExchange.hpp"

int ft_isalpha(std::string str , int cnt)
{
    int i = 0;
    // std::cout << "|"<< str << "|"<< std::endl;
    while(i < str.size())
    {
        // check str if it just digit or not
        if(cnt == 2 && (std::isdigit(str[i]) || str[i] == 32 || str[i] == '\n'))
            i++;
       else  if(std::isdigit(str[i]))
            i++;
        else{
            std::cout << "exit" << "|" << str[i] << cnt << "|" << std::endl;
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
    //std::cout << key << std::endl;
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

Btc::Btc(){}

Btc::Btc(std::string file_Input, std::string Data)
{
    try{
        file_1.open(file_Input.data(), std::ios::in);
        file_2.open(Data.data(), std::ios::in);
        if(!file_1.is_open() || !file_2.is_open())
        {
            throw -1;
        }
        while(std::getline(file_1, line, '\n'))
        {
                std::string key = line.substr(0,  line.find(","));
                std::string value = line.substr(line.find(",") + 1, strlen(line.data()));
                if(key != "date")
                    price.insert(std::pair<std::string, double>(key, static_cast<double>(atof(value.data())))); // check insert fucntion if is avalible in c++98 
        }

        while(std::getline(file_2, line, '\n'))
        {
            //std::cout << line << std::endl;
            int pos = line.find("|");
            // std::cout << pos << std::endl;
            if(pos == -1)
                std::cout << "Error: bad input => " << line  << std::endl;
            else
            {
                std::string key = line.substr(0,  pos);
                std::string value = line.substr(pos + 1, strlen(line.data()));
                double number  = static_cast<double>(atof(value.data()));
                if(number > 1000)
                    std::cout << "Error: too large a number"  << std::endl;
                else if(number < 0)
                    std::cout << "Error: not a positive number"  << std::endl;
                else
                {
                   if( parser_date(key) != 0)
                   {
                        // std::cout << key << value << std::endl;
                        it=price.find(key);
                        // std::cout << it->second <<std::endl;
                        // std::cout << key << " => " << number << " = " << (it->second * number) << std::endl;
                        if(it == price.end())
                        {
                            it = price.lower_bound(key);
                            it--;
                             std::cout << key << " => " << number << " = " << (it->second * number) << std::endl;
                            // std::cout << "find more\n"; 
                        }
                   }
                    else  if(key != "date ")
                    {
                        std::cout << "Error: bad input =>" << line << std::endl;
                    }   
                }
                // parser_price(key);

            }
                //std::cout << value << key << std::endl;
                // if(key != "Date")
                //     Fetch.insert(std::pair<std::string, double>(key, static_cast<double>(atof(value.data())))); 
        }
        // std::cout << Fetch["2011-01-03"] << std::endl;
    }

    catch(...)
    {
        std::cout << "here" << std::endl;
    }
}

