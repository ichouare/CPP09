#ifndef MERGE_H
#define MERGE_H


#include <iostream>
#include <vector>
#include <list>
#include <stdlib.h>
 #include <stdlib.h>
#include <cstring>
#include <iomanip>
 #include<ctime>
 #include <sys/time.h>


struct mergeItems
{
    std::vector<int> cnt1;    
    std::list<int>  cnt2;
    double  time_sort_vector;
    double time_sort_list;
};

void insetSort(std::vector<int>& arr, int begin, int end);
void insetSort(std::list<int>& arr, int begin, int end);
void mergeSort(std::vector<int>& arr, int begin, int end);
void mergeSort(std::list<int>& arr, int begin, int end);
void printfContainer(std::vector<int> arr, std::string msg);
void printfContainer(std::list<int> arr, std::string msg);
int is_disgit(std::string str);
template <typename T>
void fullCnt(T& cnt,int ac, char** nbrs, int i)
{
    int j = 0;
    while(i <  ac)
    {
        cnt.push_back(atoi(nbrs[i]));
        if(atoi(nbrs[i]) < 0 || strlen(nbrs[i]) == 0 || is_disgit(nbrs[i]) == 1) 
            {
                std::cout << "Error" << std::endl;
                exit(0);
            }
        i++;
        j++;
    }
}

#endif