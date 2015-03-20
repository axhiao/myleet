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
 *  依次检测每个二进制位，1为选，0位不选
 *
 *
 *
   ***/
vector<vector<int> > subsets(vector<int> &s)
{
	vector<vector<int> > res;
	sort(s.begin(),s.end());
	const size_t n = s.size();
	vector<int> v;
        size_t i, j;
	for (i = 0; i < 1 << n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i & 1 << j)
			{
				v.push_back(s[j]);
			}
		}
		res.push_back(v);
		v.clear();
	}
	return res;
}
int main()
{
	vector<int> ivec;
	ivec.push_back(1);
	ivec.push_back(2);
	ivec.push_back(3);
	vector<vector<int> > res = subsets(ivec);
	for (vector<vector<int> >::const_iterator iter = res.begin(); iter != res.end(); iter++)
	{
		display(*iter);
	}
	return 0;
}
