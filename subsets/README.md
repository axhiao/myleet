 Author:     Minglei Yin, axhiao@gmail.com
 Date:       Mar 30, 2015
 Update:     Mar 30, 2015
 Problem:    Subsets
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_78
 Notes:
 Given a set of distinct integers, S, return all possible subsets.
 Note:
 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 For example,
 If S = [1,2,3], a solution is:
 [
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
 ]
 Solution: 
1. Recursive solution.
2. Iterative solution
3.Binary solution


In addition, this problem might have another form. 
__Notes:__
 Given a collection of integers that might contain __duplicates__, S, return all possible subsets.

Solution:
1. Recursive solution
2. Iterative solution 


__注意:__
	                
此题的recursive解法可以作为排列组合问题的模板，使用范围：


* 几乎所有的搜索问题
   根据具体题目要求进行改动
* 什么时候输出（保存）
* 哪些情况需要跳过