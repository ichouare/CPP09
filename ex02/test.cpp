#include <iostream>
#include <vector>

// Binary search to find the correct position for insertion
int binarySearch(const std::vector<long long>& S, long long key, int low, int high) {
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
    return low; // Key not found, return the position for insertion
}

// Function to insert elements from 'pend' into 'S' using binary search
void insertIntoS(const std::vector<long long>& pend, std::vector<long long>& S) {
    for (long long element : pend) {
        // Use binary search to find the correct position for insertion
        int position = binarySearch(S, element, 0, S.size() - 1);

        // Insert the element into the correct position in 'S'
        S.insert(S.begin() + position, element);
    }
}

// Function to print the elements of a vector
void printVector(const std::vector<long long>& vec) {
    for (long long num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Example: Using the optimal insertion sequence from the previous step
    std::vector<long long> pend = {5, 3, 8, 2, 7};
    std::vector<long long> S; // Assume 'S' is initially empty

    std::cout << "Original 'pend': ";
    printVector(pend);

    buildOptimalInsertionSequence(pend.size()); // Reusing the previous function to build the optimal insertion sequence

    insertIntoS(pend, S);

    std::cout << "Sorted 'S' after inserting 'pend' elements: ";
    printVector(S);

    return 0;
}
