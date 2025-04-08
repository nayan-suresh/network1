#include<stdio.h>
#include<netinet/in.h>
#include<netdb.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
int main()
{
    int clientsocket, port;
    struct sockaddr_in serveraddr;
    socklen_t len = sizeof(serveraddr);
    int a, fact;
    clientsocket = socket(AF_INET, SOCK_DGRAM, 0);
    printf("Enter port: ");
    scanf("%d", &port);
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    printf("Enter the number: ");
    scanf("%d", &a);
    sendto(clientsocket, &a, sizeof(a), 0, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
    printf("%d sent to server for calculation\n", a);
    recvfrom(clientsocket, &fact, sizeof(fact), 0, (struct sockaddr*)&serveraddr, &len);
    printf("Factorial received from server: %d\n", fact);
    close(clientsocket);
}
