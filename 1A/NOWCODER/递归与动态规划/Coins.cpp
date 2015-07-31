#include <iostream>

using namespace std;

// force recursion
// O(aim^N)
int process(int arr[], int len, int index, int aim);
int coins(int arr[], int N, int aim)
{
	if (aim < 0 || N <= 0 || arr == NULL)
		return 0;

	return process(arr, N, 0, aim);
}

int process(int arr[], int len, int index, int aim)
{
	int res = 0;
	if (index == len)
		res = aim == 0 ? 1 : 0;
	else
	{
		for (int i = 0; arr[index]*i <= aim; i++)
		{
			res += process(arr, len, index+1, aim - arr[index]*i);
		}
	}
	return res;
}
// memory table
// O(N*aim^2)
int process_map(int arr[], int len, int index, int aim, int** map)
{
	int res = 0;
	if (len == index)
	{
		res = aim == 0 ? 1 : 0;
	}
	else
	{
		int mapvalue = 0;
		for (int i = 0; arr[index]*i <= aim; i++)
		{
			mapvalue = map[index+1][aim - arr[index]*i];
			if (mapvalue != -1)
				res += mapvalue;
			else
				res += process_map(arr, len, index+1, aim - arr[index]*i, map);
		}
	}
	map[index][aim] = res;
	return res;
}
int coins_map(int arr[], int len, int aim)
{
	if (arr == NULL || len <= 0 || aim < 0)
		return 0;
	//generate memory table -- map
	// -1 indicates no value ever here
	// others mean the calculated values
	int** map = new int*[len + 1];
	for (int i = 0; i < len + 1; i++)
	{
		map[i] = new int[aim + 1];
	}
	for (int i = 0; i < len + 1; i++)
	{
		for (int j = 0; j < aim + 1; j++)
			map[i][j] = -1;
	}
	return process_map(arr, len, 0, aim, map);
}
// dp-version
// O(N*aim^2)
int coins_dp(int arr[], int len, int aim)
{
	if (arr == NULL || len <= 0 || aim < 0)
	{
		return 0;
	}
	//generate dp-table
	int ** dp = new int*[len];
	for (int i = 0; i < len; i++)
		dp[i] = new int[aim + 1];
	//0th-column assignment
	for (int i = 0; i < len; i++)
		dp[i][0] = 1;
	//0th-row assignment
	for (int j = 1; j < aim + 1; j++)
	{
		if (j % arr[0] == 0)
			dp[0][j] = 1;
		else 
			dp[0][j] = 0;
	}
	// calculate dp[i][j]  0<i<len   0<j<=aim
	for (int i = 1; i < len; i++)
	{
		for (int j = 1; j < aim+1; j++)
		{
			int num = 0;
			for (int k = 0; k*arr[i] <= j;k++)
				num += dp[i-1][j-k*arr[i]];
			dp[i][j] = num;
		}
	}
	return dp[len-1][aim];
}

// dp-version + optimisation:状态合并，进一步降低时间复杂度
// O(N*aim)
int coins_dp_opt(int arr[], int len, int aim)
{
	if (arr == NULL || len <= 0 || aim < 0)
	{
		return 0;
	}
	//generate dp-table
	int ** dp = new int*[len];
	for (int i = 0; i < len; i++)
		dp[i] = new int[aim + 1];
	//0th-column assignment
	for (int i = 0; i < len; i++)
		dp[i][0] = 1;
	//0th-row assignment
	for (int j = 1; j < aim + 1; j++)
	{
		if (j % arr[0] == 0)
			dp[0][j] = 1;
		else 
			dp[0][j] = 0;
	}
	// calculate dp[i][j]  0<i<len   0<j<=aim
	for (int i = 1; i < len; i++)
	{
		for (int j = 1; j < aim+1; j++)
		{
			dp[i][j] = dp[i-1][j];
			dp[i][j] += j - arr[i] >= 0 ? dp[i][j - arr[i]] : 0;
		}
	}
	return dp[len-1][aim];
}

int coins_dp_opt_space(int arr[], int len, int aim)
{
	if (arr == NULL || len <= 0 || aim < 0)
		return 0;
	//generate the dp array and initialize it.
	int* dp = new int[aim+1];
	for (int i = 0; i < aim + 1; i++)
	{
		if (i % arr[0] == 0)
			dp[i] = 1;
		else
			dp[i] = 0;
	}
	//  scroll the dp-array
	for (int i = 1; i < len; i++)
	{
		for (int j = 1; j < aim + 1; j++)
		{
			dp[j] += j - arr[i] >= 0 ? dp[j - arr[i]] : 0;
		}
	}
	int res = dp[aim];
	delete[] dp;
	return res;
}
int main()
{
	int arr[] = {5, 10, 25, 1};
	int aim = 150;

	cout << coins(arr, sizeof(arr)/sizeof(int), aim) << endl;
	cout << coins_map(arr, sizeof(arr)/sizeof(int), aim) << endl;
	cout << coins_dp(arr, sizeof(arr)/sizeof(int), aim) << endl;
	cout << coins_dp_opt(arr, sizeof(arr)/sizeof(int), aim) << endl;
	cout << coins_dp_opt_space(arr, sizeof(arr)/sizeof(int), aim) << endl;
	return 0;
}
