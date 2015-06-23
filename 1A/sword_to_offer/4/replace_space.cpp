#include <iostream>
#include <stdio.h>

using namespace std;

void replaceBlank(char str[], int size)
{
	if (str == NULL || size <= 0)
		return ;
	int lenOrig = 0;
	int lenBlank = 0;
	int i = 0;
	while(str[i] != '\0')
	{
		lenOrig++;
		if (str[i] == ' ')
			lenBlank++;
		i++;
	}
	int lenNew = lenOrig + lenBlank * 2;
	if (lenNew > size)
		return ;
	while (lenOrig >= 0 && lenNew > lenOrig)
	{
		if (str[lenOrig] == ' ')
		{
			str[lenNew--] = '0';
			str[lenNew--] = '2';
			str[lenNew--] = '%';
		}
		else
		{
			str[lenNew--] = str[lenOrig];
		}
		--lenOrig;
	}
}

int main()
{
	//char s[50] = "we are happpy.";
	char s[50] = " weare happy ";
	replaceBlank(s, 50);
	printf("\n%s\n", s);
	return 0;
}