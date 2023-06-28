#pragma once
#ifndef TCP_FUNCTION
#define TCP_FUNCTION
#include<stdio.h>
#include<stdlib.h>
#include<winsock2.h>
#include<iostream>
#pragma comment(lib,"ws2_32.lib")
using namespace std;

//TCP客户端类
class CTcpClient
{
public:
	int m_socket;   //客户端套接字
	char m_ip[21];  //服务端IP地址
	int m_port;    //服务端端口号
	int m_buflen;  //接收到的报文大小
	char sendbuff[200];  //发送缓冲区
	char recvbuff[200];  //接收缓冲区

	//构造：对成员变量初始化
	CTcpClient();

	//发起连接
	bool ConnectToServer(const char *ip_addr, int port);

	//发送报文
	bool TCP_SendData();

	//接收报文
	bool TCP_ReceiveData();
	
	//关闭套接字
	void Close();

	
	//析构：关闭套接字，并重置成员变量
	~CTcpClient();

};


#endif
