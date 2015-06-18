#include <iostream>

using namespace std;

// interfaces
class HeapSort
{
public:
	HeapSort();
	HeapSort(int* pdata,size_t hsize, size_t len);
	~HeapSort();
	void printarr();	
	void _max_heapify(int i);
	void _build_max_heap();
	void _heapsort();
private:
	int heapsize;
	int length;
	int* data;
};
// implementation
HeapSort::HeapSort():heapsize(0),length(0),data(0)
{}

HeapSort::HeapSort(int* pdata, size_t hsize, size_t len):heapsize(hsize),length(len),data(pdata)
{}

HeapSort::~HeapSort()
{
	delete[] data;
}
void HeapSort::printarr()
{
	for (int i = 0;	i < length; ++i)
	{
			cout << data[i] << " ";
	}
	cout << endl;
}

void HeapSort::_max_heapify(int i)
{
	int left_child = 2*i+1;
	int right_child = 2*i+2;
	int largest = i;
	if (left_child < heapsize && data[left_child] > data[i])
	{
		largest = left_child;
	}
	if (right_child < heapsize && data[right_child] > data[largest])
	{
		largest = right_child;
	}
	if (i != largest)
	{
		std::swap(data[i], data[largest]);
		_max_heapify(largest);
	}
}

void HeapSort::_build_max_heap()
{
	heapsize = length;
	for (int i = (heapsize / 2 -1); i >= 0 ; --i)
	{
		_max_heapify(i);
	}
}
void HeapSort::_heapsort()
{
	_build_max_heap();
	for (int i = length-1; i >= 0 ; --i)
	{
		using std::swap;
		std::swap(data[0], data[i]);
		heapsize--;
		_max_heapify(0);
	}
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

// procedure functions
///堆性质的维护, 对节点i做维护操作。前提假设：i节点以下已经满足最大堆的性质
void max_heapify(int arr[], int i, int heapsize)
{
	// begin with 0 index.
	int left_child = 2*i+1;
	int right_child = 2*i+2;
	int largest = i;
	if (left_child < heapsize && arr[left_child] > arr[i])
	{
		largest = left_child;
	}
	if (right_child < heapsize && arr[right_child] > arr[largest])
	{
		largest = right_child;
	}
	if (i != largest)
	{
		std::swap(arr[i], arr[largest]);
		max_heapify(arr, largest, heapsize);
	}
}

void min_heapify(int arr[], int i, int heapsize)
{
	int left_child = 2*i+1;
	int right_child = 2*i+2;
	int least = i;
	if(left_child < heapsize && arr[left_child] < arr[i])
	{
		least = left_child;
	}
    if (right_child < heapsize && arr[right_child] < arr[least])
    {
    	least = right_child;
    }

    if (least != i)
    {
	   	std::swap(arr[i], arr[least]);
    	min_heapify(arr, least, heapsize);
    }

}
///建堆，时间复杂度为O(n)
///当用数组表示存储n个元素的堆时， 叶节点的下标应该表示为： (n/2 表示n/2向下取整)
/// begin with 1: n/2+1, n/2+2, ...
/// begin with 0: n/2, n/2+1, ...
void build_max_heap(int arr[], int heapsize)
{
	for (int i = (heapsize / 2 -1); i >= 0 ; --i)
	{
		max_heapify(arr, i, heapsize);
	}
}
void build_min_heap(int arr[], int heapsize)
{
	for (int i = heapsize/2 -1; i >= 0; --i)
	{
		min_heapify(arr, i, heapsize);
	}
}

void heapsort(int arr[], int heapsize)
{
	//build_min_heap(arr, heapsize);
	build_max_heap(arr, heapsize);
	for (int i = heapsize-1; i >= 1; --i)
	{
		std::swap(arr[0], arr[i]);
		//min_heapify(arr, 0, i);
		max_heapify(arr, 0, i); // i: heapsize - 1
	}
}


int main()
{
	const int FULL_SIZE = 10;
	const int HEAP_SIZE = 10;
	int* arr = new int[HEAP_SIZE];
	arr[0] = 16;
	arr[1] = 4;
	arr[2] = 10;
	arr[3] = 14;
	arr[4] = 7;
	arr[5] = 9;
	arr[6] = 3;
	arr[7] = 2;
	arr[8] = 8;
	arr[9] = 1;
	//HeapSort hs(arr, HEAP_SIZE, FULL_SIZE);
    //hs._heapsort();
    //hs.printarr();
    heapsort(arr, HEAP_SIZE);

    for (int i = 0; i < HEAP_SIZE; ++i)
    {
    	cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;

	return 0;
}
/*
   1.　若节点从１开始计数，则parent(i)=i/2, left(i)=2*i, right(i)=2*i+1,
     　叶节点下标为 n/2+1,n/2+2,...,n
   2. 若节点从０开始计数，则parent(i)=(i-1)/2, left(i)=2*i+1, right(i)=2*i+2
      叶节点下标为 n/2,n/2+1,...,n
   3. n个元素的堆高是 floor(lgn)
   4. max_heapify的时间复杂度为O(h)
   5. 由大到小排序时候，要构建一个最小堆，然后建堆和排序时候用到最小堆．
   6. heap sort: time complexity = O(n*lgn)
*/