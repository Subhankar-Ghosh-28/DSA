#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool bruteForce(string str, string goal)
    {
        if (str.length() != goal.length())
            return false;

        for (int i = 0; i < str.size(); i++)
        {
            string afterRotate = str.substr(i) + str.substr(0, i);

            if (afterRotate == goal)
                return true;
        }
        return false;
    }

    bool optimal(string str, string goal)
    {
        if (str.length() != goal.length())
            return false;

        // Concatenate s with itself and check if goal exists in it
        string doubledS = str + str;
        return doubledS.find(goal) != string::npos;
    }
};

int main()
{
    string s = "rotation";
    string goal = "tionrota";
    Solution sol;
    cout << sol.bruteForce(s, goal) << endl;
    cout << sol.optimal(s, goal) << endl;
    return 0;
}