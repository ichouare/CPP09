#include "./PmergeMe.hpp"


int main(int ac, char **av)
{
    mergeItems Items;
    double time_before_loop_end = 0;
    double time_before_loop_begins = 0;
    timeval currentTime;
    if(ac < 2)
        return 0;
    fullCnt(Items.cnt1, ac, av , 1);
    fullCnt(Items.cnt2, ac, av , 1);
    printfContainer(Items.cnt2, "Before: ");

    
    gettimeofday(&currentTime, 0);
    time_before_loop_begins = currentTime.tv_sec * 1000000 + currentTime.tv_usec;
      sort_cnt(Items.cnt1);
    gettimeofday(&currentTime, 0);
    time_before_loop_end = currentTime.tv_sec * 1000000 + currentTime.tv_usec;
    Items.time_sort_deque = time_before_loop_end - time_before_loop_begins;

    gettimeofday(&currentTime, 0);
    time_before_loop_begins = currentTime.tv_sec * 1000000 + currentTime.tv_usec;
    sort_cnt(Items.cnt2);
    gettimeofday(&currentTime, 0);
    time_before_loop_end = currentTime.tv_sec * 1000000 + currentTime.tv_usec;
    Items.time_sort_vector = time_before_loop_end - time_before_loop_begins;

    printfContainer(Items.cnt1, "After: ");
    std::cout << "Time to process a range of " << Items.cnt1.size() << " elements with std::vector "  << Items.time_sort_vector << " us" <<  std::endl;
    std::cout << "Time to process a range of " << Items.cnt2.size() << " elements with std::deque " << Items.time_sort_deque <<  " us"  << std::endl;
}