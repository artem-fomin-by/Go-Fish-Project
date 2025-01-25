// .cpp file
// consists ConsoleUI classes

#include <iostream>
#include "ConsoleUi.h"
#include "../Player.h"

ConsoleUI::ConsoleUI(){

}

void ConsoleUI::ShowTypeRequest(Type type, Player* player) {

}

void ConsoleUI::ShowTypeResponse(bool answer, Player* player) {
	if(answer)
		std::cout << player->Name() << " �������, ��� � ���� ���� �����(�) ����� ����";
	if(answer)
		std::cout << player->Name() << " �������, ��� � ���� ��� ���� ����� ����";
}

void ConsoleUI::ShowCountRequest(int count, Type type, Player* player) {

}

void ConsoleUI::ShowCountResponse(bool answer, Player* player) {
    if(answer)
		std::cout << player->Name() << " �������, ��� � ���� ������ ������� ���� ����� ����";
	if(answer)
		std::cout << player->Name() << " �������, ��� � ���� ������ ���������� ���� ����� ����";
}

void ConsoleUI::ShowSuitRequest(Type type, const std::vector<Suit>& cards, Player* player) {

}

void ConsoleUI::ShowSuitResponse(bool answer, Player* player) {
	if(answer)
		std::cout << player->Name() << " �������, ��� � ���� ������ ��� �����!";
	if(answer)
		std::cout << player->Name() << " �������, ��� � ���� ������ �����!";
}
