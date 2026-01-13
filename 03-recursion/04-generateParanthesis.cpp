#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isString(string s)
    {
        int balance = 0;

        for (char c : s)
        {
            if (c == '(')
                balance++;
            else
                balance--;

            if (balance < 0)
                return false;
        }

        return balance == 0;
    }

    void bruteHelper(string curr, int n, vector<string> &result)
    {
        if (curr.size() == 2 * n)
        {
            if (isString(curr))
                result.push_back(curr);
            return;
        }

        bruteHelper(curr + '(', n, result);
        bruteHelper(curr + ')', n, result);
    }

    void optimalHelper(string curr ,int open, int close, int n , vector<string>& result){
        if(curr.length() == 2*n){
            result.push_back(curr);
            return;
        }

        if(open < n){
            optimalHelper(curr+'(',open+1, close, n , result);
        }
        if(close<open){
            optimalHelper(curr+ ')' , open, close+1, n, result);
        }

    }

public:
    vector<string> bruteForce(int n)
    {
        vector<string> res;
        bruteHelper("", n, res);

        return res;              //TC: O(2^(2n) * n) due to the generation and validation of all 2^(2n) sequences.
    }                           // sc : O(n)  for every sequence;

    vector<string> optimal(int n)
    {
        
        vector<string> res;
        optimalHelper("",0,0, n, res);

        return res;
        /*
        Time Complexity: O(2^n) (Catalan number): C(n) = (2n)! / (n!(n+1)!) is the number of valid sequences.
        Each sequence takes O(n) to build.
        So, total complexity: O(C(n) × n)

        Space Complexity: O(n) recursion depth.
        O(C(n) × n) to store results.
        */
    }
};

int main()
{
    int n = 3;
    Solution sol;

    vector<string> result = sol.bruteForce(n);
    cout<<"Output for brute force: "<<endl;
    for (auto it : result)
    {
        cout << it << " ";
    }
    cout << endl;

    cout<< "Outpurt for optimal: "<<endl;

    result = sol.optimal(n);
    for (auto it : result)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}