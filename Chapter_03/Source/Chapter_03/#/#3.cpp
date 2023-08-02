#include <stdio.h>

int main()
{
	for (int i = 0;i < 100;  i++)
	{
		int** leak = new int*[500];
	}
}


