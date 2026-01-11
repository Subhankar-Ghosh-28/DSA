#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int countGood(int indx,int n){
    if(indx == n) return 1;

    int result = 0;

    if(indx % 2 == 0)
    {
        for(int digit :{0,2,4,6,8}){
        result = (result + countGood(indx + 1,n)) % MOD;
        }

        // if you not use loop just direct 5*countGood(indx + 1,n) for even
    }

    else {int arr[] = {0, 2, 3, 5, 7};

    for (int i = 0; i < 4; i++) {
        result = (result + countGood(indx + 1,n)) % MOD;
    }
    }
    return result;
}

int main(){
     int n = 2;
    cout << countGood(0, n) << endl;
    return 0;
}