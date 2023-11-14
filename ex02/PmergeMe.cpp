#include "./PmergeMe.hpp"
#include "PmergeMe.hpp"

// void insetSort(std::vector<int>& arr, int begin, int end)
// {
//     int i = begin;
//     int j = 0;
//     while(i <= end)
//     {
//         int key = arr[i];
//         int tmp = 0;
//         j = i - 1;
//         while(j >= begin)
//         {
//             if(arr[j] < key)
//             {
//                 tmp = arr[j + 1];
//                 arr[j + 1] = arr[j];
//                 arr[j] = tmp;
//             }
//             j--;
//         }
        
//         i++;
//     }
// }

// template <typename T> 
// void printfContainer(T arr, std::string msg)
// {
//     unsigned  i = 0;
//     std::cout << std::setw(10) << msg ;
//     while(i < arr.size())
//     {
//         std::cout << arr[i] << " ";
//         i++;
//     }
//     std::cout << std::endl;
// }

// void printfContainer(std::deque<int> arr, std::string msg)
// {
//     unsigned i = 0;
//     std::cout << std::setw(10) << msg ;
//     while(i < arr.size())
//     {
//         std::cout << arr[i] << " ";
//         i++;
//     }
//     std::cout << std::endl;
// }


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



// int find_max(std::deque<int> vc, int start,  int end)
// {
    
//    int maxIndex = start;
//     while(maxIndex < end)
//    {
//         if(vc[end] > vc[maxIndex])
//         {
//             return maxIndex;
//         }
//         maxIndex +=2;
//    }
//     return -1;
// }






// void  build_jacob_insertion_sequence(std::deque<int>& pend, std::deque<int>& jacob_insertion_sequence)
// {
//     jacob_insertion_sequence.resize(pend.size() + 1);
//     int array_len = pend.size();
//     int jacob_index = 0; // The first one that matters
//     while(jacob_index < array_len)
//     {
//         jacob_insertion_sequence.push_back(jacobsthal(jacob_index));
//         jacob_index += 1;
//     }
// }

// template<typename T>
// int binary_search(T& S, int key, int low, int high)
// {
//      while (low <= high) {
//         int mid = low + (high - low) / 2;

//         if (S[mid] == key) {
//             return mid; // Key already exists
//         } else if (S[mid] < key) {
//             low = mid + 1;
//         } else {
//             high = mid - 1;
//         }
//     }
//     return low; 
// }
// template <typename T> 
// void inseting_to_S(T &vc, T &S, T &pend)
// {
//     // typedef typename T::iterator it;
//     T jacob_insertion_sequence;
//     T final_index;
//     unsigned int i = 0;
//     int  j = 0;
//     int y = 0;
//     i = 0;
//     unsigned int  k = 3;
//     while( i < pend.size())
//     {    
//             final_index.push_back(jacobsthal(k));
//             j = final_index[i];
//             while(j >  2)
//             {
//                 j--;
//                 if( (i != 0 && j  == final_index[i - 1] + 1 )|| final_index.size() == pend.size())
//                     break;
//                final_index.push_back(j);
//                y++;
//             }
//     i += y;
//     i++;
//     k++;
//     }
//     i = 0;
//     while(i < final_index.size())
//     {
//         std::cout <<  final_index[i] << ",";
//         i++;
//     }
//     i = 0;
//     while(i < final_index.size())
//     {
//         S.insert((S.begin() + binary_search(S, pend[final_index[i] - 1], 0 , S.size())), pend[final_index[i] - 1]);
//         i++;
//     }
//     vc = S;
// }


// int find_max(std::vector<int> vc, int start,  int end)
// {
    
//    int maxIndex = start;
//     while(maxIndex < end)
//    {
//     if(vc[end] < vc[maxIndex])
//     {
//         return maxIndex;
//     }
//     maxIndex +=2;
//    }
//     return -1;
// }

// void swap_pair(std::vector<int>& vc, int index,  int end)
// {
//     if(index != -1)
//     {
//         vc.insert(vc.begin() + index, vc[end]);
//         vc.erase(vc.begin() + end + 1);
//         vc.insert(vc.begin() + index + 1 , vc[end + 1]);
//         vc.erase(vc.begin() + end + 2);
        
//     }
// }

