#include "restruct.h"

int main()
{
    castSer ser;
	printf("%s\n", inet_ntoa(ser.addrfrom.sin_addr));
    return 0;
}