#include <iostream>
#include <vector>
using namespace std;

vector<int> prodArrBrute(vector<int> nums) {
    // this is the brute force approach of solving PRODUCT OF ARRAY EXCEPT ITSELF
    // my very first thought was just multiply all the idx values and divide 'em with the currIdx value
    // but that very thought is the constraint here, i.e. we cant use the division operation
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
        int prod = 1;
        for (int j = 0; j < nums.size(); j++) {
            if (i != j) {
                prod *= nums[j];
            }
        }
        ans.push_back(prod);
    }
    return ans;
}

vector<int> prefixSuffixProd(vector<int> nums) {
    // here, we'll use the prefix-suffix approach to separately calculate the left-product and right-product from the
    // current index value, and then multiply these prefix and suffix respectively to get the final vector of the
    // products, since each calculation here uses a single loop therefore, the time complexity becomes O(3n) -> O(n)
    // also the space complexity is the same
    int n = nums.size();
    vector<int> ans(n, 1);
    vector<int> prefix(n, 1);
    vector<int> suffix(n, 1);

    // to calculate the prefix of i we need the product of prefix of previous number i.e. i-1 and the value of i-1
    // itself
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    // to calculate the suffix of i we need the product of suffix of next number i.e. i+1 and the value of i+1 itself
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    // to calculate the total product we needa multiply the prefix and suffix i-th values
    for (int i = 0; i < n; i++) {
        ans[i] = prefix[i] * suffix[i];
    }

    return ans;
}

vector<int> prefixSuffixUltra(vector<int> nums) {
    // this time we are just focusing on reducing the space complexity from O(n) to O(1) by reducing the vectors used
    int n = nums.size();
    vector<int> ans(n, 1);

    // to calculate the prefix of i we need the product of prefix of previous number i.e. i-1 and the value of i-1
    // itself but now that we are not storing the prefix into a new vector, we'll just store it into the answer vector
    // and use it as prefix
    for (int i = 1; i < n; i++) {
        ans[i] = ans[i - 1] * nums[i - 1];
    }

    // to calculate the suffix of i we need the product of suffix of next number i.e. i+1 and the value of i+1 itself
    int suffix = 1;
    for (int i = n - 2; i >= 0; i--) {
        suffix *= nums[i + 1]; // to calculate the i-th suffix
        ans[i] *= suffix;      // to get the product of prefix and suffix
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};

    // results for the product of array except self - brute force without division - O(n^2)
    vector<int> ans1 = prodArrBrute(nums);
    for (int ans : ans1) {
        cout << ans << " ";
    }
    cout << endl;

    // results for the product of array except self - prefix-suffix approach (optimal) - O(3n) == O(n)
    vector<int> ans2 = prefixSuffixProd(nums);
    for (int ans : ans2) {
        cout << ans << " ";
    }
    cout << endl;

    // results for the product of array except self - prefix-suffix approach (ultra-optimal) - TC - O(n) and SC - O(1)
    vector<int> ans3 = prefixSuffixUltra(nums);
    for (int ans : ans3) {
        cout << ans << " ";
    }
}