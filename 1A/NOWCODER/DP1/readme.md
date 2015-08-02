1. 最长递增子序列
   **题目：**给定数组arr，返回arr的最长递增子序列.
   **要求：**如果arr长度为N，请实现时间复杂度为O(N*logN)的方法。 

2. 最长公共子序列问题
   **题目：**给定两个字符串str1和str2，返回两个字符串的最长公共子序列。
   **举例：**str1=“1A2C3D4B56”，str2=“B1D23CA45B6A”。“123456”或者“12C4B6”都是最长公共子序列，返回哪一个都行。

3. 最长公共子串问题
   **题目：**给定两个字符串str1和str2，返回两个字符串的最长公共子串。
   **举例：**str1=“1AB2345CD”，str2=“12345EF”。返回“2345”。
   **要求：**如果str1长度为M，str2长度为N，实现时间复杂度为O(M*N)，额外空间复杂度为O(1)的方法。 

4. 最小编辑代价
   **题目：**给定两个字符串str1和str2，再给定三个整数ic、dc和rc分别代表插入、删除和替换一个字符的代价，返回将str1编辑成str2的最小代价。
   **举例：**
   str1=“abc”，str2=“adc”，ic=5，dc=3，rc=2。
   从“abc”编辑成“adc”，把’b’替换成’d’是代价最小的。所以返回2。 
   str1=“abc”，str2=“adc”，ic=5，dc=3，rc=100。
   从“abc”编辑成“abd”，先删除’b’然后插入’d’是代价最小的。所以返回8。 
   str1=“abc”，str2=“abc”，ic=5，dc=3，rc=2。 
   不用编辑了，本来就是一样的字符串。所以返回0。 
5. 字符串的交错组成
   **题目：**给定三个字符串str1、str2和aim。如果aim包含且仅包含来自str1和str2的所有字符，而且在aim中属于str1的字符之间保持原来在str1中的顺序，属于str2的字符之间保持原来在str2中的顺序，那么称aim是str1和str2的交错组成。实现一个函数，判断aim是否是str1和str2交错组成。 

   **举例：**str1=“AB”，str2=“12”。那么“AB12”、“A1B2”、“A12B”、“1A2B”和“1AB2”等等都是str1和str2交错组成。 
   