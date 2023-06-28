#include"CTcpClient.h"

int main()
{
	class CTcpClient client;

	if (!client.ConnectToServer("192.168.3.10", 2020))
	{
		printf("客户端未连接成功！\n");
		client.Close();
	}
	else
	{
		printf("成功到连接服务端！\n");
		while (1)
		{
			memset(client.sendbuff, 0, sizeof(client.sendbuff));
			memset(client.recvbuff, 0, sizeof(client.recvbuff));
			printf(":");
			gets_s(client.sendbuff);
			if (strcmp(client.sendbuff, "quit") == 0 || strcmp(client.sendbuff, "退出") == 0)
			{
				client.TCP_SendData();
				break;
			}

			if (!client.TCP_SendData())
			{
				printf("报文发送失败！\n");
				continue;
			}
			if (!client.TCP_ReceiveData())
			{
				printf("未接收到服务端响应！\n");
				continue;
			}
			printf("接收到服务端响应：%s \n", client.recvbuff);

		}
	}
	return 0;
}
