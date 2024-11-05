// BinarySearchRunTimeAnalysis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Recursive Binary Search Function
int recursiveBinarySearch(const vector<int>& vec, int left, int right, int target) {
    if (left > right) {
        return -1;  // Target not found
    }
    int mid = left + (right - left) / 2;
    if (vec[mid] == target) {
        return mid;
    }
    else if (vec[mid] > target) {
        return recursiveBinarySearch(vec, left, mid - 1, target);
    }
    else {
        return recursiveBinarySearch(vec, mid + 1, right, target);
    }
}

// Iterative Binary Search Function
int iterativeBinarySearch(const vector<int>& vec, int target) {
    int left = 0;
    int right = vec.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] == target) {
            return mid;
        }
        else if (vec[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;  // Target not found
}

// Sequential Search Function
int sequentialSearch(const vector<int>& vec, int target) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == target) {
            return i;
        }
    }
    return -1;  // Target not found
}

int main() {

    srand(time(0));

    // Vector of test sizes
    vector<int> test_sizes = { 5000, 50000, 100000, 150000, 200000, 1000000 };

    // Loop through each test size
    for (int N : test_sizes) {
        double SumRBS = 0;   // Accumulator for Recursive Binary Search time
        double SumIBS = 0;   // Accumulator for Iterative Binary Search time
        double SumSeqS = 0;  // Accumulator for Sequential Search time

        // Run experiment 10 times for the current size of N
        for (int i = 0; i < 10; i++) {
            // Generate vector with N random numbers
            vector<int> vec(N);
            for (int j = 0; j < N; j++) {
                vec[j] = rand() % 100 + 1;
            }

            // Sort the vector for binary search
            sort(vec.begin(), vec.end());

            // Generate a random target value
            int target = rand() % 100 + 1;

            // Recursive Binary Search timing
            auto start = high_resolution_clock::now();
            recursiveBinarySearch(vec, 0, vec.size() - 1, target);
            auto end = high_resolution_clock::now();
            duration<double, micro> durationRBS = end - start;
            SumRBS += static_cast<double>(durationRBS.count());

            // Iterative Binary Search timing
            start = high_resolution_clock::now();
            iterativeBinarySearch(vec, target);
            end = high_resolution_clock::now();
            duration<double, micro> durationIBS = end - start;
            SumIBS += static_cast<double>(durationIBS.count());

            // Sequential Search timing
            start = high_resolution_clock::now();
            sequentialSearch(vec, target);
            end = high_resolution_clock::now();
            duration<double, micro> durationSeqS = end - start;
            SumSeqS += static_cast<double>(durationSeqS.count());
        }

        // Output average times
        cout << "For N = " << N << ":\n";
        cout << "Average Running Time for Recursive Binary Search in microseconds is " << SumRBS / 10 << endl;
        cout << "Average Running Time for Iterative Binary Search in microseconds is " << SumIBS / 10 << endl;
        cout << "Average Running Time for Sequential Search in microseconds is " << SumSeqS / 10 << endl;
        cout << "------------------------------------------------------\n";
    }

    return 0;
    

}