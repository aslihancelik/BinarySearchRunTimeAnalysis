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
    std::vector<int> vec = { 1, 6, 3, 4, 5, 2, 7, 8, 9, 10 };
    int target = 6;

    // Sort the vector for binary search
    sort(vec.begin(), vec.end());

    // Display vector contents
    cout << "Contents of vector: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;


    int result = recursiveBinarySearch(vec, 0, vec.size() - 1, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    }
    else {
        cout << "Element not found." << endl;
    }

    target = 5;
    result = iterativeBinarySearch(vec, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    }
    else {
        cout << "Element not found." << endl;
    }

    target = 7;
    result = sequentialSearch(vec, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    }
    else {
        cout << "Element not found." << endl;
    }

    return 0;
}