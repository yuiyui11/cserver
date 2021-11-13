#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
 struct sockaddr_in addr;
 struct sockaddr_in client;

 int sock = socket(AF_INET, SOCK_STREAM, 0);

 addr.sin_family = AF_INET;
 addr.sin_port = htons(12345);
 addr.sin_addr.s_addr = INADDR_ANY;
 bind(sock, (struct sockaddr *)&addr, sizeof(addr));

 listen(sock, 3);

 int len = sizeof(client);
 int newsock = accept(sock, (struct sockaddr *)&client, &len);


 write(newsock, "HELLO", 5);


 close(newsock);
 close(sock);
 return 0;
}
