#include <iostream>

using namespace std;


int missNumber(int arr[], int len)
{
  int l = 0;
  int r = len;
  while (l < r ) {
    if (arr[l] == l+1)
    {
      l++;
    }
    else if (arr[l] <= l || arr[l] > r || arr[arr[l]-1] == arr[l])
    {
      arr[l] = arr[--r];
    }
    else{
      std::swap(arr[l], arr[arr[l]-1]);
    }
  }
  return l+1;
}


int main()
{
  int arr[] = {3,6,4,2,1,-2,-9,7};
  cout << missNumber(arr, 8) << endl;

  return 0;
}
