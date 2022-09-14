#pragma once
#include<WinSock2.h>
#include<ws2tcpip.h>
#include<stdio.h>
#pragma comment(lib, "WS2_32")
#define boardSize 9
typedef struct LOCATION {
	int x;
	int y;
}location;

class Stone
{
public:
	location input;
	Stone();
	~Stone();
	bool addPiece(location input, bool client);
	void display(void);
	bool checkWin(bool client);
	void readInput(location* input, bool client);

private:
	char symobl[3];//set symbol for each other and void 
	int clientPiece;//record how many pieces the client has put
	int serverPiece;//record how many pieces the server has put
	location clientLocation[81];//record the exact location of the pieces
	location serverLocation[81];//record the exact location of the pieces
	char allPieces[boardSize * boardSize];
	bool pieceAvailability(location input);
	bool findStone(location targetLocation, location stoneLocation[], int index, int stoneSize);
	bool checkDiagonal(location tempLoca, location stoneLocation[], int i, int stoneSize);
	bool checkVertical(location tempLoca, location stoneLocation[], int i, int stoneSize);
	bool checkHorizontial(location tempLoca, location stoneLocation[], int i, int stoneSize);
};

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
	// char serverAddr[50];
	// void getServerIP(char* serverAddr);
public:
	SOCKET sockConn;
	Client(in_addr addr);
	~Client();
};

class castCli
{
    private:
        WORD mVersionRequested;
        WSADATA wsaData;
        int err;
        SOCKET s;
        SOCKADDR_IN mCast;
    public:
        castCli();
        ~castCli();
};
class castSer
{
    private:
        WORD mVersionRequested;
	    WSADATA wsaData;
	    int err;
        SOCKET s;
        SOCKADDR_IN sin;
        ip_mreq mcast;
        
        int nAddrLen;
        char buf[128];
    public:
        sockaddr_in addrfrom;
        castSer();
        ~castSer();
};

//network logic
void sendStone(SOCKET sockClient, location stoneLocation, bool win);// send input location to the other part
void recvStone(SOCKET sockClient, location* stoneLocation, bool *win);// rece input location from the other part

// supportive func
int compare1(const void* a, const void* b);

// game func
void playClient(void);
void playServer(void);