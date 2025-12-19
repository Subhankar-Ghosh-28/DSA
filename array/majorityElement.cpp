#include<bits/stdc++.h>
using namespace std;
// majority element of an arr,if elemtn >  half of number of element in arr;
int brute_sol(vector <int> arr){
    int n = arr.size();
    int count = 0 ;
     for(int i=0;i<n;i++){
        for (int j =0;j<n;j++){
            if (arr[i]==arr[j]) count++;
        }
        if(count > n/2) return arr[i];
    }
    return -1;
}
int better_sol(vector <int> arr){
    int n = arr.size();
    map<int, int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it: mpp){
        if (it.second > (n/2)) {
            return it.first;
         }
    
}
return -1;
}
// moors voting majority
int optimal_sol(vector <int> arr){
 int n = arr.size();
 int elem, count=0;
for(int i=0;i<n;i++){
    if(count ==0){
        count = 1;
        elem = arr[i];
    }
    else if (arr[i] == 0){
        count++;
    }
    else{
        count--;
    }
    int count1 =0;
    for(int i=0;i<n;i++){
        if (arr[i] == elem){
            count1++;
        }
    }
    if (count1>n/2){
        return elem;
    }
    return -1;
}


}
int main(){
     vector<int > a ={ 7,7,2,7,5,3,7,2,7,7};
     int b ;
     b = better_sol(a);
    
        cout<<b;
     
    return 0;
}