#pragma once
#include<WinSock2.h>
#include<stdio.h>
#define boardSize 9
typedef struct LOCATION {
	int x;
	int y;
}location;
typedef struct Gomoku {
	//int size;//set board size
	char symobl[3];//set symbol for each other and void 
	int clientPiece;//record how many pieces the client has put
	int serverPiece;//record how many pieces the server has put
	location clientLocation[81];//record the exact location of the pieces
	location serverLocation[81];//record the exact location of the pieces
	char allPieces[boardSize * boardSize];
}gomoku;
class Server
{
private:
	WORD mVersionRequested;
	WSADATA	wsaData;
	SOCKADDR_IN addrClient;
	SOCKADDR_IN addrSrv;
	SOCKET sockSrv;
	int len;
public:
	SOCKET sockConn;
	Server();
	~Server();
};

class Client
{
private:
	WORD mVersionRequested;
	WSADATA wsaData;
	SOCKADDR_IN addrSrv;
	char serverAddr[50];
public:
	SOCKET sockConn;

	Client();
	~Client();
};
// game logic
void initGame(gomoku* current);
void addPiece(location input, gomoku* current, bool client);// add a piece to the current gomoku
bool pieceAvailability(location input, gomoku* current); // check if the location have piece or not
int compare1(const void* a, const void* b);
void display(gomoku* current);// display the current gomoku board

bool checkWin(gomoku* current, bool client);// check after input did you win
bool checkHorizontial(location tempLoca, location stoneLocation[], int i, int stoneSize);
bool checkVertical(location tempLoca, location stoneLocation[], int i, int stoneSize);
bool checkDiagonal(location tempLoca, location stoneLocation[], int i, int stoneSize);
bool findStone(location targetLocation, location stoneLocation[], int index, int stoneSize);

//network logic
void getServerIP(char* serverAddr);

void sendStone(SOCKET sockClient, location stoneLocation, bool win);// send input location to the other part
void recvStone(SOCKET sockClient, location* stoneLocation, bool *win);// rece input location from the other part

//void sendMove(location input, bool win);
//void recvMove(location* input, bool* win);