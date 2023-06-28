#include"TCP_function.h"
#pragma comment(lib,"ws2_32.lib")
using namespace std;

//sockaddr_in结构体变量赋值函数
void SocketAssignment(struct sockaddr_in &addr, USHORT Protocol,int port,const char* IP)
{
	addr.sin_family = Protocol;
	addr.sin_port = htons(port);
	addr.sin_addr.S_un.S_addr = inet_addr(IP);
}


//TCP分包发送
bool TCP_Send(SOCKET s,char* Sendbuff,int n=0)
{
	if (n == 0) n = strlen(Sendbuff);
	int Send_left = n;
	int index = 0, nSend = 0;
	/*
	while (Send_left>0)
	{
		if (nSend = send(s, Sendbuff + index, Send_left, 0) > 0 )
		{
			Send_left -= nSend;
			index += nSend;
		}
		else
		{
			return false;
		}
	}
	return true;*/
	
	if (nSend = send(s, Sendbuff + index, Send_left, 0) > 0)
		return  true;
	else return false;
}


//TCP粘包接受
bool TCP_Recive(SOCKET s, char* Recvbuff, int n = 0)
{
	if (n == 0) n = 200 ;//  
	int Recv_left = n;
	int index = 0, nRecv = 0;
	/*
	while (Recv_left > 0)
	{
		if ( recv(s, Recvbuff + index, Recv_left, 0) > 0 )
		{
			nRecv = strlen(Recvbuff);
			Recv_left -= nRecv;
			index += nRecv;
		}
		else return false;
	}
	return true;*/
	
	if (nRecv = recv(s, Recvbuff + index, Recv_left, 0) > 0)
		return  true;
	else return false;
}

//自定义协议发送(报文内容：报文数据长度+报文实际内容)
bool  Myprotocol_Send(SOCKET s, char* Sendbuff)
{
	int len = strlen(Sendbuff)+1;  //加上末尾的字符串结束标志/0
	int nlen = htonl(len);
	char strTBuff[200] = {0};

	memset(strTBuff,0,sizeof(strTBuff));
	memcpy(strTBuff, &nlen, 4);  //设置内存区的内容和占用的字节长度
	memcpy(strTBuff + 4, Sendbuff, len);
	return TCP_Send(s, strTBuff,len+4);
}

//自定义协议接受
bool  Myprotocol_Recv(SOCKET s, char* Recvbuff)
{
	int len=0;
	TCP_Recive(s, (char*)&len, 4);
	len = ntohl(len);
	return TCP_Recive(s, Recvbuff,len);
}