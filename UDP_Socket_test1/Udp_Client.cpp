#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib,"WS2_32.lib")
#include <string.h>
using namespace std;

int main() {
	WSADATA wsaData;//���뵼��WINsock2.h������ʼ��
	SOCKET SendSocket;
	sockaddr_in RecvAddr;//��������ַ
	int port = 4000;//�����������˿�
	char SendBuf[1024];//�������ݵĻ�����
	int BufLen = 1024;//��������С
	//���г�ʼ��Socket
	WSAStartup(MAKEWORD(2,2),&wsaData);
	//����Socket����
	SendSocket = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	//���÷�������ַ
	RecvAddr.sin_family = AF_INET;
	RecvAddr.sin_port = htons(port);
	RecvAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	//���������������
	cout << "Sending datagram" << endl;
	sendto(SendSocket,"jjjj",BufLen,0,(SOCKADDR*)&RecvAddr,sizeof(RecvAddr));
	//������ɣ��ر�socket
	cout << "finished socket" << endl;
	closesocket(SendSocket);
	cout << "hello" << endl;
	cout << "Exting" << endl;
	WSACleanup();

	system("pause");
	return 0;
}

/*
	���Ͷˣ��ͻ��ˣ�send client
	���նˣ��������ˣ� recv server
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
//	sendto(sockClient, "����UDPͨ�ţ�", 50, 0, (sockaddr *)&addr, 50);
//	closesocket(s);
//	WSACleanup();
//	printf("Hello World!\n");
//	system("pause");
//	return 0;
//}