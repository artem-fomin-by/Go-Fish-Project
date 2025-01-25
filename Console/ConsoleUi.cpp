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
		std::cout << player->Name() << " говорит, что у него есть карта(ы) этого типа";
	if(answer)
		std::cout << player->Name() << " говорит, что у него нет карт этого типа";
}

void ConsoleUI::ShowCountRequest(int count, Type type, Player* player) {

}

void ConsoleUI::ShowCountResponse(bool answer, Player* player) {
    if(answer)
		std::cout << player->Name() << " говорит, что у него именно столько карт этого типа";
	if(answer)
		std::cout << player->Name() << " говорит, что у него другое количество карт этого типа";
}

void ConsoleUI::ShowSuitRequest(Type type, const std::vector<Suit>& cards, Player* player) {

}

void ConsoleUI::ShowSuitResponse(bool answer, Player* player) {
	if(answer)
		std::cout << player->Name() << " говорит, что у него именно эти масти!";
	if(answer)
		std::cout << player->Name() << " говорит, что у него другие масти!";
}
