#include <iostream>
using namespace std;
// move all zeros o the end
void optimal_sol(int arr[], int n)
{
    int i, j = -1;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (i == -1) return;

    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    /*
    int i = 0;
    for (int j = 0; j < n; j++) {
    if (arr[j] != 0) {
        swap(arr[i], arr[j]);
        i++;
    }
}
    */
}

int main()
{
    int n;
    cout << "enter the number of the elements " << endl;
    cin >> n;
    int arr[n];
    cout << "enter the array element " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    optimal_sol(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}