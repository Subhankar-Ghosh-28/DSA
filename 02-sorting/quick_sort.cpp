#include <iostream>
#include <vector>
using namespace std;
int partisionf(vector<int> &arr, int low, int high)
{
  int pivot = arr[low];
  int i = low;
  int j = high;

  while (i < j)
  {
    while (arr[i] <= pivot && i <= high - 1)
    {
      i++;
    }
    while (arr[j] > pivot && j >= low + 1)
    {
      j--;
    }
    if (i < j)
    {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  int temp1 = arr[low];
  arr[low] = arr[j];
  arr[j] = temp1;
  return j;
}
void quick_sort(vector<int> &arr, int low, int high)
{
  if (low < high)
  {
    int partision = partisionf(arr, low, high);
    quick_sort(arr, low, partision - 1);
    quick_sort(arr, partision + 1, high);
  }
}

int main()
{
  vector<int> arr;
  int n;
  cout << "enter the number of element" << endl;
  cin >> n;
  cout << "input" << "\n";
  for (int i = 0; i < n; i++)
  {
    int element;
    cin >> element;
    arr.push_back(element);
  }
  quick_sort(arr, 0, n - 1);
  cout << "output" << endl;
  for (auto it : arr)
  {
    cout << it << " ";
  }
  return 0;
}