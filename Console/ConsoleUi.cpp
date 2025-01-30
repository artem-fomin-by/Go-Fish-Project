// .cpp file
// consists ConsoleUI classes

#include "ConsoleUi.h"
#include <string>
#include <iostream>
#include <algorithm>

std::string TypeTranslator(Type type){
	switch(type){
		case Two:
			return "������";
			break;
		case Three:
			return "������";
			break;
		case Four:
			return "�������";
			break;
		case Five:
			return "������";
			break;
		case Six:
			return "�������";
			break;
		case Seven:
			return "������";
			break;
		case Eight:
			return "��������";
			break;
		case Nine:
			return "�������";
			break;
		case Ten:
			return "�������";
			break;
		case Jack:
			return "������";
			break;
		case Queen:
			return "����";
			break;
		case King:
			return "������";
			break;
		case Ace:
			return "����";
			break;
	}
}

std::string SuitTranslator(Suit suit){
    switch(suit){
		case Hearts:
			return "�����";
			break;
		case Spades:
			return "����";
			break;
		case Diamonds:
			return "����";
			break;
		case Clubs:
			return "������";
	}
}


ConsoleUI::ConsoleUI(){

}

void ConsoleUI::ShowWhoseTurnNow(Player* player){
	std::cout << "\n������ ����� " + player->Name() << '\n';
}

void ConsoleUI::ShowTypeRequest(Type type, Player* player) {
	std::cout << "���������� ���� �� � " << player->Name() << " " << TypeTranslator(type) << '\n';
}

void ConsoleUI::ShowTypeResponse(bool answer, Player* player) {
	if(answer)
		std::cout << player->Name() << " �������, ��� � ���� ���� �����(�) ����� ����\n";
	else
		std::cout << player->Name() << " �������, ��� � ���� ��� ���� ����� ����\n";
}

void ConsoleUI::ShowCountRequest(int count, Type type, Player* player) {
	std::cout << "���������� � " << player->Name() << ", � ���� " << std::to_string(count) << ' ' << TypeTranslator(type) << '\n';
}

void ConsoleUI::ShowCountResponse(bool answer, Player* player) {
    if(answer)
		std::cout << player->Name() << " �������, ��� � ���� ������ ������� ���� ����� ����\n";
	else
		std::cout << player->Name() << " �������, ��� � ���� ������ ���������� ���� ����� ����\n";
}

void ConsoleUI::ShowSuitRequest(Type type, const std::vector<Suit>& cards, Player* player) {
	std::cout << "���������� � " << player->Name() << ", � ���� ";
	for(int i = 0; i < cards.size(); i++){
        std::cout << SuitTranslator(cards[i]) << ", ";
	}
	std::cout << "\n";
}

void ConsoleUI::ShowSuitResponse(bool answer, Player* player) {
	if(answer)
		std::cout << player->Name() << " �������, ��� � ���� ������ ��� �����!\n";
	else
		std::cout << player->Name() << " �������, ��� � ���� ������ �����\n";
}

void ConsoleUI::ShowNewBox(Type type, Player* player){
	std::cout << player->Name() << " ������ �������� �� " << TypeTranslator(type) << '\n';
}

void ConsoleUI::ShowCards(Player* player){
	std::cout << "\n���� �����: \n";
    sort(player->Deck().begin(), player->Deck().end());
	for(auto card : player->Deck()){
		std::cout << "\t" << TypeTranslator(card.Type()) << ' ' << SuitTranslator(card.Suit()) << '\n';
	}
}


ConsoleGameUI::ConsoleGameUI() { }

void ConsoleGameUI::ShowWin(std::vector<Player*> players) {
	std::cout << "\n���� ��������!\n��������: \n";
	for(auto i : players){
        std::cout << "\t" << i->Name() << ", " << i->Boxes() << " ���������" << '\n';
	}
}

void ConsoleGameUI::ShowWhoseTurnNow(Player* player){
	std::cout << "\n������ �����: " << player->Name() << "\n";
}

