#include<iostream>
using namespace std;
//second largest element of ann array
void brutter_sol(int arr[],int n){
    //bubble sort
     for(int i = 0; i<n;i++){
     for(int j=0; j<=i-1;j++){
        if(arr[j]>arr[j+1]){
           swap(arr[j],arr[j+1]);   
        }
     }
    }
   int largest = arr[n-1];
   int second;
   for(int i = n-2;i>= 0;i--){
    if(arr[i] != largest){
         second = arr[i];
        
        // break;
    }
   }
   cout<<"ssecond largest is "<<second;
}
void better_sol(int arr[],int n){
    int largest = arr[0];
    for (int i = 0;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    int slargest =-1;
    for(int i = 0;i<n;i++){
        if(arr[i]>slargest && arr[i] != largest){
            slargest= arr[i];
        }
    }
    cout<<"second lagest is "<< slargest;
}
void optimal_sol (int arr[],int n){
    int largest = arr[0];
    int slargest = -1;
    for(int i = 1; i<n; i++){
        if(arr[i]>largest ){
            slargest = largest;
            largest = arr[i];
    }
    else if (arr[i] < largest && arr[i]>slargest){
        slargest= arr[i];
    }
    }
    cout <<"second larget is "<<slargest<<endl;
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
    optimal_sol(arr,n);
    return 0;
}