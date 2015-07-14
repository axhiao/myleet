#include <iostream>
#include <limits>

using namespace std;


int merge_sum(int arr[], int p, int q, int r)
{
	int nl = q - p + 1;
	int nr = r - q;
	int *L = new int[nl+1];
	int *R = new int[nr+1];
	for (int i = 0; i < nl; i++)
	{
		L[i] = arr[p + i];
	}
	L[nl] = (numeric_limits<int>::max)();
	for (int i = 0; i < nr; i++)
	{
		R[i] = arr[q+1+i];
	}
	R[nr] = (numeric_limits<int>::max)();
	int i = 0;
	int j = 0;
	bool counted = false;
	int sum = 0;
	for (int k = p; k <= r; k++)
	{
		if ( !counted && L[i] <= R[j])
		{
			sum += L[i] * (nr - j);
			counted = true;
		}
		if (L[i] <= R[j])
		{
			arr[k] = L[i++];
			counted = false; // expose a new element in L[i] to compared with R[j]
		}
		else
		{
			arr[k] = R[j++];
		}
	}
	return sum;
}
int small_sum(int arr[], int p, int r)
{
	int sum = 0;
	if (p < r)
	{
		int q = (p + r) / 2;
		sum += small_sum(arr, p, q);
		sum += small_sum(arr, q+1, r);
		sum += merge_sum(arr, p, q, r);
	}
	return sum;
}


int main()
{
	int arr[] = {1, 3, 5, 2, 4, 6};
	cout << small_sum(arr, 0, 5) << endl;
	return 0;
}