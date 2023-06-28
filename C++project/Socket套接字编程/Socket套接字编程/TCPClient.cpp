#include"TCP_function.h"
#pragma comment(lib,"ws2_32.lib")
using namespace std;


int testClient()
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	//定义数据缓冲区
	char Sendbuff[200] = {0};
	char Recvbuff[200] = {0};
	//创建套接字
	SOCKET client_socket = socket(AF_INET, SOCK_STREAM, 0);

	//创建客户端结构体变量
	struct sockaddr_in client_addr;
	SocketAssignment(client_addr, AF_INET,2023,"192.168.3.10");

	int r = connect(client_socket, (struct sockaddr*)&client_addr, sizeof(sockaddr));
	if (r == 0)  printf("客户端连接成功！\n");
	else return -1;
	while(1)
	{
		cout << ":";
		gets_s(Sendbuff);
		if (strcmp(Sendbuff, "quit") == 0)
		{
			//send(client_socket, "quit", strlen(Sendbuff), 0);
			Myprotocol_Send((SOCKET)client_socket, Sendbuff);
			break;
		}
		//send(client_socket, Sendbuff, strlen(Sendbuff), 0);
		if (!Myprotocol_Send((SOCKET)client_socket, Sendbuff))
		{
			cout << "数据发送失败！" << endl;
		}
		else if (Myprotocol_Recv((SOCKET)client_socket, Recvbuff))
		{
			cout << "客户端收到响应，" ;
			printf("响应内容：%s \n ",  Recvbuff);
		}
		//int len = recv(client_socket, Recvbuff, sizeof(Recvbuff), 0);  //默认阻塞}
		else {
			cout << "客户端未接收到响应！" << endl;
		}

		//清空缓冲区
		::memset(Sendbuff, 0, sizeof(Sendbuff));  
		::memset(Recvbuff, 0, sizeof(Recvbuff));
	}
	//清空缓冲区
	::memset(Sendbuff, 0, sizeof(Sendbuff));
	::memset(Recvbuff, 0, sizeof(Recvbuff));
	closesocket(client_socket);//关闭套接字，结束TCP连接
	WSACleanup();//停止Socket库的使用
	return 0;

}
int main()
{

	return  testClient();

}