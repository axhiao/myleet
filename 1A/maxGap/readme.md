## 数组排序之后相邻的最大差值

+ __题目__：

给定一个整型数组arr,返回__如果__排序之后，相邻两数的最大差值。

例如：

arr=[9, 3, 1, 10],如果排序，结果为[1, 3, 9, 10]，９和３的差为最大差值，故返回６

arr=[5, 5, 5, 5], 返回０

+ 要求：

如果arr长度为N,时间复杂度为O(N).

+ 思路：本题如果用排序来做，时间复杂度为O(N*logN)，而如果利用桶排序的思想，可以做到时间复杂度O(N),额外空间复杂度O(N)。

1. 遍历arr找到最小值和最大值，分别记为min和max.
2. 如果arr的长度为N,那么我们准备__N+1__个桶，把max单独放在第N+1号桶中。arr中在[min,max)范围上的数放在１~N号桶里，对于１~N号桶中的每个桶来说，每个桶的容量为(max-min)/N。所以，如果一个数为num，它应该被分进的桶号为(num-min)*len/(max-min)
3. arr一共有N个数，min一定在1号桶中，max一定在最后的那个桶中，所以如果把所有的数放在N+1个桶中，必然有桶是空的。在同一个桶中的任意两个数的差值不会超过桶的区间容量。而在空桶左右两边不空的桶里，相邻数的差值肯定大于区间值。所以产生最大差值的两个相邻数肯定来自不同的桶。所以只要计算桶间的间距就可以了，也就是只需要记录每个桶区间上的最小值与最大值就可以。最大差值只可能来自某个__非空桶__的最小值减去前一个__非空桶__的最大值。
