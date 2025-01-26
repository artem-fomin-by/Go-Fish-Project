#include <iostream>
#include <tchar.h>
#include "../Game.h"
#include "ConsoleUi.h"
#include "ConsolePlayer.h"
#include <string>
#include <windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
	std::string buff;

	while(true){
		while(buff != "�" && buff != "�"){
			std::cout << "������ �������(�/�): ";
			std::cin >> buff;
		}
		if(buff == "�")
			break;

		std::cout << "������� ���� ���: ";
		std::cin >> buff;

		auto player2 = new InternalComputerPlayer();
		auto player3 = new InternalComputerPlayer();
        auto player4 = new InternalComputerPlayer();
		auto player1 = new ConsoleHumanPlayer();

        player2->Name() = "��������";
		player3->Name() = "��������";
		player4->Name() = "superNic2020";
		player1->Name() = buff;


		auto userInteraction = new ConsoleUI();
		auto game = new Game();
		auto gameUI = new ConsoleGameUI();

		game->StartGame(player1, player2, player3, player4, userInteraction, gameUI);

        game->MainLoop();
	}
    std::system("pause");
    std::cin >> buff;
}
