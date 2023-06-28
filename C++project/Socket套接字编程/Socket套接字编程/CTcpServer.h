#pragma once
#ifndef TCP_FUNCTION
#define TCP_FUNCTION
#include<stdio.h>
#include<stdlib.h>
#include<winsock2.h>
#include<iostream>
#pragma comment(lib,"ws2_32.lib")
using namespace std;

//TCP服务端类
class CTcpServer
{
private:
	int m_socklen;  //sockaddr结构体内存大小
	struct sockaddr_in m_clientaddr;  //客户端地址信息
	struct sockaddr_in m_serveraddr;  //服务端地址信息

public:
	int m_serversocket;   //服务端套接字
	int m_clientsocket; //客户端套接字
	char m_ip[21];  //服务端IP地址
	int m_port;    //服务端端口号
	int m_buflen;  //接收到的报文大小
	char sendbuff[200];  //发送缓冲区
	char recvbuff[200];  //接收缓冲区

	//构造：成员变量初始化
	CTcpServer();
	
	//服务端初始化
	bool InitServer(const char* ip, const int port);

	//服务端接收连接
	bool Accept();

	//获取客户端IP地址
	char* GetIP();

	//关闭服务端的套接字
	void  Close();

	//发送报文
	bool TCP_SendData();

	//接收报文
	bool TCP_ReceiveData();

	//析构：关闭连接，重置成员变量
	~CTcpServer();

};

#endif
