#include "./PmergeMe.hpp"

void insetSort(std::vector<int>& arr, int begin, int end)
{
    int i = begin;
    int j = 0;
    while(i <= end)
    {
        int key = arr[i];
        int tmp = 0;
        j = i - 1;
        while(j >= begin)
        {
            if(arr[j] < key)
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
    int i = begin;
    int j = 0;
    while(i < end)
    {
        int key = arr[i];
        int tmp = 0;
        j = i - 1;
        while(j > begin)
        {
            if(arr[j] < key)
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
    unsigned  i = 0;
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
    unsigned i = 0;
    std::cout << std::setw(10) << msg ;
    while(i < arr.size())
    {
        std::cout << arr[i] << " ";
        i++;
    }
    std::cout << std::endl;
}


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



int find_max(std::deque<int> vc, int start,  int end)
{
    
   int maxIndex = start;
    while(maxIndex < end)
   {
    if(vc[end] < vc[maxIndex])
    {
        return maxIndex;
    }
    maxIndex +=2;
   }
    return -1;
}


void swap_pair(std::deque<int>& vc, int index,  int end)
{
    // int tmp = 0;
    if(index != -1)
    {
        // tmp = vc[end];
        // vc[end] = vc[index];
        // vc[index] = tmp;
        // tmp = vc[end + 1];
        // vc[end + 1] = vc[index + 1];
        // vc[index + 1] = tmp;
        vc.insert(vc.begin() + index, vc[end]);
        vc.erase(vc.begin() + end + 1);
        vc.insert(vc.begin() + index + 1 , vc[end + 1]);
        vc.erase(vc.begin() + end + 2);
        
    }
}

void sort_pair(std::deque<int>& vc, int start, int end)
{
    unsigned int i = 0 ;
    while(i < (vc.size() / 2))
    {
        int maxIndex = find_max(vc, start , end);
        // std::cout << maxIndex << " " << vc[maxIndex] << std::endl;
        swap_pair(vc, maxIndex, end);
        end -= 2;
        i++;
        // sort_pair(vc, start, (end - 2));
        
    }
}

void  build_jacob_insertion_sequence(std::deque<int>& pend, std::deque<int>& jacob_insertion_sequence)
{
    jacob_insertion_sequence.resize(pend.size() + 1);
    int array_len = pend.size();
    int jacob_index = 0; // The first one that matters
    while(jacob_index < array_len)
    {
        jacob_insertion_sequence.push_back(jacobsthal(jacob_index));
        jacob_index += 1;
    }
}


int binary_search(const std::deque<int>& S, int key, int low, int high)
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

void inseting_to_S(std::deque<int>&S, std::deque<int> &vc)
{
    std::deque<int> pend;
    std::deque<int>::iterator it;
    std::deque<int> jacob_insertion_sequence;
    std::deque<int> final_index;
    unsigned int i = 0;
    it = vc.begin();
    while(it != vc.end())
    {
        S.push_back(*it);
        pend.push_back(*(it + 1));
        it+=2;

    }
    // Insert the first element in S -- we know it's the smallest, since it
   // was already sorted smaller in the first pairing
    // S.insert(S.begin() ,pend[0]);
    //  # build the valid jacobsthal sequence, then we can fill in the rest
    build_jacob_insertion_sequence(pend, jacob_insertion_sequence);

    i = 1;
    int j = 0;
    while(i <= pend.size())
    {
       if(jacob_insertion_sequence[i])
        {
            final_index.push_back(jacob_insertion_sequence[i]);
            j = jacob_insertion_sequence[i];
            while(j > jacob_insertion_sequence[i - 1] + 1)
            {
                if(final_index.size() == pend.size() + 1)
                    break;
                j--;
                final_index.push_back(j);
            }
            std::cout << "----" << std::endl;
        }
        else
             final_index.push_back(i);
        i++;
    }

    //S deque
    std::cout << " S : ==========" << std::endl;
    it = S.begin();
    while(it != S.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
    std::cout << " Pend ==========" << std::endl;
    it = pend.begin();
    while(it != pend.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
    std::cout << " final_index ==========" << std::endl;
    it = final_index.begin();
    while(it != final_index.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;

    it = final_index.begin();
    std::deque<int>::iterator it1;
    // it1 = final_index.begin();
     i = 0;
    while(i < final_index.size())
    {
       
        std::cout << pend[final_index[i] - 1] << std::endl;
        // std::cout << "pend : => " <<binary_search(S, pend[*it], 0 , S.size()) << std::endl;
        S.insert((S.begin() + binary_search(S, pend[final_index[i] - 1], 0 , S.size())), pend[final_index[i] - 1]);
        i++;
        it1++;
    }
    vc = S;
}