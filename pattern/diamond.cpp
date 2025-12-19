#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter hte number ";
    cin>>n;
    for(int i =0;i< n ;i++){
        //start
        for(int j = 0; j<n-i;j++){
            cout<<"*";
        }
        //space
        for(int j =0;j<2*i;j++){
            cout<<" ";
        }
         //start
        for(int j = 0; j<n-i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        for (int j = 1; j <=i; j++)
        {
           cout<<"*";
        }
        for(int j= 1;j<=2*(n-i);j++){
            cout<<" ";
        }
         for (int j = 1; j <=i; j++)
        {
           cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}
// **********
// ****  ****
// ***    ***
// **      **
// *        *
// *        *
// **      **
// ***    ***
// ****  ****
// **********