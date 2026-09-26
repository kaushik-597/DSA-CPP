#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// sorting algorithms: Bubble, selection, insertion - O(n^2), rest optimal one's like merge, quick are O(nlogn)
// bubble sort

void bubbleSort(vector<int> &arr, int n) {
    bool isSwap = false;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if (!isSwap) {
            return;
        }
    }
}

// selection sort
void selectionSort(vector<int> &arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int smallestIdx = i; // unsorted part starting idx
        for (int j = i + 1; j < n; j++) {
            if (arr[smallestIdx] > arr[j]) {
                smallestIdx = j;
            }
        }
        swap(arr[i], arr[smallestIdx]);
    }
}

// insertion sort
void insertionSort(vector<int> &arr, int n) {
    for (int i = 1; i < n; i++) {
        int curr = arr[i], prev = i - 1;

        while (prev >= 0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}

void printArr(vector<int> arr) {
    for (int i : arr) {
        cout << i << ",";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {4, 1, 5, 2, 3};
    int n = arr.size();

    // bubbleSort(arr, n);
    // selectionSort(arr, n);
    insertionSort(arr, n);
    printArr(arr);

    return 0;
}