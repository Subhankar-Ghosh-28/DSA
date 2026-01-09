#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0, maxDepth = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '(') cnt++;

            else if(s[i] == ')') cnt--;
            maxDepth = max(maxDepth,cnt);
        }
        return maxDepth;
    }
};

int main(){
Solution sol;
    string s = "(1+(2*3)+((8)/4))+1";
    int result = sol.maxDepth(s);
    cout << "Max Depth: " << result << endl;
return 0;
}