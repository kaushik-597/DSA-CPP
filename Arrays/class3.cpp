#include <iostream>
#include <vector> //#include <bits/c++.h> this header file is sometimes used on online compilers but we are going use VECTOR Header file only.
using namespace std;

// single number problem
int uniqueNumSearch() {
    vector<int> nums = {4, 1, 2, 2, 1};
    int ans = 0;
    for (int num : nums) {
        // here doing bitwise XOR of each num in nums will remove the same numbers due to (n^n = 0)
        // and will return the actual unique number due to (n^0 = n)
        ans ^= num;
    };
    return ans;
}

int main() {
    // vectors are STL i.e. Std Template Library - tools or containers which is used to implement data structres easily
    vector<int> nameOfVector;
    // this thing doesnt give errors on initializing but if we try to access the values it, then segmentation error
    // is possible due to empty vector i.e. no data at that address in memory
    vector<int> vec1 = {1, 2, 3, 4};
    // thats why we use this way similar to arrays, it doesnt need us to assign the
    // size manually instead it automatically tracks the size by itself.
    vector<int> vec2(4, 7);
    // this way we can initialize the vector by providing the size and the value too, here 4 is
    // the size of vector and at every index the default value will be 7

    // accessing the vectors
    cout << vec1[2] << endl;
    cout << vec2[0] << vec2[1] << vec2[2] << vec2[3] << endl; // this is redundant and difficult as well
    // therefore we gonna use forEach specialized loop for vectors to access
    // the VALUES instead of index directly from vectors
    for (int valVec : vec2) {
        cout << valVec;
    }

    // vector functions are some implicit fxns built to some operations on them
    cout << "Size of vector-2 : " << vec2.size() << endl; // gives size of vector
    vec1.push_back(7);                                    // to add new data entries at the end of vector
    cout << "Pushed back/newly added value in vecto1- " << vec1[4] << endl;
    vec1.pop_back(); // to delete the last most value from the vector
    cout << "The first/front value of vector1 - " << vec1.front() << endl; // this gives the first value of vector
    cout << "The last/back value of vector1 - " << vec1.back() << endl;    // this gives the last value of vector
    cout << "the value at some specified index e.g. 3rd index - " << vec1.at(3) << endl;

    // the dynamic allocation/resizing occurs by creating a new vector with double capacity as that of the older one
    // and copying the older values as it is into the indexes, also we have two terms size and capacity as well as
    // methods for both to check the respective stats of the vector and in the end the older vec is deleted.
    vector<int> test;
    test.push_back(7);
    test.push_back(8);
    test.push_back(9);
    // now the size of the vector is 3 but the capacity is doubled every time so it should be 4, lets check it
    cout << "Size of test vec - " << test.size() << " capacity of test vec " << test.capacity() << endl;

    cout << "The unique num is " << uniqueNumSearch() << endl;
}
