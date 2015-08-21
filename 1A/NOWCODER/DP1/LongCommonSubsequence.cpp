#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/***************************************************************

***          dp[i][j]的含义是str1[0..i]与                      ***
***          str2[0..j]的最长公共子子序列的长度   	  		     ***

****************************************************************/
string LCSeq(string& str1, string& str2)
{
	int m = str1.length();
	int n = str2.length();
	if (m == 0 || n == 0)
		return string("");

	int** dp = new int*[m];
	for (int i = 0; i < m; i++)
		dp[i] = new int[n];
	// cope with dp[0][j] and dp[i][0]
	bool bf = false;
	for (int j = 0; j < n; j++)
	{
		if (str1[0] == str2[j] || bf)
		{
			dp[0][j] =  1;
			bf = true;
		}
		else
			dp[0][j] = 0;
	}
	bf = false;
	for (int i = 0; i < m; i++)
	{
		if (str2[0] ==  str1[i] || bf)
		{
			dp[i][0] = 1;
			bf = true;
		}
		else
			dp[i][0] = 0;
	}
	// deal with dp[i][j]
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (str1[i] == str2[j])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else
			{
				dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	int cnt = dp[m-1][n-1];
	string res(cnt,'*');
	int i = m - 1;
	int j = n - 1;
	
	while( cnt > 0)
	{
		//cout << "dp[i][j]: "<< i << " " << j << " " << dp[i][j] << endl;
		if (i > 0 && dp[i][j] ==  dp[i-1][j])
			i--;
		else if (j > 0 && dp[i][j] == dp[i][j-1])
			j--;
		else
		{
			res[--cnt]  = str1[i];
			i--;
			j--;
		}
	}
	// free memory
	for (int i = 0; i < m; i++)
		delete[] dp[i];
	delete[] dp;
	return res;
}





int main ()
{
	string str1 = "WA";
	string str2 = "YZWA";
	string res = LCSeq(str1, str2);

	cout << res << endl;
	return 0;
}