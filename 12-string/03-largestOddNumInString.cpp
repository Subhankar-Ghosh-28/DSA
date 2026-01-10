#include <bits/stdc++.h>
using namespace std;

string largestOddNum(string nums)
{
    int n = nums.size();
    int idx = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if ((nums[i] - '0') % 2 == 1)
        {
            idx = i;
            break;
        }
    }
    int i = 0;
    while (i <= idx && nums[i] == ' ')
        i++;

    return nums.substr(i, idx - i + 1);
}

int main()
{
    string num = "504";
    string result = largestOddNum(num);
    cout << "Largest odd number: " << result << endl;
    return 0;
}