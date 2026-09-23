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

int main() {
    vector<int> mountainArr = {0, 3, 8, 9, 5, 2};

    // results of peak idx of mount array
    cout << "the peak element is at arr[" << peakMount(mountainArr) << "]" << endl;
}