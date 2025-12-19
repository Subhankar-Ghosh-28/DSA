#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> brute_sol(vector<vector<int>> &matrix){
  int n = matrix.size();
  int m = matrix[0].size();
  vector<vector<int>> ans(m,vector<int>(n));
    for(int i =0 ; i<n; i++){
        for(int j = 0; j < m; j++){
          ans[j][n-1-i]= matrix[i][j];
        }
    }
    return ans;
}

// optimal for square matrix if non-square matrix then create a defffrent matrix and then excutive same way
vector<vector<int>> optimal_sol(vector<vector<int>> &matrix){
     int n = matrix.size();
    
     
     for(int i =0;i<n;i++){
        for(int j =i+1; j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
     }
      for(int i =0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
      }
      return matrix;
}

int main(){
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
 vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter the matrix:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matrix[i][j];

    vector<vector<int>> rotatedMatrix = brute_sol(matrix);

    cout << "Matrix after 90 degree rotation:\n";
    for (int i = 0; i < rotatedMatrix.size(); i++) {
        for (int j = 0; j < rotatedMatrix[0].size(); j++) {
            cout << rotatedMatrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}