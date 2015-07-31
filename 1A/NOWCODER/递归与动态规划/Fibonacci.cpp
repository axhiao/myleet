#include <iostream>
#include <vector>

using namespace std;

// force resursion
// O(2^n)-method
int fib1(int n)
{
	if (n < 1)
		return 0;
	if (1 == n || 2 == n)
		return 1;

	return fib1(n-1)+fib1(n-2);
}
// O(n)-method
int fib2(int n)
{
	if (n < 1)
	{
		return 0;
	}
	if (1 == n || 2 == n)
	{
		return 1;
	}
	int res;
	int r1 = 1;
	int r2 = 1;
	for (int i = 3; i <= n; i++)
	{
		res = r1 + r2;
		r1 = r2;
		r2 = res;
	}
	return res;
}

//** O(logn)-method ****

void muliMatrix(vector<vector<int> > &arr1, vector<vector<int> > &arr2, vector<vector<int> > &res)
{
	// res = arr1 * arr2;
	vector<vector<int> > tmp(arr1.size(), vector<int>(arr2.size(),0));
	for (int i = 0; i < arr1[0].size(); i++) // row * col
	{
		for (int j = 0; j < arr2.size(); j++)
		{
			for (int k = 0; k < arr1.size(); k++)
				tmp[i][j] += arr1[i][k] * arr2[k][j]; 
		}
	}
	tmp.swap(res);
}
void matrixPower(vector<vector<int> > &m, int p, vector<vector<int> > &res)
{
	vector<vector<int> > t(m.begin(), m.end());
	vector<vector<int> > r(m.size(), vector<int>(m.size(), 0));
	// 将r设为单位矩阵E
	for (int i = 0; i < m.size(); i++)
	{
		r[i][i] = 1;
	}
	while(p)
	{
		if (1 == (p & 1) )
		{
			muliMatrix(r, t, r); // r = r  * t
		}
		muliMatrix(t, t, t); // t = t * t
		p >>= 1;
	}
	t.clear();
	r.swap(res);
}
int fib3(int n)
{
	if (n < 1)
	{
		return 0;
	}
	if (1 == n || 2 == n)
	{
		return 1;
	}

	vector<vector<int> > base;
	vector<int> t1;
	t1.push_back(1);
	t1.push_back(1);
	vector<int> t2;
	t2.push_back(1);
	t2.push_back(0);
	base.push_back(t1);
	base.push_back(t2);
	vector<vector<int> > res;
	matrixPower(base, n-2, res);
	return 1 * res[0][0] + 1 * res[1][0];
}


int main()
{
	//cout << fib1(100) << endl;
	for (int i = -3; i < 15; i++)
	{
		cout << fib2(i) << " ";
	    cout << fib3(i) << endl;
	}

	return 0;
}
