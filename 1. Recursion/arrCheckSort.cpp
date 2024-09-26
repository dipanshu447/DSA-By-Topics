// Given an array, check whether the array is in sorted order with recursion
#include <iostream>
using namespace std;

bool checkSort(int a[], int n)
{
    if (n == 1)
    {
        return true;
    }

    return (a[n - 1] < a[n - 2] ? false : checkSort(a, n - 2));
}

int main()
{

    int a[] = {23, 34, 56, 78, 24};
    int n = sizeof(a) / sizeof(a[0]);
    bool check = checkSort(a, n);
    if (check == true)
    {
        cout << "True, your array is sorted." << endl;
    }
    else
    {
        cout << "False, your array is not sorted." << endl;
    }

    return 0;
}
