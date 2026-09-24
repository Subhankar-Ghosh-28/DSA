// we have an array which have ratings of student. We give them candy atleast 1
// and children with higher ratings has get more candy from neighbour(left and right side)
// greedyly minimum number of candy total need;

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bruteForce(vector<int> &ratings)
    {
        /*
        1. the approach is simple find the left array if arr[i] > arr[i - 1] add candy
        2. same for right array but from reverse arr[i] > arr[i + 1] add candy
        3. max of both left and right
        */

        int n = ratings.size();
        vector<int> left(n), right(n);

        left[0] = 1;

        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                left[i] = left[i - 1] + 1;
            }

            else
                left[i] = 1;
        }

        right[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                right[i] = right[i + 1] + 1;
            }

            else
                right[i] = 1;
        }

        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += max(left[i], right[i]);
        }
        return sum;

        // TC-> O(3N)
        //  SC-> O(2N
    }

    int better(vector<int> &ratings)
    {
        // instead of right loop,  we use pointer and directly add to sum

        int n = ratings.size();
        vector<int> left(n);

        left[0] = 1;

        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                left[i] = left[i - 1] + 1;
            }

            else
                left[i] = 1;
        }

        int right = 1, sum = max(1, left[n - 1]);

        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                right = right + 1;
            }
            else
                right = 1;

            sum += max(left[i], right);
        }
        return sum;

        // TC-> O(2N)
        //  SC-> O(N)
    }

    int optimal(vector<int> &ratings)
    {
        /*
        in this we use Slope algo

        when increase we sum incremently then decrease we reset sum as 1 then same
        edge case if down > peak sum then sum += down - peak;
        */

        int n = ratings.size();
        int sum = 1, i = 1;

        while (i < n)
        {
            // if slope is straight line

            if (ratings[i] == ratings[i - 1])
            {
                sum++;
                i++;
                continue;
            }

            int peak = 1;

            // increaseing slope
            while (i < n && ratings[i] > ratings[i - 1])
            {
                peak += 1;
                sum += peak;
                i++;
            }

            int down = 1;
            // deceasing slope
            while (i < n && ratings[i] < ratings[i - 1])
            {
                sum += down;
                i++;
                down++;
            }

            // edge case
            if (down > peak)
            {
                sum += down - peak;
            }
        }
        return sum;

        // TC-> O(N)
        //  SC-> O(1)
    }
};

int main()
{

    vector<int> arr = {0, 2, 4, 3, 2, 1, 1, 3, 5, 6, 4, 0, 0};

    Solution sol;

    cout << "The candy needs: " << sol.optimal(arr);

    return 0;
}