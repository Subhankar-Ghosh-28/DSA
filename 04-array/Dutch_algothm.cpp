#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
// 0s 1s 2s array
void DutchNationalFlagAlgo(vector<int> &arr, int n)
{
  int low = 0, mid = 0, high = n - 1;
  while (mid <= high)
  {
    if (arr[mid] == 0)
    {
      swap(arr[low], arr[mid]);
      low++;
      mid++;
    }
    else if (arr[mid] == 1)
    {
      mid++;
    }
    else
    {
      swap(arr[high], arr[mid]);
      high--;
    }
  }
}
int main()
{
  vector<int> arr;
  int n;
  cout << "number array element " << endl;
  cin >> n;
  cout << "input only 0,1,2 arrray " << "\n";
  for (int i = 0; i < n; i++)
  {
    int element;
    cin >> element;
    arr.push_back(element);
  }
  DutchNationalFlagAlgo(arr, n);
  cout << "output" << endl;
  for (auto it : arr)
  {
    cout << it << " ";
  }
  return 0;
}