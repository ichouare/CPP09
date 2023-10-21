#include "./PmergeMe.hpp"



void insetSort(std::vector<int>& arr, int begin, int end)
{
    int i = 1;
    int j = 0;
    while(i <  arr.size())
    {
        int key = arr[i];
        int tmp = 0;
        j = i - 1;
        while(j >= 0)
        {
            if(arr[j] > key)
            {
                tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
            j--;
        }
        
        i++;
    }
}

void insetSort(std::deque<int>& arr, int begin, int end)
{
    int i = 1;
    int j = 0;
    while(i <  arr.size())
    {
        int key = arr[i];
        int tmp = 0;
        j = i - 1;
        while(j >= 0)
        {
            if(arr[j] > key)
            {
                tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
            j--;
        }
        
        i++;
    }
}

void mergeSort(std::vector<int>& arr, int begin, int end)
{
    if(begin < end)
    {
        int middle =  (begin + end) / 2;
        mergeSort(arr, begin, middle);
        mergeSort(arr, middle + 1, end);
        insetSort(arr, begin, end);
    }
}

void mergeSort(std::deque<int>& arr, int begin, int end)
{
    if(begin < end)
    {
        int middle =  (begin + end) / 2;
        mergeSort(arr, begin, middle);
        mergeSort(arr, middle + 1, end);
        insetSort(arr, begin, end);
    }
}


void printfContainer(std::vector<int> arr, std::string msg)
{
    int i = 0;
    std::cout << std::setw(10) << msg ;
    while(i < arr.size())
    {
        std::cout << arr[i] << " ";
        i++;
    }
    std::cout << std::endl;
}

void printfContainer(std::deque<int> arr, std::string msg)
{
    int i = 0;
    std::cout << std::setw(10) << msg ;
    while(i < arr.size())
    {
        std::cout << arr[i] << " ";
        i++;
    }
    std::cout << std::endl;
}


int main(int ac, char **av)
{
    mergeItems Items;
    fullCnt(Items.cnt1, ac, av , 1);
    fullCnt(Items.cnt2, ac, av , 1);
    // mergeSort(Items.cnt1);
    printfContainer(Items.cnt1, "Before: ");

    int time_before_loop_begins = time(NULL);
    mergeSort(Items.cnt1, 0, Items.cnt1.size());
    int time_before_loop_end = time(NULL);
      Items.time_sort_vector = time_before_loop_end - time_before_loop_begins;

    time_before_loop_begins = time(NULL);
    mergeSort(Items.cnt2, 0, Items.cnt2.size());
    time_before_loop_end = time(NULL);
    Items.time_sort_deque = time_before_loop_end - time_before_loop_begins; 

    printfContainer(Items.cnt1, "After: ");
    std::cout << "Time to process a range of" << Items.cnt1.size() << "elements with std::[..]" << Items.time_sort_vector << std::endl;
    std::cout << "Time to process a range of" << Items.cnt2.size() << "elements with std::[..]" << Items.time_sort_deque << std::endl;
    // std::cout << "--------------------------------"  << std::endl;
    // i = 0;
    // while(i < Items.cnt1.size())
    // {
    //     std::cout << Items.cnt1[i] << " ";
    //     i++;
    // }
}