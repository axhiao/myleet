#include <iostream>
#include <limits>

using namespace std;

void merge(int arr[], int p, int q, int r)
{
	int n1 = q - p + 1; // p,...,q
	int n2 = r - q;     // q+1,...,r

	int *arr1 = new int[n1+1];
	int *arr2 = new int[n2+1];

	for (int i = 0; i < n1; ++i)
	{
		arr1[i] = arr[p+i];
	}
	arr1[n1] = (numeric_limits<int>::max)();//sentinel

	for (int i = 0; i < n2; ++i)
	{
		arr2[i] = arr[q+i+1];
	}
	arr2[n2] = (numeric_limits<int>::max)();//sentinel

	int i=0, j=0;
	for(int k = p; k <= r; k++)
	{
		if (arr1[i] <= arr2[j])
		{
			arr[k] = arr1[i];
			i++;
		}
		else
		{
			arr[k] = arr2[j];
			j++;
		}
	}
}
void mergeSort(int arr[],int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		mergeSort(arr, p, q);
		mergeSort(arr, q+1, r);
		merge(arr, p, q, r);
	}
}

int main()
{
	
	int arr[] = {3,4,6,7,1,8,0};
	mergeSort(arr,0,6);
	for (int i = 0; i < 7; ++i)
	{
		cout << arr[i] << " " ;
	}
	cout << endl;
	return 0;
}
/*
   merge sort典型的运用分治法程序设计技巧：
   分解：　(p+r)/2
   解决：递归地排序两个子序列
   合并：合并两个已经排序好的子序列

   merge sort 分析：
   T(n) = 2T(n)+ cn    T(n) = theta(n*logn) 其实渐进紧确界．
*/