#include"C:\Users\xkzmx\Documents\Code\C\NetworkEngineering\midTerm\gomoku\gameClient\gomoku.h"
#include<stdio.h>
#include <stdlib.h>

int main()
{
	Client cli;
	location stone = { 1,2 };
	bool winStatus = true;
	sendStone(cli.sockConn, stone, winStatus);
	recvStone(cli.sockConn, &stone, &winStatus);
	printf("%d\n%d\n%d", stone.x, stone.y, winStatus);
	return 0;
}
