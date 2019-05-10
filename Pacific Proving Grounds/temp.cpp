#include<stdlib.h>
#include<algorithm>
#include"gomoku.h"
#include<WinSock2.h>
#include<stdio.h>
#include<string>
#pragma comment(lib, "WS2_32")
#include<WinSock2.h>
#include<ws2tcpip.h>
#include<stdio.h>
#pragma comment(lib, "WS2_32")

class Client
{
private:
	WORD mVersionRequested;
	WSADATA wsaData;
	SOCKADDR_IN addrSrv;
	char serverAddr[50];
	void getServerIP(char* serverAddr);
public:
	SOCKET sockConn;
	Client(in_addr addr);
	~Client();
};
Client::Client(in_addr addr)
{
	mVersionRequested = MAKEWORD(2, 2);
	WSAStartup(mVersionRequested, &wsaData);
	sockConn = socket(AF_INET, SOCK_STREAM, 0);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(1234);
	getServerIP(serverAddr);
	addrSrv.sin_addr.S_un.S_addr = inet_addr(inet_ntoa(addr));
	connect(sockConn, (SOCKADDR*)& addrSrv, sizeof(addrSrv));
}

Client::~Client()
{
	closesocket(sockConn);
}

//network logic
void Client::getServerIP(char* serverAddr)
{
	printf("Please input the ip address of the server\n");
	//fgets(serverAddr, 50, stdin);
	scanf("%s", serverAddr);
}