#include "restruct.h"
#include<WinSock2.h>
#include<ws2tcpip.h>
castSer::castSer()
{
    mVersionRequested = MAKEWORD(2, 2);
	WSAStartup(mVersionRequested, &wsaData);
    s = socket(AF_INET, SOCK_DGRAM, 0);
    sin.sin_family = AF_INET;
	sin.sin_port = htons(4567);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;
    bind(s, (SOCKADDR*)& sin, sizeof(sin));
    mcast.imr_interface.S_un.S_addr = INADDR_ANY;
	mcast.imr_multiaddr.S_un.S_addr = inet_addr("234.5.6.7");
	setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char*)& mcast, sizeof(mcast));
    nAddrLen = sizeof(addrfrom);
    while (true)
	{
        int nRet = recvfrom(s, buf, strlen(buf), 0, (sockaddr*)& addrfrom, &nAddrLen);
		
		if (nRet != SOCKET_ERROR)
			break;
    }
}
castSer::~castSer()
{
    closesocket(s);
    WSACleanup();

}

castCli::castCli()
{
	mVersionRequested = MAKEWORD(2, 2);
    WSAStartup(mVersionRequested, &wsaData);
    s = socket(AF_INET, SOCK_DGRAM, 0);
    mCast.sin_family = AF_INET;
	mCast.sin_port = htons(4567);
	mCast.sin_addr.S_un.S_addr = inet_addr("234.5.6.7");
    char sz[] = "This is just a placeholder. \r\n";
	sendto(s, sz, strlen(sz), 0, (sockaddr*)& mCast, sizeof(mCast));
}
castCli::~castCli()
{
	closesocket(s);
    WSACleanup();
}
