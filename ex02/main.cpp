#include "./PmergeMe.hpp"

int main(int ac, char **av)
{
    mergeItems Items;
    fullCnt(Items.cnt1, ac, av , 1);
    fullCnt(Items.cnt2, ac, av , 1);
    mergesort(Items.cnt1);
//     int i = 0;
//     std::cout << "--------------------------------"  << std::endl;
//     // std::cout << Items.cnt1.size() << std::endl;
//     while(i < Items.cnt1.size())
//     {
//         std::cout << Items.cnt1[i] << std::endl;
//         i++;
//     }
//     std::cout << "--------------------------------"  << std::endl;
//     i = 0;
//     while(i < Items.cnt2.size())
//     {
//         std::cout << Items.cnt2[i] << std::endl;
//         i++;
//     }
}