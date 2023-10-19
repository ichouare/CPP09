#ifndef MERGE_H
#define MERGE_H


#include <iostream>
#include <vector>
#include <deque>
#include <stdlib.h>


struct mergeItems
{
    std::vector<int> cnt1;    
    std::deque<int>  cnt2;
};

template <typename T>
void fullCnt(T& cnt,int ac, char** nbrs, int i)
{
    // std::cout << ac << std::endl;
    while(i <  ac)
    {
        cnt.push_back(atoi(nbrs[i]));
        std::cout << nbrs[i] << std::endl;
        i++;
    }
}

template <typename T, typename U>
void splitCnt(T& cnt,int ac, U nbrs, int i)
{
    // std::cout << ac << std::endl;
    while(i <  ac)
    {
        cnt.push_back(atoi(nbrs[i]));
        std::cout << nbrs[i] << std::endl;
        i++;
    }
}

template <typename T>
T mergesort(T cnt)
{
    T containeOne;
    T containeTwo;
    if(cnt.size() == 1)
        return cnt;
    splitCnt(containeOne, cnt.size() / 2, cnt, 0);
    splitCnt(containeTwo, cnt.size(), cnt,  cnt.size() / 2);
    int i = 0;
    while(i < containeOne.size())
    {
        std::cout << containeOne[i] << std::endl;
        i++;
    }
    std::cout << "--------------------------------"  << std::endl;
    i = 0;
    while(i < containeTwo.size())
    {
        std::cout << containeTwo[i] << std::endl;
        i++;
    }
    return containeOne;
}


#endif