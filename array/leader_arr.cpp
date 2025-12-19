#include<bits/stdc++.h>
using namespace std;
//every thing is right side is small then it is a leader

vector<int> brute_sol(vector<int> arr,int n){
  
    vector<int> ans;
    for(int i =0;i<n;i++){
          bool leader = true;
        for(int j = i+1;j<n;j++){
            if(arr[j]>arr[i]){
                leader = false;
                break;
            }
       
        }
           if(leader == true){
                ans.push_back(arr[i]);
            }
    }
    return ans;
}
vector<int> optimal_sol(vector<int> arr,int n){
     vector<int> ans;
     int maxi = INT_MIN;
     for(int i =n-1;i>=0;i--){
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
        }
        maxi = max(arr[i],maxi);
     }
     reverse(ans.begin(),ans.end());
     return ans;
}

int main(){
      int n;
    vector<int> arr;
    cout<<"Enter the number of the element "<<endl;
    cin>>n;
    cout<<"Enter the element "<<endl;
    for(int i =0;i<n;i++){
        int element;
        cin>>element;
        arr.push_back(element);
    }
    vector <int> a = optimal_sol(arr,n);
    for(auto it: a ){
        cout<<it<<" ";
    }
    return 0;
}