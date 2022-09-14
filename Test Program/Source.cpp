#include<stdio.h>
int main()
{
	char inLocation[10];
	bool stoneAvail;
	int temp1;
	int temp2;

	printf("PLEASE INSERT A STONE\n");
	temp1 = getc(stdin) - 48;
	temp2 = getc(stdin) - 48;
	scanf("%s", &inLocation);

	return 0;
}