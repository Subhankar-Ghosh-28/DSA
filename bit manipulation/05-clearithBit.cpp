#include<bits/stdc++.h>
using namespace std;

int optimal(int n, int i){
    return n & (~(1<<i));
}

int main(){
    int n = 13; int x = 2;
    cout<<optimal(n,x);
    return 0;
}