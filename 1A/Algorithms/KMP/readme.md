
```C++
vector<int> getNext(const string& match)
{
	vector<int> next(match.size());
	next[0] = -1;
	next[1] = 0;
	int pos = 2;
	int cn = 0;
	while (pos < match.size())
	{
		if (match[pos - 1] == match[cn] )
		{
			next[pos++] = ++cn; 
		}
		else if ( cn > 0)
		{
			cn = next[cn];
		}
		else
		{
			next[pos++] = 0;
		}
	}
	return next;
}
```

求解next数组复杂度的分析:

在求解next数组的时候,通过观察两个变量pos和cn发现在循环的过程中,pos并不会减少,cn的增长时伴随pos的增加而增加的,但这并不是绝对的,因为有第3个else分支.所以cn最后的迭代总量不会超过pos的迭代总量.假设match串的长度为m,则cn至多增加m-2次.cn在第二个分支会减少,但是不会变为负的,总共减少的量也不会超过m-2.所以next数组的计算总的迭代量不会超过2*(m-2).因此时间复杂度为O(m)


```C++
int KMPsearch(const string& str, const string& match)
{
	vector<int> next = getNext(match);
	int slen = str.size();
	int mlen = match.size();
	int i = 0;
	int j = 0;
	while (i < slen && j < mlen)
	{
		if (j == -1 || str[i] == match[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	return j == mlen ? i-j : -1;
}
```
对KMP整体复杂度的分析也是类似的:

i,j是同步增加的,最多增加n次,j有回退,但是最多的回退不会比其增加的还多.所以整体的迭代量不会超过2n,时间复杂度为O(n)(不包括生成next的时间)


