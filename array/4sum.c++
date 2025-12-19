#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> brute_force(vector<int> &arr,int target){
    int n = arr.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++){
        for(int j = i+1;j<n;j++){
            for(int k= j+1;k<n; k++){
                for(int l = k+1;l<n;l++){

                     long long sum = arr[i] + arr[j];
                    sum += arr[k];
                    sum += arr[l];
                  if ( sum == target){
                    vector<int> temp = {arr[i],arr[j],arr[k],arr[l]};
                    sort(temp.begin(),temp.end());
                    st . insert(temp);
                  }
                 }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

vector<vector<int>> better(vector<int> &arr,int target){
    int n = arr.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++){
      
      for(int j = i+1;j<n;j++){
        set <int> hashset;
        for(int k = j+1 ;k<n;k++){
            long long sum = arr[i] + arr[j];
                sum += arr[k];
        int forth = target -sum;
        if(hashset.find(forth) != hashset.end()){
             vector<int> temp = {arr[i], arr[j], arr[k],(int)forth};
                sort(temp.begin(), temp.end());
                st.insert(temp);
        }
        hashset.insert(arr[k]);
      }
    }

    }
     vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

vector<vector<int>> optimal(vector<int> &arr, int target){
     int n = arr.size();
     vector<vector<int>> ans;
     sort(arr.begin(),arr.end());
        for (int i = 0; i < n; i++) {
        // avoid the duplicates while moving i:
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            // avoid the duplicates while moving j:
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                sum += arr[l];
                if (sum == target) {
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++; l--;

                    //skip the duplicates:
                    while (k < l && arr[k] == arr[k - 1]) k++;
                    while (k < l && arr[l] == arr[l + 1]) l--;
                }
                else if (sum < target) k++;
                else l--;
            }
        }
    }

    return ans;
}


int main(){
      vector<int> arr = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = better(arr,target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}