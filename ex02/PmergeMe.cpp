#include "./PmergeMe.hpp"

void insetSort(std::vector<int>& arr, int begin, int end)
{
    int i = begin;
    int j = 0;
    while(i < end)
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

void insetSort(std::list<int>& arr, int begin, int end)
{
    std::list<int>::iterator  it = std::next(arr.begin(), begin);
    int b = begin;
    while(b <  end)
    {       
        int key = *it;
        std::list<int>::iterator j = std::prev(it);
        int k = b - 1;
        while (k >= 0 && *j > key) {
            *(std::next(j)) = *j;
            --j;
            --k;
        }

        *(std::next(j)) = key;
    it++; 
    b++;
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

void mergeSort(std::list<int>& arr, int begin, int end)
{
    // std::cout << "Merging inside " << std::endl;`
    if(begin < end)
    {
        int middle =  (begin + end) / 2;
        mergeSort(arr, begin, middle);
        mergeSort(arr, middle + 1, end);
        insetSort(arr, begin, end);
    }
    return ;
}



void printfContainer(std::vector<int> arr, std::string msg)
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

void printfContainer(std::list<int> arr, std::string msg)
{
    std::list<int>::iterator  it  = arr.begin();
    std::cout <<  msg  << std::setw(5);
    while(it != arr.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}


int is_disgit(std::string str)
{
    unsigned  i = 0;
    while(i < str.size())
    {
        if(i == 0 && str[i] == '+')
            i++;
        else if(isdigit(str[i]) == 0)
            return 1;
        i++;
    }
    return 0;
}