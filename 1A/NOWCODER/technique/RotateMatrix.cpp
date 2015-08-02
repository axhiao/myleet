#include <iostream>
#include <vector>

using namespace std;


void printMatrix(vector<vector<int> > &matrix)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void rotateEdgeOfMatrix(vector<vector<int> > &matrix, int tR, int tC, int dR, int dC)
{
	int times = dC - tC;
	for (int i = 0; i < times; i++)
	{
		int tmp = matrix[tR][tC+i];
		matrix[tR][tC+i] = matrix[dR-i][tC];
		matrix[dR-i][tC] = matrix[dR][dC-i];
		matrix[dR][dC-i] = matrix[tR+i][dC];
		matrix[tR+i][dC] =  tmp;
	}
}


void rotateMatrix(vector<vector<int> > &matrix)
{
	int tR = 0;
	int tC = 0;
	int dR = matrix.size()-1;
	int dC = matrix[0].size()-1;
	while (tR < dR)
	{
		rotateEdgeOfMatrix(matrix,tR++, tC++, dR--, dC--);
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
	printMatrix(matrix);

	rotateMatrix(matrix);

	cout << "==============" << endl;
	printMatrix(matrix);
	return 0;
}





