#include <iostream>
#include <cassert>


using namespace std;

void _8queen();
void permutation(int colIndex[], int len, int pos);
bool verifyPerm(int colIndex[], int len);

static int cnt2 = 0;

int main()
{
	_8queen();	
	cout << cnt2 << endl;
	return 0;
}

void _8queen()
{
	const int queensNum = 8;
	int colIndex[queensNum];

	for (int i = 0; i < queensNum; i++)
		colIndex[i] = i;

	  permutation(colIndex, queensNum, 0);
}


void permutation(int colIndex[], int len, int pos)
{
	if (colIndex == NULL)
		return;

	if (pos == len && verifyPerm(colIndex, len))
	{
		cnt2++;
		for (int i = 0; i < len; i++)
			cout << colIndex[i] << " ";
		cout << endl;
		return ;
	}

	for (int i = pos; i < len; i++)
	{
		std::swap(colIndex[pos], colIndex[i]);
		permutation(colIndex, len, pos + 1);
		std::swap(colIndex[pos], colIndex[i]);
	}
}


bool verifyPerm(int colIndex[], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (i-j == colIndex[i] - colIndex[j] || j - i == colIndex[i] - colIndex[j])
				return false;
		}
	}
	return true;
}