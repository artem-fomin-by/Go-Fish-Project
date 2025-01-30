#include <iostream>
#include <tchar.h>
#include "../Game.h"
#include "ConsoleUi.h"
#include "ConsolePlayer.h"
#include <string>
#include <windows.h>
#include "Intellegence.h"
#include "Unit2.h"
#include <ctime>

int _tmain(int argc, _TCHAR* argv[])
{

    std::time_t currentTime = std::time(nullptr);
	std::tm *localTime = std::localtime(&currentTime);

	std::string s1 = std::to_string(localTime->tm_mday);
	std::string s2 = std::to_string(localTime->tm_mon + 1);
	std::string s3 = std::to_string(localTime->tm_year + 1900);
	std::string s4 = std::to_string(localTime->tm_hour);
	std::string s5 = std::to_string(localTime->tm_min);
	std::string s6 = std::to_string(localTime->tm_sec);

	std::string path = "logs/" + s1 + "." + s2 + "." + s3 + "_" + s4 + "-" + s5 + "-" + s6 + ".txt";

    fout << path;

	fout.close();

	fout.open(path);

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
	std::string buff;

	while(true){
		while(buff != "д" && buff != "н"){
			fout << "Хотите сыграть(д/н): ";
			std::cout << "Хотите сыграть(д/н): ";
			std::cin >> buff;
		}
		if(buff == "н")
			break;

		fout << "Введите ваше имя: ";
		std::cout << "Введите ваше имя: ";
		std::cin >> buff;

		auto player2 = new InternalComputerPlayer();
		auto player3 = new InternalComputerPlayer();
        auto player4 = new InternalComputerPlayer();
		auto player1 = new InternalComputerPlayer();

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
}
