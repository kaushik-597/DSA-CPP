#include <iostream>
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

int main() {
    double x = 3;
    long n = -1;
    // Binary Exponentiation Results
    cout << "the results for x^n using binaryexpo is - " << binaryExpo(x, n);
}