#include <iostream>
#include <vector>
#include <map>

using namespace std;

int printHalfMajor(int arr[], int len, int &res)
{
	int resFlag = -1;// -1 means no such number 
			         // 0 means existence
	int cand = 0; 
	int times = 0;
	for (int i = 0; i < len; i++)
	{
		if (0 == times)
		{
			cand = arr[i];
			times = 1;
		}
		else if(cand == arr[i])
		{
			times++;
		}
		else
		{
			times--;
		}
	}
	// verify the existence
	times = 0;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == cand)
			times++;
	}
	if (times > len / 2)
	{
		res = cand;
		return 0;
	}
	else 
		return -1;
}
void allCandsMinus(map<int, int> &cands);
void printKMajor(int arr[], int len, int k)// k means len/k
{
	map<int, int> cands;
	for (int i = 0; i < len; i++)
	{
		if (cands.count(arr[i]) == 1)
		{
			cands[arr[i]]++;
		}
		else
		{
			if (cands.size() == k-1)
			{
				allCandsMinus(cands);
			}
			else
			{
				cands[arr[i]] = 1;
			}
		}
	}
	// verify
	map<int, int> verify;
	for (int i = 0; i < len; i++)
	{
		int curNum = arr[i];
		if (cands.count(curNum) == 1)
		{
			if (verify.count(curNum) == 1)
				verify[curNum]++;
			else
				verify[curNum] = 1;
		}
	}
	bool hasNumber = false;
	for (map<int, int>::iterator iter = verify.begin(); iter != verify.end(); iter++)
	{
		//cout << "** " << iter->first << " " << iter->second << endl;
		if (iter->second > len/k)
		{
			hasNumber = true;
			cout << iter->first << " ";
		}
	}
	if (!hasNumber)
		cout << "nu such numbers meeting the conditions" << endl;

	cout << endl;
}
void allCandsMinus(map<int, int> &cands)
{
	vector<int> removeSet;
	for (map<int, int>::iterator iter = cands.begin(); iter != cands.end(); iter++)
	{
		if (iter->second == 1)
			removeSet.push_back(iter->first);
		
		(iter->second)--;
	}
	for (int i = 0; i < removeSet.size(); i++)
		cands.erase(removeSet[i]);
	removeSet.clear();
}

int main()
{
	int arr[] = {1, 2, 3, 1, 1, 2, 1 };
	int res;
    int resFlag = printHalfMajor(arr, sizeof(arr)/sizeof(int), res);
    if(-1 == resFlag)
    	cout << "no such figure" << endl;
    else
    	cout << res << endl;

    //** the number of show-up of some element in the array is more than n/k
    //** print all of the elements meeting the conditions above.
    int K = 4;
    printKMajor(arr, sizeof(arr)/sizeof(int), K);
}