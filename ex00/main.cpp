#include "./BitcoinExchange.hpp"
int main( int ac, char **ar)
{
    if(ac != 2)
        return (0);
    Btc Myckecker("data.csv", ar[1]);
    
}