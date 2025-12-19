#include<iostream>
using namespace std;
// chekc is a array is sorted or not 
bool checker(int arr[],int n){
    for(int i = 1; i<n; i++){
        if (arr[i]>=arr[i-1]){
            
        }
        else return false;
    }
    return true;
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
   
    int a=checker(arr,n);
    if(a == true){
       cout<<"sorted";
    }
    else cout<<"not sorted";
    return 0;
}