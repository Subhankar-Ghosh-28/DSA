#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the array number ";
    cin >> n;
    int arr[n];
    cout << "Enert the array element " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // precompute
    int Hash[100001] = {0};
    for (int i = 0; i < n; i++)
    {
        Hash[arr[i]] += 1;
        
    }
    int q;
    cout << "Enter the how many numbers want search" << endl;
    cin >> q;
    while (q > 0)
    {
        q--;
        int number;
        cout << "Enter number wants to search " << endl;
        cin >> number;
        // fetch
        
        cout<<"The number appears "<<Hash[number]<<" times"<<endl;
        
    }
    return 0;
}