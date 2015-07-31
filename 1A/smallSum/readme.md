## 计算数组的小和

数组小和定义如下：

例如数组s=[1, 3, 5, 2, 4, 6], 在s[0]的左边小于等于s[0]的数的和为０，在s[1]的左边小于等于s[1]的数的和为１，在s[2]的左边小于等于s[2]的数的和为1+3=4,在s[3]的左边小于等于s[3]的数的和为１，s[4]的左边小于等于s[4]的和为1+3+2=6,s[5]的左边小于等于s[5]的和为1+3++5+2+4=15,所以s的小和=0+1+4+1+6+15=27


给定一个数组s，实现函数返回s的小和


传统解法时间复杂度__O(N^2)__, 按照题目的描述遍历即可。采用归并排序的思想可以做到__O(nlogn)__时间复杂度，额外空间复杂度为O(N).