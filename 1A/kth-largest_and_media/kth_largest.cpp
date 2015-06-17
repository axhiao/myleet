#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

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


/*
* RANDOMIZED-SELECT(A, p, r, i)
* 1 if p == r
* 2    return A[p]
* 3 q = RANDOMIZED-PARTITION(A, p, r)
* 4 k = q - p + 1
* 5 if i == k
* 6     return A[q]
* 7 else if i<k
* 8     return RANDOMIZED-SELECT(A, p, q-1, i)
* 9 else return RANDOMIZED-SELECT(A, q+1, r, i-k)
*/

int partition(int arr[], int low, int high) // arr[left] <= pivot, arr[right] > pivot
{
	srand(time(0));
	int rj = low + rand()%(high - low + 1);
	std::swap(arr[rj], arr[high]);

	int l = low - 1;
	int r = high;
	while(1)
	{
		while(arr[++l] < arr[high]);
		while(l < r && arr[--r] >= arr[high]);
		if(r <= l)
			break;

		std::swap(arr[l], arr[r]);
	}
	std::swap(arr[l], arr[high]);
	return l;
}
int randomized_select(int arr[], int p, int r, int kth)
{
	if (kth <= 0 || kth > (r - p +1))
		throw range_error("order statistic kth is out of range");
	if ( p == r)
		return arr[p];

	int q = partition(arr, p, r);
	int left_len = q - p + 1;

	if (kth < left_len)
	{
		return randomized_select(arr, p, q - 1, kth);
	}
	else if ( kth > left_len)
	{
		return randomized_select(arr, q + 1, r, kth - left_len);
	}
	else 
	{
		return arr[q];
	}
}


int main()
{
	//int a[] = {5, 15, 5, 7, 9, 17, 100, 3, 12, 10, 19, 18, 16, 10, 1000, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	//int len = sizeof(a)/sizeof(int);

	int arr[] = {5, 15, 5, 7, 9, 17, 100};
	int len = sizeof(arr)/sizeof(int);


	// order of midia = (len + 1)/2 
	cout << randomized_select(arr, 0, len - 1, (len + 1)/2) << endl;

	/*
	cout << kth_largest(arr, 0, 6, 1) << endl;
	cout << kth_largest(arr, 0, 6, 2) << endl;
	cout << kth_largest(arr, 0, 6, 3) << endl;
	cout << kth_largest(arr, 0, 6, 4) << endl;
	cout << kth_largest(arr, 0, 6, 5) << endl;
	cout << kth_largest(arr, 0, 6, 6) << endl;
	cout << kth_largest(arr, 0, 6, 7) << endl;
	*/
	//cout << kth_largest(a, 0, len - 1, 3) << endl;

	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;


	return 0;
}
