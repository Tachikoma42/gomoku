#include"C:\Users\xkzmx\Documents\Code\C\NetworkEngineering\midTerm\gomoku\gameClient\gomoku.h"
#include<stdio.h>
int main()
{
	
	Server ser;
	location stone;
	bool winStatus;
	recvStone(ser.sockConn, &stone, &winStatus);
	printf("%d\n%d\n%d", stone.x, stone.y, winStatus);
	stone = { 1,2 };
	sendStone(ser.sockConn, stone, winStatus);
	return 0;
}