// void sort_pair(std::vector<int>& vc, int start, int end)
// {
//     unsigned int i = 0 ;
//     while(i < (vc.size() / 2))
//     {
//         int maxIndex = find_max(vc, start , end);
//         swap_pair(vc, maxIndex, end);
//         end -= 2;
//         i++;        
//     }
// }

int jacobsthal(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return jacobsthal(n - 1) +( 2 * jacobsthal(n - 2));
}

// template <typename T> 
// void  build_jacob_insertion_sequence(std::vector<int>& pend, std::vector<int>& jacob_insertion_sequence)
// {
//     jacob_insertion_sequence.resize(pend.size() + 1);
//     int array_len = pend.size();
//     int jacob_index = 0; // The first one that matters
//     while(jacob_index < array_len)
//     {
//         jacob_insertion_sequence.push_back(jacobsthal(jacob_index));
//         jacob_index += 1;
//     }
// }

// template <typename T> 
// int binary_search(T& S, int key, int low, int high)
// {
//      while (low <= high) {
//         int mid = low + (high - low) / 2;

//         if (S[mid] == key) {
//             return mid; // Key already exists
//         } else if (S[mid] < key) {
//             low = mid + 1;
//         } else {
//             high = mid - 1;
//         }
//     }
//     return low; 
// }

// void inseting_to_S(std::vector<int>&S, std::vector<int> &vc)
// {
//     std::vector<int> pend;
//     std::vector<int>::iterator it;
//     std::vector<int> jacob_insertion_sequence;
//     std::vector<int> final_index;
//     unsigned int i = 0;
//     int  j = 0;
//     std::vector<int>::iterator it1;

//     it = vc.begin();
//     while(it != vc.end())
//     {
//         S.push_back(*it);
//         pend.push_back(*(it + 1));
//         it+=2;

//     }
//     build_jacob_insertion_sequence(pend, jacob_insertion_sequence);
//     i = 1;
//     while(i <= pend.size())
//     {
//        if(jacob_insertion_sequence[i])
//         {
//             final_index.push_back(jacob_insertion_sequence[i]);
//             j = jacob_insertion_sequence[i];
//             while(j > jacob_insertion_sequence[i - 1] + 1)
//             {
//                 if(final_index.size() == pend.size() + 1)
//                     break;
//                 j--;
//                 final_index.push_back(j);
//             }
//         }
//         else
//              final_index.push_back(i);
//         i++;
//     }
//     it = final_index.begin();
//     i = 0;
//     while(i < final_index.size())
//     {
//         S.insert((S.begin() + binary_search(S, pend[final_index[i] - 1], 0 , S.size())), pend[final_index[i] - 1]);
//         i++;
//         it1++;
//     }
//     vc = S;
// }


// void sort_vector(std::vector<int>& vc)
// {
//     unsigned int i = 0;
//     int straggler = -1;
//     std::vector<int> S;
//     if(vc.size() % 2)
//     {
//         straggler = vc[vc.size() - 1];
//         vc.erase(vc.end() - 1); 
//     }
//     while(i < vc.size())
//     {
//         insetSort(vc, i , i + 1);
//         i = i + 2;
//     }
//     sort_pair(vc, 0, (vc.size() - 2));
//     sort_pair(vc, 0, (vc.size() - 2));
//     inseting_to_S(S, vc);
//     if(straggler != -1)
//         vc.insert((vc.begin() + binary_search(vc, straggler, 0 , vc.size())), straggler); 
// }

// template <typename T> 
// void insetSort(T& tmp, int begin, int end)
// {
//     int i = begin;
//     int j = 0;
//     while(i < end)
//     {
//         std::pair<int, int> key = tmp[i];
//         int value = 0;
//         j = i - 1;
//         while(j >= 0)
//         {
//             if(tmp[j].first > key.first)
//             {
                
//                 value = tmp[j + 1].first;
//                 tmp[j + 1].first =  tmp[j].first;
//                 tmp[j].first = value;
//                 value = tmp[j + 1].second;
//                 tmp[j + 1].second =  tmp[j].second;
//                 tmp[j].second = value;
//             }
//             j--;
//         }
        
//         i++;
//     }
// }

// template <typename T> 
// void  sort_pairs(T& tmp,  int start, int end)
// {
//      if(start < end)
//     {
//         int middle =  (start + end) / 2;
//         sort_pairs(tmp, start, middle);
//         sort_pairs(tmp, middle + 1, end);
//         insetSort(tmp, start, end);
//     }
// }

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
    S.insert(S.begin(), pend[0]);
}


