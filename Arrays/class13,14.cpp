#include <iostream>
#include <vector>
using namespace std;

// peak index in mountain array - optimal binary search - O(log n)
int peakMount(vector<int> mountArr) {
    int start = 1, end = mountArr.size() - 2;
    // here the init of start and end is not from 0 to n-1 just to avoid unnecessary search
    // space and also whenever we init with 1 to n-2 we do checks using if-else just to make
    // sure the first and last idx doesnt get ignored, but here the mathematical rules of the
    // mountain array simply make sure that the peak can neither be at start nor be at end
    // therefore we can simply start from idx = 1 and end at idx = n-2

    // usual binary search loop
    while (start <= end) {
        int mid = start + (end - start) / 2;

        // if the peak is already at mid we return the idx
        if (mountArr[mid - 1] < mountArr[mid] && mountArr[mid] > mountArr[mid + 1])
            return mid;

        // else we check if the "mid" lies in the left-half(increasing) or the right-half(decreasing)
        // if the mid is in left then the peak will be in right and vice-versa and wherever mid is we change the start
        // or end accordingly to reach the peak that would satisfy the above condition and return mid itself
        if (mountArr[mid - 1] < mountArr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1; // this return statement is unnecessary cuz the mount array will always have a peak
}

// single number in sorted array - where every element repeats twice but there's a single number among them
// using binary search - O(log n)
int singleNum(vector<int> numArr) {
    int n = numArr.size();
    // first check if the array has size > 1
    if (n == 1)
        return numArr[0];

    // the binary search loop
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        // edge case checks
        if (mid == 0 && numArr[0] != numArr[1])
            return numArr[mid];
        if (mid == n - 1 && numArr[n - 1] != numArr[n - 2])
            return numArr[mid];

        // now to check if the mid is single number or not
        if (numArr[mid - 1] != numArr[mid] && numArr[mid] != numArr[mid + 1])
            return numArr[mid];

        // check if the left and right halves are even or odd
        if (mid % 2 == 0) { // even
            if (numArr[mid - 1] == numArr[mid])
                end = mid - 1;
            else
                start = mid + 1;
        } else {
            if (numArr[mid - 1] == numArr[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1; // in case input is not correct i.e. no single number ever existed
}

int main() {
    vector<int> mountainArr = {0, 3, 8, 9, 5, 2};
    vector<int> numArr = {1, 1, 2, 3, 3, 4, 4};

    // results of peak idx of mount array
    cout << "the peak element is at arr[" << peakMount(mountainArr) << "]" << endl;

    // results of single number in sorted array
    cout << "the single number in sorted array is - " << singleNum(numArr) << endl;
}