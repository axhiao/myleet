#include <iostream>
#include <vector>

using namespace std;

void onelap(vector<vector<int> > &matrix, int tR, int tC, int dR, int dC);
void spiralPrint(vector<vector<int> > & matrix)
{
	int tR = 0;
	int tC = 0;
	int dR = matrix.size() - 1;
	int dC = matrix[0].size() - 1;
	while (tR <= dR && tC <= dC)
	{
		onelap(matrix, tR++, tC++, dR--, dC--);
	}
}
void onelap(vector<vector<int> > &matrix, int tR, int tC, int dR, int dC)
{
	if (tR == dR)// only one row left, just printing this row is okay.
	{
		for (int i = tC; i <= dC; i++)
		{
			cout << matrix[tR][i] << " ";
		}
	}
	else if (tC == dC)// only one column left, just printing this column is ok
	{
		for (int i = tR; i <= dR; i++)
			cout << matrix[i][tC] << " ";
	}
	else// commmon sense
	{
		int curRow = tR;
		int curCol = tC;
		while (curCol < dC)
		{
			cout << matrix[tR][curCol] << " ";
			curCol++;
		}
		while (curRow < dR)
		{
			cout << matrix[curRow][dC] << " ";
			curRow++;
		}
		while (curCol > tC)
		{
			cout << matrix[dR][curCol] << " ";
			curCol--;
		}
		while (curRow > tR)
		{
			cout << matrix[curRow][tC] << " ";
			curRow--;
		}
	}
}
int main()
{
	int row = 3;
	int col = 4;
	vector<vector<int> > matrix(row);
	int t1[] = {1, 2, 3, 4};
	int t2[] = {5, 6, 7, 8};
	int t3[] = {9, 10, 11, 12};
	//int t4[] = {13, 14, 15, 16};
	matrix[0].assign(t1, t1+col);
	matrix[1].assign(t2, t2+col);
	matrix[2].assign(t3, t3+col);
	//matrix[3].assign(t4, t4+col);
	

	spiralPrint(matrix);

	
	return 0;
}