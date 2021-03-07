#include<stdio.h>
#include<sys/socket.h> 
#include<arpa/inet.h>	

int main(int argc , char *argv[])
{
	int socket_desc;
	struct sockaddr_in server;
	
	//Сокет үүсгэх.
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1)
	{
		printf("Сокет үүсгэж чадсангүй.!");
	}
		
	server.sin_addr.s_addr = inet_addr("202.70.34.28");
	server.sin_family = AF_INET;
	server.sin_port = htons( 80 );

	//Remote сервертэй холбогдох.
	if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		puts("Холболтонд алдаа гарлаа.!");
		return 1;
	}
	
	puts("Холбогдлоо.!");
	printf("Серверийн IP (Бүхэл тоон утга): %d\n" , server.sin_addr.s_addr);
	printf("IP хаяг: %s\n" , inet_ntoa(server.sin_addr));
	return 0;
}