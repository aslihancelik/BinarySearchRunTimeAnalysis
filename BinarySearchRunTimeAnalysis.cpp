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

    // Step 1: Initialize random number generator
    srand(time(0));

    // Step 2: Fill vector with random numbers between 1 and 100
    vector<int> vec;
    for (int i = 0; i < 10; i++) {  // Small vector for test purposes
        vec.push_back(rand() % 100 + 1);
    }

    // Step 3: Sort the vector
    sort(vec.begin(), vec.end());

    // Step 4: Generate a random target
    int target = rand() % 100 + 1;

    // Step 5: Write contents of the vector
    cout << "Contents of vector: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;

    // Recursive Binary Search
    cout << "\n// Recursive Binary Search\n";
    int index = recursiveBinarySearch(vec, 0, vec.size() - 1, target);
    if (index != -1) {
        cout << "Target " << target << " found at location " << index << " using Recursive Binary Search.\n";
    }
    else {
        cout << "Target " << target << " was not found using Recursive Binary Search.\n";
    }

    // Iterative Binary Search
    cout << "\n// Iterative Binary Search\n";
    index = iterativeBinarySearch(vec, target);
    if (index != -1) {
        cout << "Target " << target << " found at location " << index << " using Iterative Binary Search.\n";
    }
    else {
        cout << "Target " << target << " was not found using Iterative Binary Search.\n";
    }

    // Sequential Search
    cout << "\n// Sequential Search\n";
    index = sequentialSearch(vec, target);
    if (index != -1) {
        cout << "Target " << target << " found at location " << index << " using Sequential Search.\n";
    }
    else {
        cout << "Target " << target << " was not found using Sequential Search.\n";
    }

    return 0;


}