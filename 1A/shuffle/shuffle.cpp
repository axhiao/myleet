#include <iostream>
#include <cstdlib>// srand, rand
#include <ctime> // time

using namespace std;


void shuffle(int arr[], int len)
{
	srand(time(0));
	for (int i = 0; i < len; i++)
	{
		int j = rand()%(i+1);
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
}


int main()
{
	int arr[7] = {1,2,3,4,5,6,7};
	shuffle(arr, 7);
	for (int i = 0; i < 7; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}