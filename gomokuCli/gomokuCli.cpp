#include"C:\Users\xkzmx\Documents\Code\C\NetworkEngineering\midTerm\gomoku\gameClient\gomoku.h"
#include<stdio.h>
#include <stdlib.h>

int main()
{
	printf("What role do you want to play?\n 1 for server\n2 for client");
	int choice;
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		playServer();
	case 2:
		playClient();
	default:
		break;
	}
	return 0;
}
