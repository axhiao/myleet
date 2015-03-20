#include <iostream>
#include <vector>

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

vector<vector<int> > subsets(vector<int> &s)
{
	vector<vector<int> > res;
	vector<int> emp;
	res.push_back(emp);
	int N = s.size();
	int i;
	for (i = 0; i < N; i++)
	{
		int size = res.size();
		int j;
		for (j = 0; j < size; j++)
		{
		        vector<int> v;
			int k;
			for (k = 0; k < res[j].size(); k++)
			{
				v.push_back(res[j][k]);
			}
			v.push_back(s[i]);
			res.push_back(v);
		}
	}
	return res;
}
int main()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(5);
	vec.push_back(3);
 	vector<vector<int> > r =  subsets(vec);
	int i;
	for (i = 0; i < r.size(); i++)
	{
		display(r[i]);
		cout<<endl;
	}
	return 0;
}
