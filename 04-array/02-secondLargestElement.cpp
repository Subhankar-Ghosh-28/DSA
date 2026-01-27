#include <iostream>
using namespace std;
// second largest element of an array
void bruteForce_sol(int arr[], int n)
{
    // bubble sort
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    int largest = arr[n - 1];
    int second;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > second && arr[i] != largest)
        {
            second = arr[i];

            // break;
        }
    }
    cout << "Second largest is " << second;
}
void better_sol(int arr[], int n)
{
    int largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    int slargest = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > slargest && arr[i] != largest)
        {
            slargest = arr[i];
        }
    }
    cout << "Second lagest is " << slargest;
}
void optimal_sol(int arr[], int n)
{
    int largest = arr[0];
    int slargest = -1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            slargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > slargest)
        {
            slargest = arr[i];
        }
    }
    cout << "Second larget is " << slargest << endl;
}
int main()
{
    int n;
    cout << "Enter the number of the elements " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the array element " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bruteForce_sol(arr, n);
    cout << endl;
    better_sol(arr, n);
    cout << endl;
    optimal_sol(arr, n);
    cout << endl;
    return 0;
}