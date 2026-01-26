#include <iostream>
using namespace std;

/*
1 2 3 4 5 
1 2 3 4
1 2 3
1 2
1
*/

int main()
{
    int n;
    cout << "Enter the number ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {

        for (int j = 1; j <= n - i; j++)
        {

            cout << j << " ";
        }

        cout << endl;
    }
    return 0;
}