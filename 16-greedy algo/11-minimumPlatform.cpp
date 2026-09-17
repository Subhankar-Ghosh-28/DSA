// minimum number of platform need to arrival and dpart of given trains
// two array arrival time and departure time of every i'th trains

#include <bits/stdc++.h>
using namespace std;

class minimumPlateform
{
public:
    int bruteForce(int n, int arraival[], int dep[])
    {
        int maxCnt = 0;

        for (int i = 0; i < n; i++)
        {
            int cnt = 1;

            for (int j = i + 1; j < n; j++)
            {
                if (arraival[i] >= arraival[j] && arraival[i] <= dep[j] ||
                    arraival[j] >= arraival[i] && arraival[j] <= dep[i])
                {
                    cnt++;
                }
            }
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
        // TC-> O(N^2) ,  SC-> O(1)
    }

    int optimal(int n, int arr[], int dep[])
    {
        sort(arr, arr + n);
        sort(dep, dep + n);

        int i = 0, j = 0;

        int cnt = 0, maxCnt = 0;

        while (i < n)
        {
            if (arr[i] <= dep[j])
            {
                cnt++;
                i++;
            }
            else
            {
                cnt--;
                j++;
            }

            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;

        // TC-> O(2nlog n) + O(2n);
    }
};

int main()
{
    int arr[] = {900, 945, 955, 1100, 1500, 1800};
    int dep[] = {920, 1200, 1130, 1150, 1900, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);

    minimumPlateform obj;
    cout << "Minimum number of Platforms required "
         << obj.optimal(n, arr, dep) << endl;
    return 0;
}