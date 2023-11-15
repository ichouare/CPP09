#include "./PmergeMe.hpp"
#include "PmergeMe.hpp"



int is_disgit(std::string str)
{
    unsigned  i = 0;
    while(i < str.size())
    {
        if(isdigit(str[i]) == 0)
            return 1;
        i++;
    }
    return 0;
}





int jacobsthal(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return jacobsthal(n - 1) +( 2 * jacobsthal(n - 2));
}



void sort_deque_pairs(std::deque<int> & vc , std::deque<int> & S, std::deque<int> & pend)
{
    std::deque<std::pair<int, int> > tmp;
    unsigned int  i = 0;
    while(i < vc.size())
    {
        tmp.push_back(std::pair<int, int>(vc[i],  vc[i + 1]));
        i+=2;
    }
    i = 0;
    while(i < tmp.size())
    {
        if(tmp[i].first < tmp[i].second)
            std::swap(tmp[i].first, tmp[i].second);
        i++;
    }
    sort_pairs(tmp, 0, tmp.size());
    i = 0;
    while(i < tmp.size())
    {
        S.push_back(tmp[i].first);
        pend.push_back(tmp[i].second);
        i++;
    }
}



