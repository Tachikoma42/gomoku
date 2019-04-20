#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct LOCATION {
	int x;
	int y;
}location;
int main()
{
	location input;
	char inLocation[3];
	scanf("%s", &inLocation);
	int in = atoi(inLocation);
	input.x = in / 10;
	input.y = in % 10;
	return 0;
}