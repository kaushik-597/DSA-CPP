#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> arr, int target) {
    int start = 0, end = arr.size() - 1;
    while (start <= end) {
        // int mid = (start + end) / 2; this formula might get the int to overflow with start and end both being INT_MAX
        // so we can use another formula to calculate the mid, the formula gives the exact value but it differs from the
        // memory allocation perspective
        int mid = start + (end - start) / 2;
        if (target < arr[mid]) {
            end = mid - 1;
        } else if (target > arr[mid]) {
            start = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

// recursion has a call stack, which leads to the space complexity of O(log n) but the time complexity is same as of
// iterative approach
int binSrchRecur(vector<int> arr, int target, int start, int end) {
    if (start <= end) {
        int mid = start + (end - start) / 2;
        if (target < arr[mid]) {
            return binSrchRecur(arr, target, start, mid - 1);
        } else if (target > arr[mid]) {
            return binSrchRecur(arr, target, mid + 1, end);
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {-1, 0, 4, 8, 9, 13, 19};
    int target = 13;
    cout << "output of binarySearch - O(logn) - arr[" << binarySearch(arr, target) << "]" << endl;

    int start = 0, end = arr.size() - 1;
    cout << "output of binarySearchRecursion - O(logn) - arr[" << binSrchRecur(arr, target, start, end) << "]" << endl;
}