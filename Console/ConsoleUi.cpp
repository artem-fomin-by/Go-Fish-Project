// .cpp file
// consists ConsoleUI classes

#include "ConsoleUi.h"
#include <string>
#include <iostream>
#include <algorithm>

std::string TypeTranslator(Type type){
	switch(type){
		case Two:
			return "двойки";
			break;
		case Three:
			return "тройки";
			break;
		case Four:
			return "четвёрки";
			break;
		case Five:
			return "пятёрки";
			break;
		case Six:
			return "шестёрки";
			break;
		case Seven:
			return "семёрки";
			break;
		case Eight:
			return "восьмёрки";
			break;
		case Nine:
			return "девятки";
			break;
		case Ten:
			return "десятки";
			break;
		case Jack:
			return "вальты";
			break;
		case Queen:
			return "дамы";
			break;
		case King:
			return "короли";
			break;
		case Ace:
			return "тузы";
			break;
	}
}

std::string SuitTranslator(Suit suit){
    switch(suit){
		case Hearts:
			return "черви";
			break;
		case Spades:
			return "пики";
			break;
		case Diamonds:
			return "бубы";
			break;
		case Clubs:
			return "крести";
	}
}


ConsoleUI::ConsoleUI(){

}

void ConsoleUI::ShowWhoseTurnNow(Player* player){
	std::cout << "\nСейчас ходит " + player->Name() << '\n';
}

void ConsoleUI::ShowTypeRequest(Type type, Player* player) {
	std::cout << "Спрашивает есть ли у " << player->Name() << " " << TypeTranslator(type) << '\n';
}

void ConsoleUI::ShowTypeResponse(bool answer, Player* player) {
	if(answer)
		std::cout << player->Name() << " говорит, что у него есть карта(ы) этого типа\n";
	else
		std::cout << player->Name() << " говорит, что у него нет карт этого типа\n";
}

void ConsoleUI::ShowCountRequest(int count, Type type, Player* player) {
	std::cout << "Спрашивает у " << player->Name() << ", у него " << std::to_string(count) << ' ' << TypeTranslator(type) << '\n';
}

void ConsoleUI::ShowCountResponse(bool answer, Player* player) {
    if(answer)
		std::cout << player->Name() << " говорит, что у него именно столько карт этого типа\n";
	else
		std::cout << player->Name() << " говорит, что у него другое количество карт этого типа\n";
}

void ConsoleUI::ShowSuitRequest(Type type, const std::vector<Suit>& cards, Player* player) {
	std::cout << "Спрашивает у " << player->Name() << ", у него ";
	for(int i = 0; i < cards.size(); i++){
        std::cout << SuitTranslator(cards[i]) << ", ";
	}
	std::cout << "\n";
}

void ConsoleUI::ShowSuitResponse(bool answer, Player* player) {
	if(answer)
		std::cout << player->Name() << " говорит, что у него именно эти масти!\n";
	else
		std::cout << player->Name() << " говорит, что у него другие масти\n";
}

void ConsoleUI::ShowNewBox(Type type, Player* player){
	std::cout << player->Name() << " собрал сундучок из " << TypeTranslator(type) << '\n';
}

void ConsoleUI::ShowCards(Player* player){
	std::cout << "\nВаши карты: \n";
    sort(player->Deck().begin(), player->Deck().end());
	for(auto card : player->Deck()){
		std::cout << "\t" << TypeTranslator(card.Type()) << ' ' << SuitTranslator(card.Suit()) << '\n';
	}
}


ConsoleGameUI::ConsoleGameUI() { }

void ConsoleGameUI::ShowWin(std::vector<Player*> players) {
	std::cout << "\nИгра окончена!\nПобедили: \n";
	for(auto i : players){
        std::cout << "\t" << i->Name() << ", " << i->Boxes() << " Сундучков" << '\n';
	}
}

void ConsoleGameUI::ShowWhoseTurnNow(Player* player){
	std::cout << "\nСейчас ходит: " << player->Name() << "\n";
}

