//Client thhek
#include "Window.h"
#include"Board.h"
#include"Coin.h"
#include<process.h>
#include<iostream>

//Network Libraries
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")
#include<WinSock2.h>

using namespace std;

int con = 0;
bool GameWon = false;

WSADATA wsaData;
WORD dllversion;
SOCKADDR_IN addr;
SOCKET Connection;
SOCKET newConnection;
int sizeofaddr;
int init();
void SEND_RECEIVE();

char CheckTurn[1] = { 'n' };
char r_CheckTurn[1] = { 'n' };

//Used for SENDING!

char CS_x1[4], CS_x2[4], CS_x3[4], CS_x4[4], CS_y1[4], CS_y2[4], CS_y3[4], CS_y4[4];
int x_send[4], y_send[4];
string SendX[4], SendY[4];

//Used for RECEIVING!
char CR_x1[4], CR_x2[4], CR_x3[4], CR_x4[4], CR_y1[4], CR_y2[4], CR_y3[4], CR_y4[4];
int x_rec[4], y_rec[4];
string RecX[4],RecY[4];



int main(int agrc, char**argv){
	init();
	Window window("Ludo", 920, 930);
	Board board(window, 350, 350,255);
	Coin coin(window, 100, 700,200, 700, 100, 780, 200, 780, 680, 100, 780, 100, 680, 200, 780, 200, 255);
	system("cls");
	cout << "Server!" << endl;
	while (!window.isClosed()) {
		coin.CoinCheck();
		if (!GameWon) {
			window.clear();
			board.draw();
			coin.draw();
			window.pollEvents();
			board.pollEvent();
			coin.pollEvent();
			SEND_RECEIVE();

			//GETTING XY VALUES
			x_send[0] = coin.Get_X1();
			x_send[1] = coin.Get_X2();
			x_send[2] = coin.Get_X3();
			x_send[3] = coin.Get_X4();
			y_send[0] = coin.Get_Y1();
			y_send[1] = coin.Get_Y2();
			y_send[2] = coin.Get_Y3();
			y_send[3] = coin.Get_Y4();

			//SETTING XY VALUES
			coin.Set_x1(x_rec[0]);
			coin.Set_x2(x_rec[1]);
			coin.Set_x3(x_rec[2]);
			coin.Set_x4(x_rec[3]);
			coin.Set_y1(y_rec[0]);
			coin.Set_y2(y_rec[1]);
			coin.Set_y3(y_rec[2]);
			coin.Set_y4(y_rec[3]);

			CheckTurn[0] = coin.GetCheckTurn();
			coin.SetCheckTurn(r_CheckTurn[0]);
			coin.Kill();

			if (coin.GameWIn()) {
				GameWon = true;
			}

		}
	}
	return 0;
}

int init() {
	dllversion = MAKEWORD(2, 1);
	if (WSAStartup(dllversion, &wsaData) != 0) {
		cerr << "WinSock startup FAILURE!" << endl;
		return 0;
	}
	sizeofaddr = sizeof(addr);
	addr.sin_addr.S_un.S_addr = inet_addr("192.168.56.20");
	addr.sin_family = AF_INET;
	addr.sin_port = htons(54000);

	Connection = socket(AF_INET, SOCK_STREAM, NULL);
	bind(Connection, (SOCKADDR*)&addr, sizeof(addr));
	listen(Connection, SOMAXCONN);
}

void SEND_RECEIVE(){
	newConnection = accept(Connection, (SOCKADDR*)&addr, &sizeofaddr);
	if (newConnection == 0) {
		cerr << "Failed to accept the Client's Connection!" << endl;
		con = 0;
	}
	else {
		if (con == 0) {
			//system("cls");
			cout << "Connected" << endl;
			con = 1;
		}

		//SENDING DATA
		{
			//Coin1
			SendX[0] = to_string(x_send[0]);
			SendY[0] = to_string(y_send[0]);
			strcpy_s(CS_x1, SendX[0].c_str());
			strcpy_s(CS_y1, SendY[0].c_str());

			send(newConnection, CS_x1, sizeof(CS_x1), NULL);
			send(newConnection, CS_y1, sizeof(CS_y1), NULL);

			//Coin2
			SendX[1] = to_string(x_send[1]);
			SendY[1] = to_string(y_send[1]);
			strcpy_s(CS_x2, SendX[1].c_str());
			strcpy_s(CS_y2, SendY[1].c_str());

			send(newConnection, CS_x2, sizeof(CS_x2), NULL);
			send(newConnection, CS_y2, sizeof(CS_y2), NULL);


			//Coin3
			SendX[2] = to_string(x_send[2]);
			SendY[2] = to_string(y_send[2]);
			strcpy_s(CS_x3, SendX[2].c_str());
			strcpy_s(CS_y3, SendY[2].c_str());

			send(newConnection, CS_x3, sizeof(CS_x3), NULL);
			send(newConnection, CS_y3, sizeof(CS_y3), NULL);

			//Coin4
			SendX[3] = to_string(x_send[3]);
			SendY[3] = to_string(y_send[3]);
			strcpy_s(CS_x4, SendX[3].c_str());
			strcpy_s(CS_y4, SendY[3].c_str());

			send(newConnection, CS_x4, sizeof(CS_x4), NULL);
			send(newConnection, CS_y4, sizeof(CS_y4), NULL);
		}

		//RECEIVING DATA
		{
			//Coin1
			recv(newConnection, CR_x1, sizeof(CR_x1), NULL);
			recv(newConnection, CR_y1, sizeof(CR_y1), NULL);
			x_rec[0] = atoi(CR_x1);
			y_rec[0] = atoi(CR_y1);

			//Coin2
			recv(newConnection, CR_x2, sizeof(CR_x2), NULL);
			recv(newConnection, CR_y2, sizeof(CR_y2), NULL);
			x_rec[1] = atoi(CR_x2);
			y_rec[1] = atoi(CR_y2);

			//Coin3
			recv(newConnection, CR_x3, sizeof(CR_x3), NULL);
			recv(newConnection, CR_y3, sizeof(CR_y3), NULL);
			x_rec[2] = atoi(CR_x3);
			y_rec[2] = atoi(CR_y3);

			//Coin4
			recv(newConnection, CR_x4, sizeof(CR_x4), NULL);
			recv(newConnection, CR_y4, sizeof(CR_y4), NULL);
			x_rec[3] = atoi(CR_x4);
			y_rec[3] = atoi(CR_y4);
		}

	}

	//Sending Check && Receiving Check
	recv(newConnection, r_CheckTurn, sizeof(r_CheckTurn), NULL);
	send(newConnection, CheckTurn, sizeof(CheckTurn), NULL);
}