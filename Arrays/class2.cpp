#include <iostream>
using namespace std;

// Pass By Reference - this thing changes the values of array in the parent too unlike
// local variables which dont interfere with the values passed as args or params
void changeArr(int arr[], int size)
{
    cout << "the fxn changeArr uses pass by ref and changes the values in main fxn too" << endl;
    for (int i = 0; i < size; i++)
    {
        arr[i] = 2 * arr[i];
    }
};

int main()
{
    int size = 5;
    int marks[size] = {78, 59, 66, 79, 9};

    // for(int i = 0; i < size; i++){
    //     cin>>marks[i];
    //     cout<<"Array["<<i<<"] is "<<marks[i]<<endl;
    // }

    // this will print the memory location of the array variable (not sure if its the mem loc exactly)
    cout << marks << endl;

    // length of array
    cout << sizeof(marks) / sizeof(int) << endl;

    // brute force + implicit functions - smallest number in array
    int smallest = INT_MAX; // int max is +infinity
    int largest = INT_MIN;  // int min is -infinity
    for (int i = 0; i < size; i++)
    {
        // brute force
        // if(marks[i] < smallest){
        //   smallest = marks[i];
        // }

        // using MIN implicit function for smallest
        smallest = min(marks[i], smallest);

        // using MAX implicit function for largest
        largest = max(marks[i], largest);
    }
    cout << "Smallest number in Array is " << smallest << endl;
    cout << "Largest number in Array is " << largest << endl;

    // Pass By Reference usecase
    cout << "before the fxn changeArr uses pass by ref, the values of original marks array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << marks[i] << " ";
    }
    changeArr(marks, size);
    cout << "after the fxn changeArr uses pass by ref, the values of original marks array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << marks[i] << " ";
    }
    // this is weird cuz how a function is changing the local variable of MAIN,
    // but the reasoning behind it is that the name of the array variable is a POINTER and doesnt store the values itself,
    // instead it stores the address of the array which means we are not passing the array as the parameters
    // but the address and since the other fxn has the address, it is going to change the value at that address,
    // which seems to like the local variable is being changed by another fxn out of its scope. confirm this first with gpt
    // so basically, passing the array to any function can change the values cuz it doesnt make copies like parameters,
    // instead it uses the pointer to locate the array itself and this is called pass by reference.
    return 0;
}