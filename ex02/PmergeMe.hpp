#ifndef MERGE_H
#define MERGE_H


#include <iostream>
#include <vector>
#include <deque>
#include <stdlib.h>
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

void insetSort(std::vector<int>& arr, int begin, int end);
void insetSort(std::deque<int>& arr, int begin, int end);
// void mergeSort(std::vector<int>& arr, int begin, int end);
// void mergeSort(std::deque<int>& arr, int begin, int end);
void printfContainer(std::vector<int> arr, std::string msg);
void printfContainer(std::deque<int> arr, std::string msg);
int is_disgit(std::string str);
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
int find_max(std::deque<int> vc, int start,  int end);
int find_max(std::vector<int> vc, int start,  int end);
void swap_pair(std::vector<int>& vc, int index,  int end);
void sort_pair(std::vector<int>& vc, int start, int end);
void sort_pair(std::deque<int>& vc, int start, int end);
void  build_jacob_insertion_sequence(std::vector<int>& pend, std::vector<int>& jacob_insertion_sequence);
void  build_jacob_insertion_sequence(std::deque<int>& pend, std::deque<int>& jacob_insertion_sequence);
int binary_search(const std::vector<int>& S, int key, int low, int high);
int binary_search(const std::deque<int>& S, int key, int low, int high);
void inseting_to_S(std::vector<int>&S, std::vector<int> &vc);
void inseting_to_S(std::deque<int>&S, std::deque<int> &vc);
void sort_vector(std::vector<int>& vc);
void sort_vector(std::deque<int>& vc);
int jacobsthal(int n);







// void insetSort(std::deque<int>& arr, int begin , int end)
// {
//     int i = begin + 1;
//     int j = 0;
//     while(i <= end)
//     {
//         int key = arr[i];
//         j = i - 1;
//         while(j >= begin && arr[j] > key)
//         {
//             arr[j + 1] = arr[j];
//             j--;
//         }
//         i++;
//     }
// }
// template <typename T>
// T mergesort(T cnt)
// {

// }

// void mergeInsertSort(std::vector<int>& arr, int begin , int end)
// {
//     if(begin < end)
//     {
//         int middle = (end + begin) / 2;
//         mergeInsertSort(arr, begin, middle);
//         mergeInsertSort(arr, middle + 1, end);
//         //inser sort(arr)
//         insetSort(arr, begin, end);
//         // merge()
//     }

// }


#endif