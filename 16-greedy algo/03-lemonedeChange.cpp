#include <bits/stdc++.h>
using namespace std;

/*
    i have a bills which only 5, 10 20
    a person came and buy lemon with price you return them price
*/

bool func(vector<int> &arr)
{
    int five = 0, ten = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 5)
        {
            five++;
        }
        else if (arr[i] == 10)
        {
            if (five > 0)
            {
                five--;
                ten += 1;
            }

            else
                return false;
        }
        else
        {
            if (ten > 0 & five > 0)
            {
                ten -= 1;
                five -= 1;
            }
            else if (five >= 3)
            {
                five -= 3;
            }
            else
                return false;
        }
    }
    return true;
    // TC-> O(n);
    // SC-> O(1);
}

int main()
{
    vector<int> arr = {5, 5, 5, 10, 20};
    bool ans = func(arr);
    if (ans)
    {
        cout << "Possible." << endl;
    }
    else
    {
        cout << "Not possible." << endl;
    }
    return 0;
}