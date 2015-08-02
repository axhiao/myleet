#include <iostream>
#include <cstdio>
using namespace std;

void printProcess(int i, int N, bool down)
{
	if (i > N)
		return;
	printProcess(i+1, N, true);
	printf("%s\n",down?"down":"up" );
	printProcess(i+1, N, false);
}


void printAllFolds(int N)
{
	printProcess(1, N, true);
}


int main()
{
	int N = 5;
	printAllFolds(N);
	return 0;
}