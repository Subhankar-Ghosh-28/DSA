#include<bits/stdc++.h>
using namespace std;

string conver2Binary(int n){
    string result = "";
    while( n != 1){
        if(n%2 == 1) result += '1';
        else result += '0';
        n = n/2;
    }
    if(n == 1) result += '1';
    reverse(result.begin(),result.end());
    return result;
}

int convert2Decimal(string x){
    int n = x.size();
    int powerOf2 = 1;
    int num = 0;

    for (int i = n-1; i >= 0; i--)
    {
        if(x[i] == '1'){
            num += powerOf2;
            
        }
        powerOf2 *= 2;
    }
    return num;
    


}

int main(){
    string  x = "1101";
    cout<<convert2Decimal(x);
    return 0;
}