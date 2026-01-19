#include <string.h>
#include <stdio.h>

void varcount()
{
	static int datavar = 0;
	int stackvar;

	datavar++;
	stackvar++;

	printf("Data segment variable: %d\n", datavar);
	printf("Stack variable: %d\n\n", stackvar);
}


int main()
{
	for (int i=0; i < 3; i++)
	{
		varcount();
	}

	return 0;
}