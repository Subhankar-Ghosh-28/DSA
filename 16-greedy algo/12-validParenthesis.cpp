//  s = (*))  * could be '(', ')', 'null';
// give me the string is a valid parenthesis or not

#include <bits/stdc++.h>
using namespace std;

class isValid
{
private:
    bool helperBruteForce(string &s, int index, int cnt)
    {
        if (cnt < 0)
            return false;

        if (index == s.size())
            return cnt == 0;

        if (s[index] == '(')
        {
            return helperBruteForce(s, index + 1, cnt + 1);
        }
        if (s[index] == ')')
        {
            return helperBruteForce(s, index + 1, cnt - 1);
        }

        return helperBruteForce(s, index + 1, cnt + 1) ||
               helperBruteForce(s, index + 1, cnt - 1) ||
               helperBruteForce(s, index + 1, cnt);
    }

public:
    bool bruteforce(string s)
    {
        int cnt = 0;
        int size = s.size();

        return helperBruteForce(s, 0, cnt);

        // TC-> O(3^n) 3 recursive call
        //  SC->O(n)  auxilary stack space
    }

    bool better(string s)
    {
        // DP

        // TC-> O(n^2);
        // SC-> o(n ^ 2);
    }

    bool optimal(string s)
    {

        // use range o 1 -1 in cnt ,, if range min == 0 true;

        int n = s.size();
        int mini = 0, maxi = 0;

        for (auto it : s)
        {
            if (it == '(')
            {
                mini++;
                maxi++;
            }
            else if (it == ')')
            {
                mini--;
                maxi = maxi - 1;
            }

            else
            {
                mini--;
                maxi--;
            }

            if (mini < 0)
                mini = 0;
            if (maxi < 0)
                return false;
        }

        return mini == 0;

        // TC->O(n)
        // SC-> O(n)
    }
};

int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;

    isValid sol;
    if (sol.optimal(s))
    {
        cout << "Valid parenthesis string\n";
    }
    else
    {
        cout << "Invalid parenthesis string\n";
    }
    return 0;
}