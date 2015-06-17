## 顺序统计量

通俗的理解，就是在一个给定的集合中，寻找第k大(小)的量


## 在给定数组中找第k大

#### 利用quick sort中的partition

* 随机选择一个支点pivot
* 做一次partition，比pivot大的放在左边，比pivot小的放在右边(因为我们是找第k大，所以这么处理)
* 设左边长度为L,
   *  当 K < L,递归在左边找第K大的数
   *  当 K > L,递归在右边找第(K-L)大的数
   *  当 K = L,返回支点，该支点就是要找的第K大的数


利用该算法最终时间复杂度接近 O(n)

#### 利用最大堆

将数组建成一个最大堆，然后pop堆顶最大元素k次就可以

但是，该算法复杂度为O(nlogn)


## 寻找中位数

首先，算法给定的参数是寻找第 i 小元素，i = (n+1)/2 即是中位数

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


说明： partition过程，如果是寻找第 k 最小，则 A[left]<=pivot, A[right]>pivot;如果是寻找第 k 最大，则A[left]>=pivot, A[right]<pivot.





