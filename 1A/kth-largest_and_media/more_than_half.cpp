#include <iostream>
#include <cassert>
#include <cstdlib> // rand()
#include <ctime>   // time()

using namespace std;



int moreThanHalf1(int arr[], int len);//立候选
int moreThanHalf2(int arr[], int len);//partition
bool checkArray(int arr[], int len, int ind);
int partition(int arr[], int p, int r);

int main()
{
	int arr[] = {2, 1, 3, 2, 2, 2, 4, 2, 6};
	int len = sizeof(arr) / sizeof(int);

	//cout << moreThanHalf1(arr, len) << endl;
	cout << moreThanHalf2(arr, len) << endl;


	return 0;
}

bool checkArray(int arr[], int len, int elem)
{
	int cnt = 0;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == elem)
			cnt++;
	}
	if (cnt > len / 2)
		return true;
	else
		return false;
}

int partition(int arr[], int p, int r)
{
	srand(time(0));
	int rd = p + rand() % (r - p + 1);
	std::swap(arr[rd], arr[r]);

	int pivot = arr[r];
	int k = p - 1;
	for (int i = p; i < r; i++)
	{
		if (arr[i] <= pivot)
		{
			k++;
			std::swap(arr[k], arr[i]);
		}
	}
	std::swap(arr[k+1], arr[r]);
	return k+1;
}

int moreThanHalf1(int arr[], int len)
{
	if (arr == NULL || len <= 0)
		return 0;

	int candidate = arr[0];
	int times = 1;

	for (int i = 1; i < len; i++)
	{
		if (times = 0)
		{
			candidate = arr[i];
			times = 1;
		}
		else if (arr[i] == candidate)
		{
			times++;
		}
		else
		{
			times--;
		}


	}
	if (checkArray(arr, len, candidate))
		return candidate;
	else
		return 0;
}

int moreThanHalf2(int arr[], int len)
{
	if (arr == NULL || len <= 0)
		return -1;

	int start = 0; 
	int end = len - 1;
	int middle = len / 2;

	int index = partition(arr, start, end);
	while (index != middle)
	{
		//cout << "************" << endl;
		if (index < middle)
		{
			start = index + 1;
			index = partition(arr, start, end);
		}
		else
		{
			end = index - 1;
			index = partition(arr, start, end);
		}
	}
	if (checkArray(arr, len, arr[middle]))
		return arr[middle];
	else
		return -1;
}