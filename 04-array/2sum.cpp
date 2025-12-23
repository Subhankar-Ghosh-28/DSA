#include<iostream>
using namespace std;
void twosum(int arr[],int n,int target){
int a,b;
 for(int i =1;i<n;i++){
    for(int j=0;j<n;j++){
        if((arr[i]+arr[j])== target){
          a = i;
          b=j;
         
        }
       
    }
  
 }

 cout<<"location of target "<<b<<" "<<a;
}

int main(){
     int n;
     cout<<"enter the number of the elements "<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter the array element "<<endl;
    for(int i =0; i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"enter target "<<endl;
    cin>>target;
    twosum(arr,n,target);
    return 0;
}