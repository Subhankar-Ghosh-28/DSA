#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {                  // n ^ th char
        for (char ch = ('A' + n - 1) - i; ch <= ('A' + n - 1); ch++)
        {
            cout << ch << " ";
        }
        cout << "\n";
    }

    return 0;
}
// E
// D E
// C D E
// B C D E
// A B C D E