#include<stdio.h>
#include<string.h> //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
int main(int argc , char *argv[])
{
	int socket_desc,port;
	struct sockaddr_in server;
	char message[50] , server_reply[2000];
	char IP[20];
	//Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1)
	{
		printf("Could not create socket");
	}
	printf("請輸入IP：");
	scanf("%s",IP);
	printf("請輸入port：");
	scanf("%d",&port);
	server.sin_addr.s_addr = inet_addr(IP);
	server.sin_family = AF_INET;
	server.sin_port = htons( port );
	//Connect to remote server
	if (connect(sockfd , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		puts("connect error");
		return 1;
	}
	puts("Connected\n");
	while(1)
	{
		//Send some data
		//message = "GET / HTTP/1.1\r\n\r\n";
		printf("\n請輸入4個數字：");
		scanf("%s",message);
		if( send(sockfd , message , strlen(message) , 0) < 0)
		{
			puts("Send failed");
			return 1;
		}
		puts("Data Send\n");
		//Receive a reply from the server
		if( recv(socket_desc, server_reply , 2000 , 0) < 0)
		{
			puts("recv failed");
		}
		puts("Reply received\n");
		puts(server_reply);
	}
	return 0;
}

