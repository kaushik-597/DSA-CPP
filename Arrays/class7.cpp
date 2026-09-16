#include <iostream>
#include <vector>
using namespace std;

// Computing x^n i.e. x power n using BINARY EXPONENTIATION APPROACH
double binaryExpo(double x, long n) {
    double ans = 1;

    // some edge cases that we already know about and these can't be changed anyhow
    if (n == 0)
        return 1.0;
    if (x == 1)
        return 1.0;
    if (x == 0)
        return 0.0;
    if (x == -1 && n % 2 == 0)
        return 1.0;
    if (x == -1 && n % 2 != 0)
        return -1.0;

    // if a power i.e. n is negative, then we can just reciprocate x and make the power positive again
    if (n < 0) {
        x = 1 / x;
        n = -n;
    };

    while (n > 0) {
        // this is to check if the last most bit is "1" or not, if it 1 then we need to count this bit of 2^0, 2^2,
        // 2^4... series so that it adds upto "n"  and for that we'll just multiply the ans with x cuz 2^0 is always 1
        // and x^1 is x thus answer becomes x for rightmost-bit
        if (n % 2 == 1) {
            ans *= x;
        }

        // now the squaring of x is done cuz we need to move to the next power such as 2^2, 2^4, 2^8... the power is
        // being doubled therefore x is getting squared everytime
        x *= x;

        // also we need to move the next bit of n therefore we divide it with 2 to remove the rightmost bit and again
        // the first step of checking if the rightmost bit is 1 or not will continue
        n /= 2;
    }
    return ans;
}

// Stock Buy and Sell Problem - using vectors
int buySellStock(vector<int> prices) {
    // the thought here is we first need to determine the best buy price and then only we can sell the stock and get the
    // maximum profit out of it, for that we need maxprofit and bestbuy also we can just check the best selling price by
    // comparing the maxprofit of the current index and the previous ones, also we dont need to find the besy buy
    // separately we can just keep updating it until we find the minimum value of prices by comparing it to the current
    // index value
    int maxProfit = 0, bestBuy = prices[0];
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] > bestBuy) {
            maxProfit = max(maxProfit, prices[i] - bestBuy);
        };
        bestBuy = min(bestBuy, prices[i]);
    }
    return maxProfit;
}

int main() {
    double x = 3;
    long n = -1;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    // Binary Exponentiation Results
    cout << "the results for x^n using binaryexpo is - " << binaryExpo(x, n) << endl;

    // stock buy and sell results
    cout << "The max profit is - " << buySellStock(prices) << endl;
}