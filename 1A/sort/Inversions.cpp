#include <iostream>
#include <limits>

using namespace std;


int merge_inversions(int arr[], int p, int q, int r)
{
	int nl = q - p + 1;
	int nr = r - q;
	int *L = new int[nl+1];
	int *R = new int[nr+1];
	// left side of array
	for (int i = 0; i < nl; i++)
	{
		L[i] = arr[p+i];
	}
	L[nl] = (numeric_limits<int>::max)();//sentinel
	// right side of array 
	for (int i = 0; i < nr; i++)
	{
		R[i] = arr[q+1+i];
	}
	R[nr] = (numeric_limits<int>::max)();//sentinel

	int inv_cnt = 0;
	bool counted = false;
	int i = 0;
	int j = 0;
	for (int k = p; k <= r; k++)
	{
		if (!counted && R[j] < L[i])
		{
			//inv_cnt += nl - i + 1;
			inv_cnt += nl - i;

			counted = true;
		}
		if (L[i] <= R[j])
		{
			arr[k] = L[i++];
		}
		else
		{
			arr[k] = R[j++];
			counted = false;
		}
	}
	delete[] L;
	delete[] R;
	return inv_cnt;
}

int count_inversions(int arr[], int p, int r)
{
	int inversions = 0;
	if (p < r)
	{
		int q = (p + r) / 2;
		inversions += count_inversions(arr, p, q);
		inversions += count_inversions(arr, q+1, r);
		inversions += merge_inversions(arr, p, q, r);
	}
	return inversions;
}
int main()
{
	int arr[] = {2, 3, 8, 6, 1};

	cout << count_inversions(arr, 0, 4) << endl;

	return 0;
}