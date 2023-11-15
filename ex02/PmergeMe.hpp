#ifndef MERGE_H
#define MERGE_H


#include <iostream>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <cstring>
#include <iomanip>
 #include<ctime>
 #include <sys/time.h>
 #include <algorithm> 


struct mergeItems
{
    std::vector<int> cnt1;    
    std::deque<int>  cnt2;
    double  time_sort_vector;
    double time_sort_deque;
};

int jacobsthal(int n);
int is_disgit(std::string str);
void sort_deque_pairs(std::deque<int> & vc , std::deque<int> & S, std::deque<int> & pend);
void sort_vector_pairs(std::vector<int> & vc , std::vector<int> & S, std::vector<int> & pend);

template <typename T>
void fullCnt(T& cnt,int ac, char** nbrs, int i)
{
    int j = 0;
    while(i <  ac)
    {
        cnt.push_back(atoi(nbrs[i]));
        if(cnt[j] < 0 || strlen(nbrs[i]) == 0 || is_disgit(nbrs[i]) == 1) 
            {
                std::cout << "Error" << std::endl;
                exit(0);
            }
        i++;
        j++;
    }
}

template <typename T> 
void printfContainer(T arr, std::string msg)
{
    unsigned  i = 0;
    std::cout << std::setw(10) << msg ;
    while(i < arr.size())
    {
        std::cout << arr[i] << " ";
        i++;
    }
    std::cout << std::endl;
}

template<typename T>
int binary_search(T& S, int key, int low, int high)
{
     while (low <= high) {
        int mid = low + (high - low) / 2;

        if (S[mid] == key) {
            return mid; // Key already exists
        } else if (S[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low; 
}

template <typename T> 
void inseting_to_S(T &vc, T &S, T &pend)
{
    T final_index;
    typename T::iterator it;
    unsigned int i = 0;
    int  j = 0;
    int index = 0;
    i = 0;
    unsigned int  k = 3;
    while( final_index.size() != pend.size())
    {    
            final_index.push_back(jacobsthal(k));
            j = final_index[final_index.size() - 1];
            while(j >  2)
            {
                j--;
                if( (i != 0 && j  == final_index[i - 1] + 1))
                    break;
                if(final_index.size() == pend.size())
                    break;
               final_index.push_back(j);
            }
    k++;
    }
    i = 0;
    unsigned int size = pend.size();
    while(i < size)
    {
        it = std::find(pend.begin(),pend.end(), pend[final_index[i] - 1]);
        if(it != pend.end())
        {
            S.insert((S.begin() + binary_search(S, *it, 0 , S.size())), *it);
            index = std::distance(pend.begin(), it);
            pend.erase(pend.begin() + index);
        }
        i++;
    }
    if(pend.size())
    {
        i  = 0;
        while(i <pend.size())
        {
            S.insert((S.begin() + binary_search(S, pend[i], 0 , S.size())), pend[i]);
            i++;
        }
    }    
    vc = S;
}



template <typename T> 
void insetSort(T& tmp, int begin, int end)
{
    int i = begin;
    int j = 0;
    while(i < end)
    {
        std::pair<int, int> key = tmp[i];
        int value = 0;
        j = i - 1;
        while(j >= 0)
        {
            if(tmp[j].first > key.first)
            {
                
                value = tmp[j + 1].first;
                tmp[j + 1].first =  tmp[j].first;
                tmp[j].first = value;
                value = tmp[j + 1].second;
                tmp[j + 1].second =  tmp[j].second;
                tmp[j].second = value;
            }
            j--;
        }
        
        i++;
    }
}

template <typename T> 
void  sort_pairs(T& tmp,  int start, int end)
{
     if(start < end)
    {
        int middle =  (start + end) / 2;
        sort_pairs(tmp, start, middle);
        sort_pairs(tmp, middle + 1, end);
        insetSort(tmp, start, end);
    }
}
template <typename T> 
void sort_cnt_pairs(T & vc , T & S, T & pend)
{
    std::vector<std::pair<int, int> > tmp;
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
template <typename T> 
void sort_cnt(T& vc)
{
    int straggler = -1;
    T S;
    T pend;
    if(vc.size() % 2)
    {
        straggler = vc[vc.size() - 1];
        vc.erase(vc.end() - 1); 
    }
    sort_cnt_pairs(vc, S, pend);
    inseting_to_S(vc, S, pend);
    if(straggler != -1)
        vc.insert((vc.begin() + binary_search(vc, straggler, 0 , vc.size())), straggler); 
}


// template <typename T> 
// void sort_cnt_pairs(T & vc , T & S, T & pend)
// {
//     std::vector<std::pair<int, int> > tmp;
//     unsigned int  i = 0;
//     while(i < vc.size())
//     {
//         tmp.push_back(std::pair<int, int>(vc[i],  vc[i + 1]));
//         i+=2;
//     }
//     i = 0;
//     while(i < tmp.size())
//     {
//         if(tmp[i].first < tmp[i].second)
//             std::swap(tmp[i].first, tmp[i].second);
//         i++;
//     }
//     sort_pairs(tmp, 0, tmp.size());
//     i = 0;
//     while(i < tmp.size())
//     {
//         S.push_back(tmp[i].first);
//         pend.push_back(tmp[i].second);
//         i++;
//     }
// }







#endif