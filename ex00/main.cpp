#include "./BitcoinExchange.hpp"
int main(int ac, char **ar)
{
    if(ac != 2)
        return (0);
    Btc("data.csv", ar[1]);
    // (void)ar;
    // std::string str = "             value         :      ";
    // str = trim(str);
    // std::cout << "|" << trim(str) << "|" << std::endl;
    return 0;
}