# 顺序统计量

通俗的理解，就是在一个给定的集合中，寻找第k大(小)的量

相关问题总结：

* 数组中出现次数超过一半的数字
* 无序数组中第K大
* 寻找中位数(k= n/2)
* 无序数组中最小的k个数


## 数组中出现次数超过一半的数字

1. 利用partition找到某一次pivot的下标位于中位数的位置
2. 立候选的方法

## 无序数组中第K大

1. 利用quick sort中的partition

	* 随机选择一个支点pivot
	* 做一次partition，比pivot大的放在左边，比pivot小的放在右边(因为我们是找第k大，所以这么处理)
	* 设左边长度为L,
	   *  当 K < L,递归在左边找第K大的数
	   *  当 K > L,递归在右边找第(K-L)大的数
	   *  当 K = L,返回支点，该支点就是要找的第K大的数


	利用该算法最终时间复杂度接近 O(n)

2. 利用最大堆

	将数组建成一个最大堆，然后pop堆顶最大元素k次就可以

	但是，该算法复杂度为O(nlogn)


## 寻找中位数

首先，算法给定的参数是寻找第 i 大元素(第i小还是第i大,关键就在partition过程,参看__说明__)，设i = (n+1)/2,则第i大元素即为中位数.

* RANDOMIZED-SELECT(A, p, r, i)
* 1 if p == r
* 2    return A[p]
* 3 q = RANDOMIZED-PARTITION(A, p, r)
* 4 k = q - p + 1
* 5 if i == k
* 6     return A[q]
* 7 else if i<k
* 8     return RANDOMIZED-SELECT(A, p, q-1, i)
* 9 else return RANDOMIZED-SELECT(A, q+1, r, i-k)


**说明**： 

1. partition过程，如果是寻找第 k 最小，则 A[left]<=pivot, A[right]>pivot;如果是寻找第 k 最大，则A[left]>=pivot, A[right]<pivot.
2. 由于以区间长度为参考,所以当数组中的元素不是互异的时候,可能出现第i大和第i+1大为同一个数字.

## 无序数组中最小的k个数

1. 利用排序 O(nlogn)
2. 利用堆或者红黑树构造的数据结构如multiset. O(nlogk)，此方法比较适合大数据处理，可以依次读入数据并及时处理
3. bfprt算法，O(n). 算法导论9.3节

**注意**:以上利用partition过程的方法,都会改动原来的数组中内容的相对顺序.所以这一点应该注意





