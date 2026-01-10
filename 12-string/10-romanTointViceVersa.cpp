#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int romanToInt(string &s)
    {
        int res = 0;
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 100}, {'M',1000,}
        };

        for (int i = 0; i < s.size() - 1; i++)
        {
            if(roman[s[i]] < roman[s[i+1]]){
                res -= roman[s[i]];
            }
            else {
                res += roman[s[i]];
            }
        }
        return res + roman[s.back()];
    }

    string intToRoman(int num){
        int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string symbols[] ={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string res = "";

        for (int i = 0; i < 13; i++)
        {
            while(num>= values[i]){
                num -= values[i];
                res += symbols[i];
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string s = "MCMXCIV"; 
    int result = sol.romanToInt(s);
    
    int n = result;
    string res = sol.intToRoman(n);

    cout<< "Roman value: "<< res<< endl;
    cout << "Integer value: " << result << endl;
    return 0;
}