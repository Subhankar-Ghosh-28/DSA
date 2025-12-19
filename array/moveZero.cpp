#include<iostream>
using namespace std;
//move all zeros o the end
void optimal_sol(int arr[],int n){
    int j,i;j=-1;
    for(i =0;i<n;i++){
        if(arr[i]==0){
            j=i;break;
        }
    }
    for (int i = j+1; i < n; i++)
    {
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    
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
    for(int i =0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}