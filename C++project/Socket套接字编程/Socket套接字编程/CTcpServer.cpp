#include"CTcpServer.h"

//1. 构造函数
CTcpServer::CTcpServer() 
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	memset(&this->m_clientaddr, 0, sizeof(m_clientaddr));
	memset(&this->m_serveraddr, 0, sizeof(m_serveraddr));
	this->m_serversocket = this->m_clientsocket = -1;
	memset(this->m_ip, 0, sizeof(m_ip));
	this->m_port = this->m_buflen=0;
	memset(this->sendbuff, 0, sizeof(sendbuff));
	memset(this->recvbuff, 0, sizeof(recvbuff));
	this->m_socklen = sizeof(m_clientaddr);

}

//2. 服务端初始化
bool CTcpServer::InitServer(const char *ip,const int port) 
{
	if (this->m_serversocket > 0) 
	{
		this->Close(); m_serversocket = -1;
	}
	strcpy(this->m_ip, ip);
	this->m_port = port;
	this->m_serversocket = socket(AF_INET, SOCK_STREAM, 0);
	m_serveraddr.sin_family = AF_INET;
	m_serveraddr.sin_addr.S_un.S_addr = inet_addr(this->m_ip);
	m_serveraddr.sin_port = htons(this->m_port);

	if (bind(this->m_serversocket, (struct sockaddr*)&m_serveraddr, sizeof(m_serveraddr)) != 0)
	{
		this->Close(); return false;
	}
	listen(this->m_serversocket,5); //最多允许同时有5个连接
	return true;

}

//3. 开启接受连接
bool CTcpServer::Accept()
{
	if (this->m_serversocket == -1) return false;
	this->m_clientsocket = accept(this->m_serversocket, (struct sockaddr*)&this->m_clientaddr, &this->m_socklen);
	if(this->m_clientsocket < 0)
		return false;
	else return true;
}

//4. 获取客户端IP地址
char* CTcpServer::GetIP()
{
	return inet_ntoa(this->m_clientaddr.sin_addr);
}

//5. 关闭服务端套接字
void  CTcpServer::Close() 
{
	closesocket(this->m_serversocket);
}

//6. 发送报文
bool CTcpServer::TCP_SendData()
{
	int len = strlen(this->sendbuff) + 1;  //加上末尾的字符串结束标志/0
	int nlen = htonl(len);
	char strTBuff[200] = { 0 };

	memset(strTBuff, 0, sizeof(strTBuff));
	memcpy(strTBuff, &nlen, 4);  //设置内存区的内容和占用的字节长度
	memcpy(strTBuff + 4, this->sendbuff, len);

	if (send(this->m_clientsocket, strTBuff, len + 4, 0) > 0)
		return  true;
	else return false;
}

//7. 接收报文
bool CTcpServer::TCP_ReceiveData()
{
	recv(this->m_clientsocket, (char*)&(this->m_buflen), 4, 0);   //获取报文长度

	this->m_buflen = ntohl(this->m_buflen);
	if (recv(this->m_clientsocket, this->recvbuff, this->m_buflen, 0) > 0)
		return true;
	else return false;

}


//8. 析构函数
CTcpServer::~CTcpServer()
{
	if (this->m_serversocket > 0) this->Close();

	memset(&this->m_serversocket, 0, sizeof(m_serversocket));
	memset(&this->m_clientsocket, 0, sizeof(m_clientsocket));
	this->m_serversocket = this->m_clientsocket = -1;
	memset(this->m_ip, 0, sizeof(m_ip));
	this->m_port = this->m_buflen = 0;
	memset(this->sendbuff, 0, sizeof(sendbuff));
	memset(this->recvbuff, 0, sizeof(recvbuff));

	WSACleanup();
}
