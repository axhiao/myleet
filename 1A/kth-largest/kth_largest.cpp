#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 *  DATE: 6/16/2015
 *  Author: axhiao
 *  find the kth-largest number
 *  @para:
 *  @return kth-largest number
 *
*/
int kth_largest(int arr[], int low, int high, int kth)
{
	if (kth <= 0)
		return -1;
	if (kth > (high - low +1))
		return -1;
	// randomly select an element as the pivot
	int rj = low + rand() % (high - low + 1);
	std::swap(arr[low], arr[rj]);
	// one partition
	int cnt = 1; // no less than pivot, including the pivot
	int m = low;
	for (int i = low + 1; i <= high; ++i)
	{
		if (arr[i] >= arr[low])
		{
			std::swap(arr[++m], arr[i]);
			cnt++;
		}
	}
	std::swap(arr[low], arr[m]);
	// 3 situations
	if (kth < cnt)
	{
		return kth_largest(arr, low, m - 1, kth);
	}
	else if (kth > cnt)
	{
		return kth_largest(arr, m + 1, high, kth-cnt);
	}
	else 
		return  arr[m];
}

int main()
{
	int a[] = {5, 15, 5, 7, 9, 17, 100, 3, 12, 10, 19, 18, 16, 10, 1000, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	int len = sizeof(a)/sizeof(int);

	int arr[] = {5, 15, 5, 7, 9, 17, 100};
	
	cout << kth_largest(arr, 0, 6, 1) << endl;
	cout << kth_largest(arr, 0, 6, 2) << endl;
	cout << kth_largest(arr, 0, 6, 3) << endl;
	cout << kth_largest(arr, 0, 6, 4) << endl;
	cout << kth_largest(arr, 0, 6, 5) << endl;
	cout << kth_largest(arr, 0, 6, 6) << endl;
	cout << kth_largest(arr, 0, 6, 7) << endl;
	
	//cout << kth_largest(a, 0, len - 1, 3) << endl;

	return 0;
}
