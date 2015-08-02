#include <iostream>
#include <vector>

using namespace std;



void printTiltedLevel(vector<vector<int> > &matrix, int tR, int tC, int dR, int dC, bool f);
void printMatrixZigZag(vector<vector<int> > &matrix)
{
	int tR = 0;
	int tC = 0;
	int dR = 0;
	int dC = 0;
	int endR = matrix.size() - 1;
	int endC = matrix[0].size() - 1;

	bool uptodown = false;
	while (tR != endR + 1)
	{
		printTiltedLevel(matrix, tR, tC, dR, dC, uptodown);
		tR = tC == endC ? tR + 1 : tR; // tR must be in front of tC
        tC = tC == endC ? tC : tC + 1;
        dC = dR == endR ? dC + 1 : dC; //
        dR = dR == endR ? dR : dR + 1;
        uptodown = !uptodown;
	}
}
void printTiltedLevel(vector<vector<int> > &matrix, int tR, int tC, int dR, int dC, bool f)
{
	if (f) // true -> up to down
	{
		while(tR != dR + 1)
			cout << matrix[tR++][tC--] << " ";
	}
	else // false -> down to up
	{
		while(dR != tR - 1)
			cout << matrix[dR--][dC++] << " ";
	}
}
int main()
{
	int row = 4;
	int col = 4;
	vector<vector<int> > matrix(row);
	int t1[] = {1, 2, 3, 4};
	int t2[] = {5, 6, 7, 8};
	int t3[] = {9, 10, 11, 12};
	int t4[] = {13, 14, 15, 16};
	matrix[0].assign(t1, t1+col);
	matrix[1].assign(t2, t2+col);
	matrix[2].assign(t3, t3+col);
	matrix[3].assign(t4, t4+col);

	printMatrixZigZag(matrix);
}