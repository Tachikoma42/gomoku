#include<WinSock2.h>
#include<stdio.h>
#include<string>
#pragma comment(lib, "WS2_32")

//#define serverAddr "127.0.0.1"
typedef struct LOCATION {
	int x;
	int y;
}location;
typedef struct SOCKLOCATION{
	char x[1];
	char y[1];
}socklocation;
class Conn
{
private:
	WORD mVersionRequested;
    WSADATA wsaData;
public:
	SOCKET sockClient;
	SOCKADDR_IN addrSrv;

	Conn(char serverAddr[50]);
	~Conn();
};

Conn::Conn(char serverAddr[50])
{
	mVersionRequested = MAKEWORD(2,2);
	sockClient = socket(AF_INET, SOCK_STREAM, 0);
	addrSrv.sin_family = AF_INET;
    addrSrv.sin_port = htons(1234);
    addrSrv.sin_addr.S_un.S_addr = inet_addr(serverAddr);
}
void sendStone(SOCKET sockClient, location stoneLocation, int len, int flags = 0)
{
	socklocation sendLocation;
	itoa(stoneLocation.x,sendLocation.x,10);
	itoa(stoneLocation.y, sendLocation.y,10);
	//memcpy(sendLocation.x,)
	send(sockClient, (char*)&sendLocation, sizeof(socklocation), 0);

}
void recvStone(SOCKET sockClient, location stoneLocation, int len, int flags = 0)
{
	char buffer[10];
	socklocation recvLocation;
	recv(sockClient, buffer,sizeof(buffer),0);
	memcpy(&recvLocation,buffer, sizeof(buffer));
}
int main()
{
    // //gcc client.c -lws2_32 -o client
    char serverAddr[50];
    printf("Please input the ip address of the server\n");
    scanf("%s", &serverAddr);
    
    // WORD mVersionRequested;
    // WSADATA wsaData;
    // int err;

    // mVersionRequested = MAKEWORD(2,2);

    // err = WSAStartup(mVersionRequested, &wsaData);
    // if (err != 0)
    //     return SOCKET_ERROR;

    // SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);
    // SOCKADDR_IN addrSrv;

    // addrSrv.sin_family = AF_INET;
    // addrSrv.sin_port = htons(1234);
    // addrSrv.sin_addr.S_un.S_addr = inet_addr(serverAddr);
	Conn conn(serverAddr);
	connect(conn.sockClient, (SOCKADDR*)& conn.addrSrv, sizeof(conn.addrSrv));
    char sendLocation[2];
    char recvLocation[2];
    while(TRUE)
    {	    
        recv(conn.sockClient, recvLocation, 2, 0);
        printf("%s\n", recvLocation);
        // scanf("%s", &sendLocation);
        // send(sockClient, sendLocation, strlen(sendLocation) + 1, 0);
    }
    closesocket(conn.sockClient);

    return 0;
}