#include "./PmergeMe.hpp"

int main(int ac, char **av)
{
    if(ac == 1)
        return 0;
    mergeItems Items;
    timeval endTime;
    timeval startTime;


    fullCnt(Items.cnt1, ac, av , 1);
    fullCnt(Items.cnt2, ac, av , 1);

    printfContainer(Items.cnt2, "Before: ");

    gettimeofday(&startTime, NULL);
    mergeSort(Items.cnt2, 0, Items.cnt2.size());
    gettimeofday(&endTime, NULL);
    Items.time_sort_list = (endTime.tv_sec - startTime.tv_sec) * 1000000.0 + (endTime.tv_usec - startTime.tv_usec);

    gettimeofday(&startTime, 0);
    mergeSort(Items.cnt1, 0, Items.cnt1.size());
    gettimeofday(&endTime, 0);
    Items.time_sort_vector = (endTime.tv_sec - startTime.tv_sec) * 1000000.0 + (endTime.tv_usec - startTime.tv_usec);


    printfContainer(Items.cnt2, "After: ");
    std::cout << "Time to process a range of " << Items.cnt1.size() << " elements with std::vector " << std::fixed  << Items.time_sort_vector << " us" <<  std::endl;
    std::cout << "Time to process a range of " << Items.cnt2.size() << " elements with std::list "  << Items.time_sort_list <<  " us"  << std::endl;
}