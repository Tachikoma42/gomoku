#include"gomoku.h"
#include<stdio.h>
int main()
{
	//gcc Precious.cpp gomoku.cpp gomoku.h -lws2_32 -o output

	printf("What role do you want to play?\n1 for server\n2 for client\n");
	int choice;
	scanf("%d", &choice);
	system("cls");
	switch (choice)
	{
	case 1:
		playServer(); // choose to be server
		break;
	case 2:
		playClient(); // choose to be server
		break;
	default:
		printf("Wrong input");
		break;
	}
	printf("PRESS ANY KEY TO EXIT");
	getchar();
	return 0;
}
