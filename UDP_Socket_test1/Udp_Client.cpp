#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib,"WS2_32.lib")
#include <string.h>
using namespace std;

int main() {
	WSADATA wsaData;//必须导入WINsock2.h包，初始化
	SOCKET SendSocket;
	sockaddr_in RecvAddr;//服务器地址
	int port = 4000;//服务器监听端口
	char SendBuf[1024];//发送数据的缓冲区
	int BufLen = 1024;//缓冲区大小
	//进行初始化Socket
	WSAStartup(MAKEWORD(2,2),&wsaData);
	//创建Socket对象
	SendSocket = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	//配置服务器地址
	RecvAddr.sin_family = AF_INET;
	RecvAddr.sin_port = htons(port);
	RecvAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	//向服务器发送数据
	cout << "Sending datagram" << endl;
	sendto(SendSocket,"jjjj",BufLen,0,(SOCKADDR*)&RecvAddr,sizeof(RecvAddr));
	//发送完成，关闭socket
	cout << "finished socket" << endl;
	closesocket(SendSocket);
	cout << "hello" << endl;
	cout << "Exting" << endl;
	WSACleanup();

	system("pause");
	return 0;
}

/*
	发送端（客户端）send client
	接收端（服务器端） recv server
*/
//#include <stdio.h>
//#include <WinSock2.h>
//#include <Windows.h>
//
//#pragma comment(lib,"WS2_32.lib")
//
//int main(void)
//{
//	WSADATA wsd;
//	SOCKET s;
//
//	if (WSAStartup(MAKEWORD(2, 2), &wsd))
//	{
//		printf("WSAStartup failed!\n");
//		return 1;
//	}
//
//	s = socket(AF_INET, SOCK_DGRAM, 0);
//	if (s == INVALID_SOCKET)
//	{
//		printf("socket failed,Error Code:%d\n", WSAGetLastError());
//		WSACleanup();
//		return 1;
//	}
//	SOCKADDR_IN addr;
//	SOCKET sockClient = socket(AF_INET, SOCK_DGRAM, 0);
//
//	addr.sin_family = AF_INET;
//	addr.sin_addr.S_un.S_addr = inet_addr("172.20.10.3");
//	addr.sin_port = htons(1401);
//
//	sendto(sockClient, "测试UDP通信！", 50, 0, (sockaddr *)&addr, 50);
//	closesocket(s);
//	WSACleanup();
//	printf("Hello World!\n");
//	system("pause");
//	return 0;
//}