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

	/*
	for (int curr = 0; curr < max; curr++)
	{
		int num  = 0;
		while(counting_array[curr] > 0)
		{

		}
	}*/

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