#ifndef TCP_FUNCTION
#define TCP_FUNCTION
#include<stdio.h>
#include<stdlib.h>
#include<winsock2.h>
#include<iostream>
#pragma comment(lib,"ws2_32.lib")
using namespace std;

void SocketAssignment(struct sockaddr_in& addr, USHORT Protocol, int port, const char* IP);
bool TCP_Send(SOCKET s, char* Sendbuff, int n );
bool TCP_Recive(SOCKET s, char* Recvbuff, int n );
bool Myprotocol_Send(SOCKET s, char* Sendbuff);
bool Myprotocol_Recv(SOCKET s, char* Recvbuff);

#endif // !TCP_FUNCTION
