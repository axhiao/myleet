#include <iostream>
#include <string>
#include <tr1/memory>
#include <vector>
#include <stdexcept>
#include <cassert>

using namespace std;
using std::tr1::shared_ptr;

// 模拟系统资源类
class Resources
{
public:
	Resources():elemIndex(-1),datastr(""){}
	Resources(string str):elemIndex(-1), datastr(str){}
	~Resources(){}
    int getIndex(){return elemIndex;}
    void setIndex(int ind){elemIndex = ind;}
    void display(){cout << datastr << endl;}
private:
	int elemIndex;
	string datastr;
};


// elements in heap
class baseElem
{
public:
	baseElem(){}
	baseElem(Resources *pRes, int keyPriority):key(keyPriority),resptr(pRes){}
	baseElem(const baseElem &be):key(be.getKey()),resptr(be.getPointerToResource()){}
	~baseElem(){}
	void setKey(int keyPriority){key = keyPriority;}

	int getKey()const{return key;}
	std::tr1::shared_ptr<Resources> getPointerToResource()const{return resptr;}
private:
	int key;
	std::tr1::shared_ptr<Resources> resptr;
};

// priority heap queue
class HeapQueue
{
public:
	HeapQueue();
	HeapQueue(int hsize);
	~HeapQueue();
	// operating function
	void heap_increase_key(int i, int k);
    void max_heap_insert(Resources *res, int k);
    baseElem heap_maximum();
    void max_heapify(int kth);
    baseElem heap_extract_max();


    void print();
private:
	int heapsize;
	int length;
	vector<baseElem> heap_ones;	
};


/*   implementation of priority heap queue  */

HeapQueue::HeapQueue():heapsize(0),length(20)
{
}
HeapQueue::HeapQueue(int hsize):heapsize(0),length(hsize)
{
}
HeapQueue::~HeapQueue()
{
	heap_ones.clear();
}
void HeapQueue::print()
{
	for (int i = 0; i < heapsize; ++i)
	{
		cout << heap_ones[i].getKey() << "   ";
		heap_ones[i].getPointerToResource()->display();
	}
}
void HeapQueue::max_heapify(int kth)
{
	// heap_ones 中第 kth 个元素进行维护操作
	int left_child = 2*kth + 1;
	int right_child = 2*kth + 2;
	int largest = kth;
	if (left_child < heapsize && heap_ones[left_child].getKey() > heap_ones[kth].getKey())
	{
		largest = left_child;
	}
	if (right_child < heapsize && heap_ones[right_child].getKey() > heap_ones[largest].getKey())
	{
		largest = right_child;
	}
	if (kth != largest)
	{
		std::swap(heap_ones[kth], heap_ones[largest]);
		max_heapify(largest);
	}
}
baseElem HeapQueue::heap_extract_max()
{
	if (heapsize == 0)
		throw runtime_error("heap underflow");
	//baseElem be(heap_ones[0].getPointerToResource(), heap_ones[0].getKey());
	baseElem be(heap_ones[0]);
	assert (heap_ones.size() == heapsize);
	heap_ones[0] = heap_ones[heap_ones.size() - 1];
	heap_ones.pop_back();
	heapsize = heapsize - 1;
	max_heapify(0);
	return be;
}
baseElem HeapQueue::heap_maximum()
{
	if (heapsize > 0)
		return heap_ones[0];
}
void HeapQueue::heap_increase_key(int i, int k)
{
	if (heap_ones[i].getKey() < k)
		throw runtime_error("the added key should be larger than the orginial one.");
	heap_ones[i].setKey( k );

	while (i >=1 && heap_ones[(i-1)/2].getKey() < heap_ones[i].getKey())
	{
		std::swap(heap_ones[(i-1)/2], heap_ones[i]);
		heap_ones[(i-1)/2].getPointerToResource()->setIndex(i);
		heap_ones[i].getPointerToResource()->setIndex((i-1)/2);
		i = (i - 1 ) / 2;
	}
}


/**
*  res: system resource
*  k : priority level
*/
void HeapQueue::max_heap_insert(Resources *res, int k)
{

	if(heapsize == length) // should recollate memory
		throw runtime_error("room is run out of. need to reallocated!");

	// generate heap element	
	baseElem be(res, k);
 
	heap_ones.push_back(be);
	// insert generated element in the heap queue
    heap_increase_key(heapsize, k); 
    heapsize = heapsize + 1;        
}



//   main function   //
int main()
{
	Resources *r1 = new Resources("No.1 resource, hello world");
    Resources *r2 = new Resources("No.6 resource, my husband");
    Resources *r3 = new Resources("No.3 resource, miss bear.");
    Resources *r4 = new Resources("No.9 resource, Ethan Hunt");
    Resources *r5 = new Resources("No.8 resource, Caleb Rivers");
    Resources *r6 = new Resources("No.13 resource, Caleb Rivers");

    HeapQueue hq;
    hq.max_heap_insert(r1, 1);
    hq.max_heap_insert(r2, 6);
    hq.max_heap_insert(r3, 3);
    hq.max_heap_insert(r4, 9);
    hq.max_heap_insert(r5, 8);
    hq.max_heap_insert(r6, 13);
    hq.print();

    hq.heap_maximum().getPointerToResource()->display() ;
    hq.heap_extract_max().getPointerToResource()->display();

    cout << "-------------------" << endl;
    cout << " After pop max key: " << endl;
	hq.print();
    cout << "done !!!" << endl;
	return 0;
}