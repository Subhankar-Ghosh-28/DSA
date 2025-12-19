#include<bits/stdc++.h>
using namespace std;

int main(){
    int start = 13;
    int goal = 7;
    int cnt = 0;
    int ans = start^goal;

    for (int i = 0; i < 32; i++)
    {
        if(ans & (1<<i)) cnt++;
    }

    cout<<cnt;
    
    return 0;
}