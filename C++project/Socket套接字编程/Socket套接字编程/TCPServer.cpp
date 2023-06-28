#include"TCP_function.h"
#pragma comment(lib,"ws2_32.lib")
using namespace std;

int testServer()
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	//以下为测试信息，打印相应的数值用于测试
	/*
	printf("wVersion: %d.%d\n", LOBYTE(wsaData.wVersion), HIBYTE(wsaData.wVersion));
	printf("wHighVersion: %d.%d\n", LOBYTE(wsaData.wHighVersion), HIBYTE(wsaData.wHighVersion));
	printf("szDescription: %s\n", wsaData.szDescription);
	printf("szSystemStatus: %s\n", wsaData.szSystemStatus);
*/
//创建套接字
	SOCKET server_socket = socket(AF_INET, SOCK_STREAM, 0);
	//创建结构体变量
	struct sockaddr_in serv_addr;
	SocketAssignment(serv_addr, AF_INET, 2023, "127.0.0.1");

	//绑定套接字参数
	bind(server_socket, (struct sockaddr*)&serv_addr, sizeof(sockaddr));    // 将套接字绑定到本地地址和端口上。

	//开启监听 int listen(int sockfd, int queue_length);
	listen(server_socket, 3);//最多开启3个连接

	cout << "等待客户端连接！" << endl;
	//接受请求 int accept(int sockfd, struct sockaddr *addr, int *addrlen);
	struct sockaddr_in clientaddr;
	int alength = sizeof(sockaddr);
	int aID = accept(server_socket, (struct sockaddr*)&clientaddr, &alength);  //默认阻塞

	//打印信息
	printf("已接受来自客户端 IP：%s 端口号：%d 的连接\n", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));//将端口号由网络字节序转为主机字节序

	//接受数据  int recv(int aID, char *buf, int len, int flags);
	char recvbuff[200] = {0};
	char sendbuff[200] = {0};


	while (1)
	{
		//int len = recv(aID, recvbuff, sizeof(recvbuff), 0);  //默认阻塞
		if (Myprotocol_Recv(aID, recvbuff))
		{
			if (strcmp(recvbuff, "quit") == 0)
			{
				cout << "通信结束，TCP连接断开" << endl;
				break;
			}
			cout << "服务端接收到数据" << endl;
			printf("数据大小：%d个字节,数据内容：%s \n", strlen(recvbuff), recvbuff);

			strcpy(sendbuff, "已收到客户端数据,此为ACK确认信息！");
			//send(aID, sendbuff, strlen(sendbuff), 0);
			if (!Myprotocol_Send(aID, sendbuff))
			{
				cout << "发送响应失败！" << endl;
			}
		}
		else
			cout << "服务端接受数据失败！" << endl; 

		

		//清空缓冲区
		::memset(sendbuff, 0, sizeof(sendbuff));  
		::memset(recvbuff, 0, sizeof(recvbuff)); 
	}
	//清空缓冲区
	::memset(sendbuff, 0, sizeof(sendbuff));
	::memset(recvbuff, 0, sizeof(recvbuff));
	closesocket(aID);//关闭套接字，结束TCP连接
	WSACleanup();//停止Socket库的使用
	return 0;

}


int main()
{
	return testServer();
}