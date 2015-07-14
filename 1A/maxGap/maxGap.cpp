#include <iostream>
#include <algorithm>

using namespace std;

//使用long防止相乘的中间结果溢出
int bucket(long num, long len, long max, long min)
{
	//　if num==max then return len
	return (int)((num - min) * len / (max - min));
}


int maxGap(int arr[], int len)
{
	if (arr == NULL || len < 2)
		return 0;
	int min = *min_element(arr, arr+len);
	int max = *max_element(arr, arr+len);
	if (min == max)
		return 0;
	int *mins = new int[len+1];
	int *maxs = new int[len+1];
	bool *hasNum = new bool[len+1];

	for (int i = 0; i <= len; i++)
		hasNum[i] = false;
	for (int i = 0; i < len; i++)
	{
		// No. of bucket
		int bid = bucket(arr[i], len, max, min);

		mins[bid] = hasNum[bid] ? std::min(arr[i], mins[bid]) : arr[i];
		maxs[bid] = hasNum[bid] ? std::max(arr[i], maxs[bid]) : arr[i];
		hasNum[bid] = true;
	}
	int i = 0;
	int lastMax = 0;
	while (i <= len)// find the 1st nonempty bucket
	{
		if (hasNum[i++])
		{
			lastMax = maxs[i-1];
			break;
		}
	}
	int res = 0;
	for (; i <= len; i++)
	{
		if (hasNum[i])
		{
			res = std::max(mins[i] - lastMax, res);
			lastMax = maxs[i];
		}
	}
	delete[] mins;
	delete[] maxs;
	delete[] hasNum;
	return res;
}


int main()
{
	int arr[] = {9, 3, 1, 10, 4, 9, 32};
	int len = sizeof(arr)/sizeof(int);
	cout << maxGap(arr, len) << endl;

	return 0;
}