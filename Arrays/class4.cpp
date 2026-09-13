#include <iostream>
#include <vector>
using namespace std;

// in this class, we are studying MAXIMUM SUBARRAY SUM - which needs us to find all the possible subarrays in
// an array and then find the sum of each array and then check which subarr has the max/highest value of sum
// we can solve this using bruteforce by using 3-for loops, one for each starting point i.e. each starting index
// second one for getting each subarray using end value, and the last one for each value inside every subarray
// using the starting and ending point, but this method has a time complexity of O(n^3), that is not optimal
// anyway lets first try the brute force then we'll eliminate the redundancy for optimal solution.

void bruteSubarrFind(int arr[], int size) {
    // this fxn will print all the subarrays possible

    // this loop will give every subarray possible for each starting point
    for (int str = 0; str < size; str++) {
        // this loop will give each subarray
        for (int end = str; end < size; end++) {
            // this loop will print/give each value inside the subarray
            for (int i = str; i <= end; i++) {
                cout << arr[i];
            }
            cout << " "; // spaces between each subarray
        }
        cout << endl; // next line for each starting point
    }
}

void bruteSubarrSum(int arr[], int size) {
    // this fxn will reduce the complexity of previous brute force and will also find the max sum
    int maxSum = INT_MIN; // obv to "start" comparing the values, we need lowest number possible

    // this loop will calculate every subarray possible for each starting point
    for (int str = 0; str < size; str++) {
        int currSum = 0; // this variable stores the value of sums at each level (subarrays of common starting point)

        // this loop will calculate each subarray
        for (int end = str; end < size; end++) {
            currSum += arr[end];
            maxSum = max(currSum, maxSum);
        }
    }
    cout << "The max sum of subarray (using brute force) is - " << maxSum << endl;
}

// now to reduce the time complexity furthermore, we can use KADANE's algorithm which works on the intuition
// that we can simply ignore the negative sum of the subarrays, so that the possibilities where even negative sums
// were being calculated are now removed, because the negative sum will afterall reduce the maxSum value,
// thus we just need to reset the currSum to 0 in case currSum becomes negative i.e. currSum<0,
// also this currSum<0 check is done after setting the maxSum, cuz in an edge case, if the array/vector has all negative
// numbers then we know that maxSum is going to be a negative number but if we keep resetting currSum to 0, then
// then the maxSum will always be 0 itself cuz of the fact that 0 is larger than all negative numbers.
// this is how we achieve the most optimal - Linear O(n) time complexity with a single foreach loop being used.
void kadaneMaxSum(vector<int> nums) {
    int maxSum = INT_MIN;
    int currSum = 0;
    for (int num : nums) {
        currSum += num;
        maxSum = max(currSum, maxSum);

        if (currSum < 0) {
            currSum = 0;
        }
    }
    cout << "The max subarray sum (using KADANE's algo) is - " << maxSum << endl;
}

int main() {
    int size = 5;
    int arr[size] = {1, 2, 3, 4, 5};
    vector<int> nums = {3, -4, 5, 4, -1, 7, 6, -8};

    bruteSubarrFind(arr, size); // time-complexity - O(n^3)
    bruteSubarrSum(arr, size);  // time-complexity - O(n^2)
    kadaneMaxSum(nums);         // time-complexity - O(n) - most optimal - Linear
}