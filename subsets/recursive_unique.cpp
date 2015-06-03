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

void subsethelper(vector<vector<int> > &result, vector<int> &list,vector<int> nums, int pos)
{
	//result.push_back(vector<int> tmp(list));
	result.push_back(list);
	int i;
	for (i = pos; i < nums.size(); i++)
	{
		if (i != pos && nums[i] == nums[i-1])
		{
			continue;
		}
		list.push_back(nums[i]);
		subsethelper(result,list,nums,i+1);
		list.erase(list.begin()+list.size()-1);
	}
}


vector<vector<int> >  subsets(vector<int> nums)
{
   sort(nums.begin(),nums.end());
   vector<vector<int> > result;
   vector<int> list;
   subsethelper(result,list,nums,0);
   return result;
}


int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
        sort(nums.begin(),nums.end());
	vector<vector<int> > result =   subsets(nums);
	for (vector<vector<int> >::const_iterator iter = result.begin(); iter != result.end(); iter++)
	{
		display(*iter);
	}
	return 0;
}

