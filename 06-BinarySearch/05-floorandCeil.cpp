#include <bits/stdc++.h>
using namespace std;

int ceil(int arr[], int n, int x) // The ceiling of x is the smallest element in the array greater than or equal to x
{
  int low = 0;
  int high = n - 1, ans;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] >= x)
    {
      ans = arr[mid];
      high = mid - 1;
    }

    else
      low = mid + 1;
  }
  return ans;
}

// The floor of x is the largest element in the array which is smaller than or equal to x
int floor(int arr[], int n, int x)
{
  int low = 0;
  int high = n - 1, ans;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] <= x)
    {
      ans = arr[mid];
      low = mid + 1;
    }

    else
      high = mid - 1;
  }
  return ans;
}

int main()
{

  int a[] = {2, 4, 5, 7, 8};
  int n = sizeof(a) / sizeof(a[0]);
  int key = 6;
  int b = ceil(a, n, key);
  int c = floor(a, n, key);

  //  int* b = lower_bound(a, a + n, key);

  cout << "ceil is " << b << endl;
  cout << "floor is " << c;

  return 0;
}