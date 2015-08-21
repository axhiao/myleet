#include <iostream>
#include <string>

using namespace std;

/***************************************************************

***        dp[i][j]的含义是,在必须把str1[i]和str2[j]当做公        ***   
***        共子子串最后一一个字符的情况下,公共子子串最长能有多长       ***

****************************************************************/

// space: O(mn)
int** getdp(string& str1, string& str2)
{
	int m = str1.length();
	int n = str2.length();
	int** dp = new int*[m];
	for (int i = 0; i < m; i++)
		dp[i] = new int[n];
	// dp[i][0] and dp[0][j]
	for (int i = 0; i < m; i++)
	{
		if (str1[i] == str2[0])
			dp[i][0] = 1;
		else
			dp[i][0] = 0;
	}
	for (int j = 1; j < n; j++)
	{
		if (str1[0] == str2[j])
			dp[0][j] = 1;
		else
			dp[0][j] = 0;
	}
	// dp[i][j]
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (str1[i] == str2[j])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = 0;
		}
	}
	return dp;
}

string getLCStr(string& str1, string& str2)
{
	int m = str1.length();
	int n = str2.length();
	if (m == 0 || n == 0)
		return string("");
	int** dp = getdp(str1, str2);
	int max = -1;
	int index = -1;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dp[i][j] > max)
			{
				max = dp[i][j];
				index = i;
			}
		}
	}
	delete[] dp;
	return str1.substr(index-max+1, max);
}

// space: O(1)

string getLCStr2(string& str1, string& str2)
{
	
}

int main()
{
	string str1("abcde");
	string str2("bebcd");
	string res = getLCStr(str1, str2);
	cout << res << endl;
	return 0;
}	