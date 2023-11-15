#include "./BitcoinExchange.hpp"


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
   int count = 0;
    while(i < str.size())
    {
        if(cnt == 2 && (std::isdigit(str[i])  || str[i] == '\n' || str[i] == '-'))
            i++;
       else  if(std::isdigit(str[i]))
            i++;
        else if(i == 0 && cnt == 2 && str[i] == '+')
            i++;
        else if( i != 0 && i != str.size() - 1 && str[i] == '.')
        {
            i++;
            count++;
        }
        else{
            return -1;
        }
    }
    if(count > 1)
        return -1;
    return 0;
}

int check_date(m_date& m_d)
{
    int max_days_in_month[12]= {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i = 0;
    while(i < 3)
    {
        if(m_d.date[0] <  m_d.min_date[0]
            || (m_d.date[0] ==  m_d.min_date[0] && m_d.date[1] <=  m_d.min_date[1] && m_d.date[2] <  m_d.min_date[2]) 
            || m_d.date[1] <= 0 || m_d.date[1] > 12 || m_d.date[2] <= 0 || m_d.date[2] > max_days_in_month[m_d.date[1] - 1] )
            return (0);
        
        i++;
    }
    return 1;
}

int check_date_data(m_date m_d)
{
    int max_days_in_month[12]= {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i = 0;
    while(i < 3)
    {

        if(m_d.date[i] == 0 || m_d.date[1] <= 0 || m_d.date[1] > 12 || m_d.date[2] <= 0 || m_d.date[2] > max_days_in_month[m_d.date[1] - 1] )
            return (0);
        
        i++;
    }
    return 1;
}
int del_number(std::string key, char po)
{
    int count_comma = 0;
    int i = 0;
    while(key[i])
    {
        if(key[i] == po) 
            count_comma++;
        i++;
    }
    if(count_comma != 2)
        return -1;
    return 0;
}

int parser_date_data(std::string key)
{
    m_date Date;
    std::string date[5];
    if(del_number(key, '-') == -1)
        return 0;
    int i = 0;
    int pos = 0;
    while(key.size())
    {
        pos = key.find("-");
        if(pos != -1)
        {
            date[i] = key.substr(0, key.find("-")).data();
            key = key.substr(key.find("-") + 1 , key.size());
        }
        else
        {
            date[i] = key.data();
            // std::cout << key << std::endl;
            key = "";
        }
        i++;
    }
    // std::cout << key << std::endl;
    if(i != 3)
        return 0;
    i = 0;
    while(i < 3)
    {
        // std::cout <<  date[i] << std::endl;
        if(ft_isalpha(date[i], i) == -1)
            return 0;
        Date.date[i] = static_cast<float>(atof((date[i]).data()));
    i++;
    }
    if(check_date_data(Date) == 0)
        return 0;
    return 1;
}

int parser_date(std::string key, m_date& Date)
{
    std::string date[5];
    int i = 0;
    int pos = 0;
    if(del_number(key, '-') == -1)
        return 0;
    while(key.size())
    {
        pos = key.find("-");
        if(pos != -1)
        {
            date[i] = key.substr(0, key.find("-")).data();
            key = key.substr(key.find("-") + 1 , key.size());
        }
        else
        {
            date[i] = key.data();
            key = "";
        }
        i++;
    }
    if(i != 3)
        return 0;
    i = 0;
    while(i < 3)
    {
        if(ft_isalpha(date[i], i) == -1)
            return 0;
        Date.date[i] = static_cast<float>(atof((date[i]).data()));
    i++;
    }
    if(check_date(Date) == 0)
        return 0;
    return 1;
}

void check_files(std::string file_Input, std::string Data, std::fstream& file_1, std::fstream& file_2)
{
      file_1.open(file_Input.data(), std::ios::in);
      file_2.open(Data.data(), std::ios::in);
        if(!file_1.is_open() || !file_2.is_open())
            throw -1;
}

void   available_date(m_date& items)
{
    std::string date = items.price.begin()->first;
    int i = 0;
    int pos = 0;
    while (i < 3)
    {
        pos = (date).find("-");
        items.min_date[i] = atoi((date).substr(0, pos).data());
       ( date) = (date).substr(pos + 1, (date).size());
        i++;
    }
}

void read_data_file(std::fstream& file_1,m_date& items)
{
    int pos = -1;
    while(std::getline(file_1, items.line, '\n'))
    {
                pos = items.line.find(",");
                if(pos == -1)
                    throw -1;
                std::string key = items.line.substr(0,  pos);
                std::string value = items.line.substr(pos + 1, strlen(items.line.data()));
                key = trim(key);
                value = trim(value);
                if(key.empty() || value.empty() || (key != "date" && parser_date_data(key) == 0) || (value  != "exchange_rate" && ft_isalpha(value, 2) == -1) )
                    throw -1;
                items.price.insert(std::pair<std::string, float>(key, static_cast<float>(atof(value.data())))); // check insert fucntion if is avalible in c++98 
    }
    available_date(items);
    }

void Btc(std::string file_Input, std::string Data)
{
    m_date items;
    std::fstream file_1;
    std::fstream  file_2;
    try{
        check_files(file_Input, Data, file_1, file_2);
        read_data_file(file_1, items);
        if(items.price.empty())
            throw -1;
        while(std::getline(file_2, items.line, '\n'))
        {
            int pos = items.line.find("|");
            if((pos == -1 && items.line.size() != 0))
            {
                std::cout << "Error: bad input => " << items.line << std::endl;

            }
            else
            {
                std::string key = items.line.substr(0,  pos);
                std::string value = items.line.substr(pos + 1, strlen(items.line.data()));
                key = trim(key);
                value = trim(value);
                double number  = static_cast<float>(atof(value.data()));
                if((items.line.empty() == 0 &&  (value.empty() || key.empty())) ||  (ft_isalpha(value, 2) == -1 && trim(value) != "value"))
                    {
                        std::cout << "Error: bad input" << std::endl;
                    }
                else if(number > 1000)
                    std::cout << "Error: too large a number"  << std::endl;
                else if(number < 0)
                    std::cout << "Error: not a positive number"  << std::endl;
                else
                {
                   if(parser_date(key, items) != 0 )
                    {
                        items.it = items.price.find(key);
                        if(items.it == items.price.end())
                        {
                            items.it = items.price.lower_bound(key);
                            items.it--;
                            std::cout << key << " => " << value  << " = "  << std::setprecision(8) << (items.it->second * number) << std::endl; 
                        }
                        else
                        {
                            std::cout << key << " => " << value << " = " <<  std::setprecision(8) << (items.it->second * number) << std::endl; 
                        }
                   }
                    else  if(trim(key) != "date" && items.line.size())
                        std::cout << "Error: bad input"<< std::endl;
                }
            } 
        }
    }
    catch(...)
    {
        std::cout << "Error: bad files" << std::endl;
    }
}

