#include"CTcpServer.h"

int main()
{
	class CTcpServer server;
	if (!server.InitServer("192.168.3.22", 2020))
	{
		printf("服务端初始化未成功！\n");
		server.Close();
	}
	else
	{
		printf("服务端等待连接！\n");
		if (!server.Accept())
		{
			printf("服务端未连接成功！\n");
			server.Close();
		}
		else
		{
			printf("连接成功，客户端IP为：%s \n", server.GetIP());
			strcpy(server.sendbuff, "ACK确认！");
			while (1)
			{
				memset(server.recvbuff, 0, sizeof(server.recvbuff));
				if (!server.TCP_ReceiveData())
				{
					printf("接收报文失败！\n");
					continue;
				}
				else if (!server.TCP_SendData())
				{
					printf("发送响应失败！\n");
					continue;
				}
				else
				{
					if (strcmp(server.recvbuff, "quit") == 0 || strcmp(server.recvbuff, "退出") == 0)
					{
						printf("TCP通信结束！\n"); break;
					}
					else printf("接收报文信息：%s \n", server.recvbuff);
				}

			}
		}
	}
	return 0;
 }
	
