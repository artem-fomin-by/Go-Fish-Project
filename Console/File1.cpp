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
		while(buff != "д" && buff != "н"){
			std::cout << "Хотите сыграть(д/н): ";
			std::cin >> buff;
		}
		if(buff == "н")
			break;

		std::cout << "Введите ваше имя: ";
		std::cin >> buff;

		auto player2 = new InternalComputerPlayer();
		auto player3 = new InternalComputerPlayer();
        auto player4 = new InternalComputerPlayer();
		auto player1 = new ConsoleHumanPlayer();

        player2->Name() = "Геннадий";
		player3->Name() = "Каролина";
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
