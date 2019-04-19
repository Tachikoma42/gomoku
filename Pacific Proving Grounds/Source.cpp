#include<stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct LOCATION {
	int x;
	int y;
}location;
int main()
{
	char x[2];
	char y[2];
	location stoneLocation = { 1,2 };
	itoa(stoneLocation.x, x, 10);
	itoa(stoneLocation.y, y, 10);

	return 0;
}