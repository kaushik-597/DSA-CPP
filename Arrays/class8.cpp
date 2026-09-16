#include <iostream>
#include <vector>
using namespace std;

// container with max water problem - brute force but this will give TLE error which is due to its O(n^2) complexity
// with 10^10 operations which is greater than 10^8 operations
int maxWaterBrute(vector<int> containers) {
    int maxWater = 0;

    for (int i = 0; i < containers.size() - 1; i++) {
        for (int j = i + 1; j < containers.size(); j++) {
            int width = j - i;
            int height = min(containers[i], containers[j]);
            int area = width * height;
            maxWater = max(maxWater, area);
        }
    }
    return maxWater;
}

// thus to solve it optimally we use two pointer approach and get O(n) complexity
int maxWaterOpt(vector<int> containers) {
    int maxWater = 0;
    int left = 0, right = containers.size() - 1;

    while (left < right) {
        int width = right - left;
        int height = min(containers[left], containers[right]);
        int area = width * height;
        maxWater = max(maxWater, area);
        containers[left] < containers[right] ? left++ : right--;
    }

    return maxWater;
}

int main() {
    vector<int> containers = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    // output with brute force
    cout << "max water with brute force is - " << maxWaterBrute(containers) << endl;

    // output with two pointer approach
    cout << "max water with Two Pointer Approach is - " << maxWaterOpt(containers) << endl;
}