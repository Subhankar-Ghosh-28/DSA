#include<bits/stdc++.h>
using namespace std;

int optimal( int n ){
    int cnt = 0;
    while(n>1){
        cnt += n&1;
        n = n>>1;
    }
    if ( n== 1) cnt++;
    return cnt;
}

int main(){
    int n = 13;
    cout<<optimal(n);
    cout<<__builtin_popcount(n);
    return 0;
}