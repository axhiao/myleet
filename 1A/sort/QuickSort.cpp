#include <iostream>

using namespace std;


void swap(int arr[], int l, int r)
{
	int tmp;
	tmp = arr[l];
	arr[l] = arr[r];
	arr[r] = tmp; 
}
int partition(int arr[], int left, int right, int pivot)
{
	int l = left -1;
	int r = right;
    /*
       example: 
       let 6 to be the pivot.
       (1) At the beginning:
       3 4 6 1 7 8 6
      l            r
        
       (2) After the first while loop:
       3 4 6 1 7 8 6 
           l r  
       (3) swap them, then continue to move i and j:
       3 4 1 6 7 8 6 
           l r                 
       (3) swap them, then continue to move i and j:
       3 4 1 6 7 8 6 
             l     pivot
             r
       (4) swap the left and the pivot.
       3 4 1 6 7 8 6 
             l     pivot           
    */
	while(1)
	{
	    // Find the first element which does not fulfill the rule
	    // It will not move out of range because the right node is pivot.
	    // 使用< 很重要，这样可以避免l跑到pivot的位置，就是right的位置
	    //while (l < r && arr[++l] <= pivot);
	    //for example, partition [3 4 6 1 7 8 6]
		while(arr[++l] < pivot);

	    // Find the first element which does not fulfill the rule
	    // Don't need to move r to be left of LEFT.	    
	    // use >= to keep elements >= pivot in the right.
	    // r>l assure that, for example, [7,3,6,1] correct 
	    // when l points to 7 and r to 1
		while(r>l && arr[--r] >= pivot);
		// If r <= l, means that all the elements is in the right place.
		if(r<=l)
			break;
		swap(arr,l,r);
	}
	swap(arr,l,right);
	return l;
}
// partition from Introduction to Algorithms
int partition2ITA(int arr[], int left, int right, int pivot)
{
	int i = left - 1;
	for (int j = left; j < right; ++j)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr,i,j);
		}
	}
	swap(arr,i+1,right);
	return i+1;
}
void quickSort(int arr[],int left,int right)
{
	if(arr == NULL || left >= right )
		return ;
	//set the right node to be pivot.
	int mp = partition2ITA(arr, left, right, arr[right]);
	quickSort(arr, left, mp-1);
	quickSort(arr, mp+1, right);
}

int main()
{
	int arr[]={3,4,6,1,7,8,6};
	quickSort(arr,0,6);
	for (int i = 0; i < 7; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
/*
   快速排序的性能分析：
   1.最坏情况下，每次划分产生的子问题分别包含n-1和0个元素，递归式T(n)=T(n-1)+O(n)   T(n)=O(n^2)
   2.最好情况下，每次划分产生n/2数目的子问题，T(n)=2T(n/2)+O(n)    T(n)=O(n*logn)
   3.即使　T(n)=T(9n/10)+T(n/10)+cn   still:  T(n)=O(n*logn)
 */


