#include<bits/stdc++.h>
using namespace std;

// print all prime num till n (given)

class Solution {
    public:

    bool checkPrine(int num)
    {
        int cnt = 0;
        for (int i = 1; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                cnt++;
                if (num / i != i)
                    cnt++;
            }
        }
        return (cnt == 2) ? true : false;
    }

    vector<int> bruteForce(int n){

        vector<int> ans;
        for (int i = 2; i <= n; i++)
        {
            if(checkPrine(i)) ans.push_back(i);
        }
        return ans;
    }

    vector<int>optimal(int n){
        vector<int> ans,prime(n+1);
        for (int i = 2; i <= n; i++){ 
            prime[i] = 1;
        }

        for (int i = 2; i*i <= n; i++){
            if(prime[i] == 1){
                for (int j = i*i; j <= n; j+=i)
                {
                    prime[j] = 0;
                }
                
            }
        }

        for (int i = 2; i <= n; i++)
        {
            if(prime[i] == 1){                                  //Tc -> o(n)+o(nloglogn)+o(n),,,sc -> o(n)
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    for (auto it : sol.bruteForce(36))
    {
        cout << it << " ";
    }
    cout << "\n";
    for (auto it : sol.optimal(36))
    {
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}