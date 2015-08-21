#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

// O(n^2)
void getDP1(int arr[], int len, int **dp)
{
	if (arr == NULL || len <= 0)
		return;
	*dp = new int[len];
	for (int i = 0; i < len; i++)
	{
		(*dp)[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				(*dp)[i] = std::max((*dp)[i], (*dp)[j]+1);
			}
		}
	}
}
// O(nlogn) with bi-search
void getDP2(int arr[], int len, int** dp)
{
	if (NULL == arr || len <= 0)
		return;
	*dp = new int[len];
	int* ends = new int[len];
	ends[0] = arr[0];
	(*dp)[0] = 1;
	int right = 0;
	for (int i = 1; i < len; i++)
	{
		int l = 0;
		int r = right;
		while (l <= r)
		{
			int m = (l + r) / 2;
			if (arr[i] > ends[m])
			{
				l = m + 1;
			}
			else
			{
				r = m - 1;
			}
		}
		right = std::max(l, right);
		ends[l] = arr[i];
		(*dp)[i] = l + 1;
	}
}
void getLis(int arr[], int dp[], int len, int** res, int* rlen)
{
	int max = 0;
	int index = -1;
	for (int i = 0; i < len; i++)
	{
		if (dp[i] > max)
		{
			max = dp[i];
			index = i;
		}
	}

	*rlen = max;
	*res = new int[max];
	(*res)[--max] = arr[index];
	for (int i = index; i >= 0; i--)
	{
		if (arr[i] < arr[index] && dp[i] == dp[index] - 1)
		{
			(*res)[--max] = arr[i];
			index = i;
		}
	}
}

void LIS(int arr[], int len, int** res, int* rlen)
{
	if (arr == NULL || len <= 0)
		return ;
	int* dp = NULL;
	getDP1(arr, len, &dp);
	//getDP2(arr, len, &dp);
	getLis(arr, dp, len, res, rlen);
	delete[] dp;
}
int main()
{
	int arr[]= {2,1,5,3,6,4,8,9,7};
	
	
	int* res = NULL;
	int len  = 0;
	LIS(arr, sizeof(arr)/sizeof(int), &res, &len);



	// output
	for (int i = 0; i < len; i++)
		cout << res[i] << " ";
	cout << endl;
	


	delete[] res;
	return 0;
}