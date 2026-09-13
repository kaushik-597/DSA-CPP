#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// here we are solving PAIR SUM problem - return a pair from sorted array with a target sum , time complexity - O(n^2)
vector<int> pairsumbrute(vector<int> nums, int target) {
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }
    return ans;
};

// now we reduce the complexity to Linear - O(n) using a single loop and the fact that the array is "sorted".
vector<int> pairSumOptimal(vector<int> nums, int target) {
    vector<int> ans;
    int size = nums.size();
    int i = 0, j = size - 1;

    while (i < j) {
        int pairSum = nums[i] + nums[j];

        if (pairSum > target) {
            j--;
        } else if (pairSum < target) {
            i++;
        } else {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
    return ans;
}

// finding majority element with a sorting and foreach with complexity - O(n logn)
int majorElemTest(vector<int> elemVec) {
    sort(elemVec.begin(), elemVec.end());

    int freq = 1, size = elemVec.size(), ans = elemVec[0];

    // here i is set to 1 cuz ans already has the 0th index value of vector, so we start from 1st
    for (int i = 1; i < size; i++) {
        if (elemVec[i] == elemVec[i - 1]) {
            freq++;
        } else {
            freq = 1;
            ans = elemVec[i];
        }
        if (freq == size / 2) {
            return ans;
        }
    }
    return ans;
};

// now using MOORE's Voting Algorithm to solve major element problem in linear complexity - O(n)
// also we won't sort the array in this algo cuz thats what gonna reduce the complexity to linear and instead of
// resetting frequency to 0 we are going to decrement it whenever we encounter a different value than previous
// and it will still give us enough high frequency for the answer to be the majority number
int mooreMJ(vector<int> elemVec) {
    int size = elemVec.size();
    int freq = 0, ans = elemVec[0]; // we start with 0 freq cuz we'll count it in loop

    for (int i = 0; i < size; i++) {
        if (freq = 0) {
            ans = elemVec[i];
        }
        if (ans == elemVec[i]) {
            freq++;
        } else {
            freq--;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 26;
    vector<int> elemVec = {1, 2, 1, 2, 1, 1};

    // printing the results of brute force pair sum with complexity - O(n^2)
    vector<int> ans1 = pairsumbrute(nums, target);
    cout << "the pair(using brute force) is - " << ans1[0] << "," << ans1[1] << endl;

    // printing the results of two pointer approach - optimal solution pair sum with complexity - O(n)
    vector<int> ans2 = pairSumOptimal(nums, target);
    cout << "the pair (using optimal solution) is - " << ans2[0] << "," << ans2[1] << endl;

    // major element result from the test method with sorting and foreach
    cout << "The major element in element vector (using less optimal solution) is - " << majorElemTest(elemVec) << endl;

    // major element result from MOORE's Voting Algorithm
    cout << "The major element in element vector (using MOORE's Voting) is - " << mooreMJ(elemVec) << endl;
}