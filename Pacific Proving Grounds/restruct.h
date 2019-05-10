#pragma once
#include<WinSock2.h>
#include<ws2tcpip.h>
#include<stdio.h>
#pragma comment(lib, "WS2_32")


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
