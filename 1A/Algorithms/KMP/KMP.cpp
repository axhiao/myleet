#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using namespace std;


vector<int> getNext(const string& match);
int KMPsearch(const string& str, const string& match);

int main()
{
	string str("bcabcdababcdabcdabde");
	string match("bcd");
	cout << KMPsearch(str, match) << endl;

	return 0;
}


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