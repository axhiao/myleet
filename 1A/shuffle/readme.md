## 随机算法


```
for i = 1 to n
	randomly select a card j from [1,i]
	swap card i with card j
```

**说明该算法可以保证每张牌在每个位置等概率的出现**

* 1. 如果可以申请额外空间，只需要做一次无放回的随机抽样就可以
* 2. 现在，不开辟新的存储空间。第一次被选中的元素就要放入这个数组的第一个位置，但这个位置原来已经有别的（也可能就是这个）元素了，这时候只要把原来的元素跟被选中的元素互换一下就可以了。很容易就避免了辅助空间。


来计算一下概率。如果某个元素被放入第i（1 ≤ i ≤ n ）个位置，就必须是在前i - 1次选取中都没有选到它，并且第i次选取是恰好选中它。其概率为：

pi = (n-1)/n × (n-2)/(n-1) ... (n-i+1)/(n-i+2) × 1/(n-i+1) = 1/n