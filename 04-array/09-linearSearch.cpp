#include <bits/stdc++.h>
using namespace std;
// return the index where the element located;

int linearSearch(vector<int> &arr, int searchElement)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == searchElement)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 3, 4, 52, 7, 9};

    int element;
    cout << "Enter the search element: ";
    cin >> element;
    ;
    cout << "Element at: " << linearSearch(arr, element) << "index";
    return 0;
}