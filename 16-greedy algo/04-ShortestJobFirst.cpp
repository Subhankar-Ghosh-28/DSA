// do smallest job first

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sjf(vector<int> &arr)
    {
        int n = arr.size();

        int total = 0, waitTime = 0;
        sort(arr.begin(), arr.end());
        int i = 0;
        while (i < n)
        {
            waitTime += total;
            total += arr[i];
            i++;
        }
        return waitTime / n;
    }
    // TC-> O(nlogn + n)
    // sc-> O(1)
};

int main()
{
    int n;
    cout << "Enter the total number of works: ";
    cin >> n;

    vector<int> arr(n); // = {4,3,7,1,2};

    int i = 0;
    while (i < n)
    {
        int x;
        cout << "Enter " << i + 1 << " work time: ";
        cin >> x;
        arr[i] = x;
        i++;
    }
    cout << endl;
    cout << "The array of the work: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    Solution sol;

    cout << endl
         << "The answer is: " << sol.sjf(arr) << endl;
}