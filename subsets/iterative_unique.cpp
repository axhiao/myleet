#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


template<typename T>
void display(T &input)
{
	for (typename T::const_iterator iter = input.begin(); iter != input.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

}
/*
 * 集合中会有重复的值。
 * 若s中有重复元素，可以先排序，遍历过程中如果发现当前元素s[i]和s[i-1]相同，那么不同于
 * 原有思路“将当前res中所有的子集copy一份并在末尾添加s[i]”的做法，只需要将res中 上一次
 * 添加进来的子集copy一份，末尾添加s[i]
 * 需要注意的是，此时要有一个记录上次新增子集位置的变量，用pos和cnt来表示，
 * cnt来记录本轮res中增加了多少元素，供下一轮使用。
 * pos = res.size() - cnt; 
 *****/
vector<vector<int> > subsets(vector<int> &s)
{
	vector<vector<int> > res;
	vector<int> emp;
	res.push_back(emp);
	int N = s.size();
	int i;
	int pos = 0;
	int cnt = 1;
	for (i = 0; i < N; i++)
	{
		pos = res.size()-cnt;
		int size = res.size();
		int j;
		if (i != 0 && s[i] != s[i-1])
		{
			pos = 0;
		}
		cnt = 0;
		for (j = pos; j < size; j++)
		{
		        vector<int> v;
			int k;
			for (k = 0; k < res[j].size(); k++)
			{
				v.push_back(res[j][k]);
			}
			v.push_back(s[i]);
			res.push_back(v);
			cnt++;
		}	
	}
	return res;
}
int main()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(2);
	vec.push_back(2);
	sort(vec.begin(),vec.end());
 	vector<vector<int> > r =  subsets(vec);
	int i;
	for (i = 0; i < r.size(); i++)
	{
		display(r[i]);
		cout<<endl;
	}
	return 0;
}

