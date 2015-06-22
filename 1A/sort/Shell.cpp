#include <iostream>

using namespace std;



void shellsort(int arr[], int len)
{
	int n = len;
	int h = 1; // delta
	while (h >= 1)
	{
		for (int i = 1; i < len; i++)
		{
			for (int j = i; j >= h; j = j - h)
			{
				if (arr[j] < arr[j-h])
					std::swap(arr[j], arr[j-h]);
				else
					break;
			}
		}
		h = h / 3;
	}
}

int main()
{
	
	int arr[] = {3,67,2, 8, 45,3,32,4,12};
	int len = sizeof(arr) / sizeof(int);
	shellsort(arr, len);
	for(int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	
	return 0;
}

/*
shell 排序中的关键步骤在于步长递减序列的确定，任何可以递减至1的步长序列都可以，比较好用的是
Hibbard's 序列： 1, 3, 7, ...， 2^k-1
Knuth's 序列： 1, 4, 13, ... , (3^k - 1)/2 本程序中用的便是这个
已知最好的序列是 1, 5, 19, 41, 109,....
*/