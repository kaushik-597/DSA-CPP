#include <iostream>
#include <vector>
using namespace std;

// we need a boolean function to check if the mid is a valid answer of not
bool isValid(vector<int> &pagesArr, int totalStud, int books, int mid) {
    int maxAllowedPages = mid;
    int stud = 1, pages = 0; // starting with 1 student to allocate pages respectively

    // this for loop as O(n)
    for (int i = 0; i < books; i++) {
        // edge case where the array holds a value that surpasses the max pages threshold
        if (pagesArr[i] > maxAllowedPages) {
            return false;
        }

        // again if the current pages + pages to be allocated next are lower or equal to limit then do allocation
        if (pagesArr[i] + pages <= maxAllowedPages) {
            pages += pagesArr[i];
        } else {
            // else move to the next student by increasing the number of student and allocate it the new pages which are
            // totally different from the previous student so we simply overwrite the pages variable
            stud++;
            pages = pagesArr[i];
        }
    }

    // thus, if the number of students who got pages allocated are higher than the total number of students then return
    // false i.e. invalid else return true i.e. valid
    return stud > totalStud ? false : true;
}

// book allocation problem - we cant simply solve this problem using binary search cuz the pages array is never going to
// be a sorted array but what we can do is find the range of the pages from 0 i.e. start to end i.e. sum of all pages
// available and then use binary search on that range-array to find the minimum out of the maximum number of pages that
// can be allocated to the students
int allocateBooks(vector<int> &pagesArr, int totalStud, int books) {
    // checks
    if (totalStud > books)
        return -1;

    // first of all we need to define the range of total pages
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < books; i++) {
        sum += pagesArr[i];
    }
    int start = 0, end = sum; // range of possible answers

    while (start <=
           end) { // this while loop has O(log N * n) where N - range (start-end) and O(n) is complexity of isValid
        int mid = start + (end - start) / 2;

        // now we check if the mid is a valid answer or not, if it is then we check if there exists even a lower value
        // than mid in the left search space which can be valid, and if the mid was never valid in the first case, then
        // we go check the higher values ahead of mid i.e. right search space
        if (isValid(pagesArr, totalStud, books, mid)) {
            ans = mid;
            end = mid - 1; // if valid answer, we go even lower value i.e. left
        } else {
            start = mid + 1; // if invalid answer, we go higher value i.e. right
        }
    }
    return ans;
}

int main() {
    vector<int> pagesArr = {2, 1, 3, 4};
    int totalStud = 2, books = 4;

    // the results for book allocation problem using binary search
    cout << "the min of max pages that can be allocated: " << allocateBooks(pagesArr, totalStud, books) << endl;
}