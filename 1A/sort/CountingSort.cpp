#include <iostream>

using namespace std;


int maxElemOfArr(int arr[], int len)
{
	int max = -1;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

void countingsort(int arr[], int len)
{
	int max = maxElemOfArr(arr, len);
	int *counting_array = new int[max]();

	for (int i = 0; i < len; ++i)
	{
		counting_array[arr[i]]++;
	}

	int curr = 0;
	int num = 0;
	//注意：采用此种喜欢方式，counting sort为 不稳定 排序方式
	//     curr变量应该倒着遍历，并放置元素(as text of intro to algo does)，为稳定的排序
	while(curr < len)
	{
		while(counting_array[num] > 0)
		{
			arr[curr] = num;
			counting_array[num]--;
			curr++;
			if (curr >= len)
			{
				break;
			}
		}
		num++;	
	}
	delete[] counting_array;

}


int main()
{
	int arr[] = {3, 6, 7, 2, 8, 4, 5, 7, 3, 2, 4, 1, 2};
	int len = sizeof(arr) / sizeof(int);


	countingsort(arr, len);


	for(int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;


	return 0;
}