#include"gomoku.h"
#include<stdio.h>
int main()
{
	printf("What role do you want to play?\n1 for server\n2 for client\n");
	int choice;
	scanf("%d", &choice);
	system("cls");
	switch (choice)
	{
	case 1:

		playServer();
		break;
	case 2:
		playClient();
		break;
	default:
		printf("Wrong input");
		break;
	}
	printf("PRESS ANY KEY TO EXIT");
	getchar();
	return 0;
}
