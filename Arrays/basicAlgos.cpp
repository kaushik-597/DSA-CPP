#include <iostream>
using namespace std;

// LINEAR SEARCH on Array - time complexity - O(n)
int linearSRCH(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

// Reverse an array using two pointer approach
void reverseArr(int arr[], int size)
{
    int start = 0, end = size - 1;
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

// swapping the max and min numbers in the array
void swapMaxMin(int arr[], int size)
{
    int smallest = INT_MAX, largest = INT_MIN;
    int smallIdx = 0, largeIdx = 0;

    // searching for the smallest and largest numbers
    for (int i = 0; i < size; i++)
    {
        smallest = min(arr[i], smallest);
        largest = max(arr[i], largest);
    };

    // getting the index of the smallest and largest in the array
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == smallest)
        {
            smallIdx = i;
        }
        if (arr[i] == largest)
        {
            largeIdx = i;
        }
    }

    // swapping the smallest and largest numbers
    swap(arr[smallIdx], arr[largeIdx]);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int size = 6;
    int arr[size] = {6, 4, 7, 1, 9, 15};
    int target = 4;
    cout << linearSRCH(arr, size, target) << endl;
    // reverseArr(arr, size);
    swapMaxMin(arr, size);
}