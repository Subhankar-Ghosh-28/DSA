#include <bits/stdc++.h>
using namespace std;
// allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.
// min(max) type;
class Solution
{
private:
    int countStudents(vector<int> &arr, int pages)
    {
        int n = arr.size();
        int students = 1;
        long long pagesStudent = 0;

        for (int i = 0; i < n; i++)
        {
            if (pagesStudent + arr[i] <= pages)
            {
                pagesStudent += arr[i];
            }
            else
            {
                students++;
                pagesStudent = arr[i];
            }
        }
        return students;
    }

public:
    int bruteForce(vector<int> &nums, int m)
    {
        int n = nums.size();

        if (m > n)
            return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        for (int i = low; i <= high; i++)
        {
            if (countStudents(nums, i) == m)
            {
                return i;
            }
        }
        return low;

        //TC -> O(n)* O(sum(arr[])-max(arr[])+1))
    }

    int optimal(vector<int> &nums, int m)
    {
        int n = nums.size();

        if (m > n)
            return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = low;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int student = countStudents(nums, mid);
            if (student <= m)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;

        // TC -> O(n)* O(log (sum(arr[])-max(arr[])+1)))
    }
};

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int m = 4;
    Solution soll;
    int ans = soll.optimal(arr, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}