#include"CTcpClient.h"


//1.构造函数
CTcpClient::CTcpClient()
{
	//SOCKET库初始化
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	this->m_socket = -1;
	memset(this->m_ip, 0, sizeof(m_ip));
	//this->m_ip = NULL;
	memset(this->sendbuff, 0, sizeof(sendbuff));
	memset(this->recvbuff, 0, sizeof(recvbuff));
	this->m_port = 0;
	this->m_buflen = 0;
}


//2.关闭客户端套接字
void CTcpClient::Close()
{
	closesocket(this->m_socket);
	this->m_socket = -1;
	//WSACleanup();
}

//3.析构函数
CTcpClient::~CTcpClient()
{
	if (this->m_socket > 0) this->Close();

	//this->m_socket = -1;
	memset(this->m_ip, 0, sizeof(m_ip));
	//this->m_ip = NULL;
	memset(this->sendbuff, 0, sizeof(sendbuff));
	memset(this->recvbuff, 0, sizeof(recvbuff));
	this->m_port = 0;
	this->m_buflen = 0;

	WSACleanup();

}

//4. 初始化套接字和发起连接
bool CTcpClient::ConnectToServer( const char* ip_addr , int port)
{
	if (this->m_socket > 0) 
	{
		this->Close(); m_socket = -1;
	}
	this->m_socket = socket(AF_INET, SOCK_STREAM, 0);
	strcpy(this->m_ip, ip_addr);
	//memcpy((void *)this->m_ip, ip_addr,strlen(ip_addr));
	this->m_port = port;

	struct sockaddr_in serve_addr;
	serve_addr.sin_family = AF_INET;
	serve_addr.sin_port = htons(this->m_port);
	serve_addr.sin_addr.S_un.S_addr = inet_addr(this->m_ip);

	if (connect(this->m_socket, (struct sockaddr*)&serve_addr, sizeof(serve_addr)) !=0 )
	{
		//printf("客户端连接失败！\n");
		this->Close();
		return false;
	}
	else
	{
		//printf("客户端连接成功！\n");
		return true;
	}
}


//5.发送报文
bool CTcpClient::TCP_SendData()
{
	int len = strlen(this->sendbuff) + 1;  //加上末尾的字符串结束标志/0
	int nlen = htonl(len);
	char strTBuff[200] = { 0 };

	memset(strTBuff, 0, sizeof(strTBuff));
	memcpy(strTBuff, &nlen, 4);  //设置内存区的内容和占用的字节长度
	memcpy(strTBuff + 4, this->sendbuff, len);

	if ( send(this->m_socket, strTBuff, len+4 , 0) > 0)
		return  true;
	else return false;

}


//6.接收报文
bool CTcpClient::TCP_ReceiveData()
{
	if (recv(this->m_socket, (char*)&this->m_buflen, 4, 0) > 0)
	{
		this->m_buflen = ntohl(this->m_buflen);
		if ( recv(this->m_socket, this->recvbuff, this->m_buflen, 0) > 0)
			return true;
		else return false;
	}
	else return false;
}





