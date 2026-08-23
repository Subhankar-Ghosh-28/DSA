#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

class Solution
{
public:
    bool static Comparator(Item val1, Item val2)
    {
        if ((val1.value / val1.weight) >= (val2.value / val2.weight))
        {
            return true;
        }
        return false;
    }

    double func(Item arr[], int w, int n)
    {
        sort(arr, arr + n, Comparator);

        int totalVal = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i].weight <= w)
            {
                totalVal += arr[i].value;
                w -= arr[i].weight;
            }
            else
            {
                totalVal += (arr[i].value / arr[i].weight) * w;
                break;
            }
        }
        return totalVal;
    }

    // TC -> O(n + nlog n)
    // SC-> O(1);
};

int main()
{
    int n = 3, weight = 50;
    Item arr[n] = {{100, 20}, {60, 10}, {120, 30}};

    Solution sol;
    double ans = sol.func(arr, weight, n);

    cout << "The maximum value is: " << setprecision(2) << fixed << ans;
    return 0;
}