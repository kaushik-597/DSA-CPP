#include <iostream>
using namespace std;

// pointers
void pointers() {
    int a = 10;
    int *ptr = &a;
    int **ptr2 = &ptr;
    int *ptr3 = NULL;

    cout << "a-" << a << " &a-" << &a << " ptr-" << ptr << " *ptr (dereference)-" << *ptr << " ptr2-" << ptr2
         << " *ptr2(dereference)-" << *ptr2 << " **ptr2(dereference)-" << **ptr2 << " ptr3-" << ptr3 << endl;
}

// pass by reference - using pointers, here instead of making a copy for the passed parameters, we pass the actual and
// exact variable's address so that this other local fxn can access and manipulate it right where it is in the memory
// to do that we need to pass the address while callin this fxn and in the declaration we define a pointer then we
// dereference it and assign some different value from the original value to check if it works or not
void changeA(int *ptr) {
    *ptr = 20;
}

// array pointers
void arrPointers() {
    int arr[] = {1, 2, 3, 4, 5};
    // array name/variable itself is a special variable of type pointer which is constant this pointer points to the
    // location of the 0th element of the array i.e. address of starting point of the array
    cout << "arr name is an address/pointer - " << arr << endl;

    cout << "dereferencing arr i.e. *arr gives 0th idx value - " << *arr << endl;

    // also we can perform pointer arithmatic like decrement, increment, substraction, comparison operations as well on
    // the array pointers but all of these use a strange way, i mean they just do the usual operations but instead of
    // adding numbers they add/sub/etc. memory space in bytes of the data-type of that pointer itself, like below from
    // here we do arr+1 which means we add 1-int into the array address that is 4 bytes and further on we keep doing
    // this as 2-int, 3-int and so on, which will print all the elements on those addresses
    cout << "dereferencing arr+1,2,3 i.e. *arr gives 0th idx value and so on - " << *arr << *(arr + 1) << *(arr + 2)
         << *(arr + 3) << endl;

    // also if we dont dereference then we can simply see the addition of int-bytes into the hexadecimal address space
    cout << "not dereferencing arr+1,2,3 i.e. arr gives 0th idx address and so on - " << arr << " " << (arr + 1) << " "
         << (arr + 2) << " " << (arr + 3) << endl;

    // and finally instead of just adding 1,2,3 we can simply increment and decrement on the pointer itself but since
    // the arr is a constant non-modifiable pointer thats why we will assign the value to a basic ptr
    int *ptr = arr;
    int *ptr2 = arr + 2;
    cout << "arr++/ptr++ - " << ++ptr << endl;
    cout << "arr+2/ptr+2 - " << ++ptr << endl;
    cout << "--arr/--ptr - " << --ptr << --ptr << endl;

    // last but not least we can substract the pointers (cant add them though), and on substracting the pointers,
    // instead of getting the actual substracted bytes from the address what we will get is the number of data-types
    // like if difference is 8 bytes and data-type is 4 then we get output as 2-ints
    cout << "substraction of ptr2 with ptr1 - " << ptr2 - ptr << " data-types i.e. ints" << endl;
}

int main() {
    pointers();

    // using pointers for pass by reference where &a is passed which is address of a
    int a = 10;
    changeA(&a);
    cout << "a after changeA is called - " << a << endl;

    // array pointers results
    arrPointers();
}