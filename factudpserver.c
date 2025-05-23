#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>
#include<netdb.h>
#include<sys/types.h>
#include<stdlib.h>
#include<arpa/inet.h>
int main()
{
    int serversocket, port;
    struct sockaddr_in serveraddr, clientaddr;
    socklen_t len = sizeof(clientaddr);
    int a, fact = 1, i;
    serversocket = socket(AF_INET, SOCK_DGRAM, 0);
    printf("Enter port number: ");
    scanf("%d", &port);
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    bind(serversocket, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
    printf("Waiting for client\n");
    recvfrom(serversocket, &a, sizeof(a), 0, (struct sockaddr*)&clientaddr, &len);
    printf("Received %d from client\n", a);
    for(i = 1; i <= a; i++)
    {
        fact *= i;
    }
    sendto(serversocket, &fact, sizeof(fact), 0, (struct sockaddr*)&clientaddr, len);
    printf("Factorial calculated and sent to client\n");
    close(serversocket);
}
