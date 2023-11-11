#include "./PmergeMe.hpp"

int find_max(std::vector<int> vc, int start,  int end)
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

void swap_pair(std::vector<int>& vc, int index,  int end)
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

void sort_pair(std::vector<int>& vc, int start, int end)
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

int jacobsthal(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void  build_jacob_insertion_sequence(std::vector<int>& pend, std::vector<int>& jacob_insertion_sequence)
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

int binary_search(const std::vector<int>& S, int key, int low, int high)
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

void inseting_to_S(std::vector<int>&S, std::vector<int> &vc)
{
    std::vector<int> pend;
    std::vector<int>::iterator it;
    std::vector<int> jacob_insertion_sequence;
    std::vector<int> final_index;
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

    //S vector
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
    std::vector<int>::iterator it1;
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

void sort_vector(std::vector<int>& vc)
{
    unsigned int i = 0;
    int straggler = -1;
    std::vector<int> S;
    if(vc.size() % 2)
    {
        straggler = vc[vc.size() - 1];
        vc.erase(vc.end() - 1); 
    }
    while(i < vc.size())
    {
        insetSort(vc, i , i + 1);
        i = i + 2;
    }
    sort_pair(vc, 0, (vc.size() - 2));
    sort_pair(vc, 0, (vc.size() - 2));
    inseting_to_S(S, vc);
    if(straggler != -1)
        vc.insert((vc.begin() + binary_search(vc, straggler, 0 , vc.size())), straggler); 
}

void sort_vector(std::deque<int>& vc)
{
    unsigned int i = 0;
    int straggler = -1;
    std::deque<int> S;
    if(vc.size() % 2)
    {
        straggler = vc[vc.size() - 1];
        vc.erase(vc.end() - 1); 
    }
    while(i < vc.size())
    {
        insetSort(vc, i , i + 1);
        i = i + 2;
    }
    sort_pair(vc, 0, (vc.size() - 2));
    sort_pair(vc, 0, (vc.size() - 2));
    inseting_to_S(S, vc);
    if(straggler != -1)
        vc.insert((vc.begin() + binary_search(vc, straggler, 0 , vc.size())), straggler); 
}

int main(int ac, char **av)
{
    mergeItems Items;
    double time_before_loop_end = 0;
    double time_before_loop_begins = 0;
    timeval currentTime;
    if(ac < 2)
        return 0;


    fullCnt(Items.cnt1, ac, av , 1);
    // fullCnt(Items.cnt2, ac, av , 1);

    printfContainer(Items.cnt1, "Before: ");

    
    gettimeofday(&currentTime, 0);
    time_before_loop_begins = currentTime.tv_sec * 1000000 + currentTime.tv_usec;
      sort_vector(Items.cnt1);
    // mergeSort(Items.cnt2, 0, Items.cnt2.size());
    gettimeofday(&currentTime, 0);
    time_before_loop_end = currentTime.tv_sec * 1000000 + currentTime.tv_usec;
    Items.time_sort_deque = time_before_loop_end - time_before_loop_begins;

    gettimeofday(&currentTime, 0);
    time_before_loop_begins = currentTime.tv_sec * 1000000 + currentTime.tv_usec;
    sort_vector(Items.cnt2);
    // mergeSort(Items.cnt1, 0, Items.cnt1.size());
    gettimeofday(&currentTime, 0);
    time_before_loop_end = currentTime.tv_sec * 1000000 + currentTime.tv_usec;
    Items.time_sort_vector = time_before_loop_end - time_before_loop_begins;


    printfContainer(Items.cnt1, "After: ");
    printfContainer(Items.cnt1, "After: ");
    std::cout << "Time to process a range of " << Items.cnt1.size() << " elements with std::vector "  << Items.time_sort_vector << " us" <<  std::endl;
    std::cout << "Time to process a range of " << Items.cnt2.size() << " elements with std::deque " << Items.time_sort_deque <<  " us"  << std::endl;
}