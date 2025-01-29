// .cpp file
// consists ConsoleHumanPlayer class

#include "ConsolePlayer.h"
#include "../Game.h"
#include <algorithm>
#include <iostream>
#include <ConsoleUi.cpp>

ConsoleHumanPlayer::ConsoleHumanPlayer() {
    boxes = 0;
}

bool ConsoleHumanPlayer::MakeTurn(int& indexOfPlayer) {


	auto consoleUI = dynamic_cast<ConsoleUI*>(userInteraction);


	std::vector<Suit> suits = {Hearts, Spades, Diamonds, Clubs};
	std::vector<Type> types = {Two, Three, Four, Five, Six,	Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};

	consoleUI->ShowCards(this);
	int chosenPlayerInt = 5;

	std::vector<Player*> players = {game->Player1(), game->Player2(), game->Player3(), game->Player4()};

	int counter = 1;
	std::cout << '\n';
	for(int i = 0; i < 4; i++){
		if(indexOfPlayer == i)
			continue;
		std::cout << counter++ << " - " << players[i]->Name() << '\n';
	}
	std::cout << '\n';

	while(chosenPlayerInt >= 4){
		std::cout << "Введите номер игрока, которого хотите выбрать: ";
		std::cin >> chosenPlayerInt;
	}

	chosenPlayerInt--;

	if(chosenPlayerInt >= indexOfPlayer)
		chosenPlayerInt++;

	std::cout << '\n';
	for(int i = 0; i < 13; i++){
		std::cout << i + 1 << " - " << TypeTranslator(types[i]) << '\n';
	}
	std::cout << '\n';

	int chosenTypeInt = 14;

	while(chosenTypeInt > 13){
		std::cout << "Введите номер типа, про который вы хотите спросить: ";
		std::cin >> chosenTypeInt;
	}
	chosenTypeInt--;

	Type chosenType = types[chosenTypeInt];
	bool response;
	Player* chosenPlayer;

	//userInteraction->ShowTypeRequest(chosenType, chosenPlayer);

	switch (chosenPlayerInt) {
		case 0:
			chosenPlayer = game->Player1();
			break;
		case 1:
			chosenPlayer = game->Player2();
			break;
		case 2:
			chosenPlayer = game->Player3();
			break;
		case 3:
			chosenPlayer = game->Player4();
			break;
	}

	response = chosenPlayer->TypeRequest(chosenType);

	game->Player1()->Intellegence()->registrateTypeResponse(chosenPlayerInt, chosenType, response);
	game->Player2()->Intellegence()->registrateTypeResponse(chosenPlayerInt, chosenType, response);
	game->Player3()->Intellegence()->registrateTypeResponse(chosenPlayerInt, chosenType, response);
	game->Player4()->Intellegence()->registrateTypeResponse(chosenPlayerInt, chosenType, response);

	//userInteraction->ShowTypeResponse(response, chosenPlayer);
	if(!response){
		indexOfPlayer = (indexOfPlayer + 1) % 4;
		return false;
	}

	int chosenCount = 5;
	while(chosenCount > 4) {
		std::cout << "Введите количетво карт: ";
		std::cin >> chosenCount;
	}
	//chosenCount--;
	//userInteraction->ShowCountRequest(chosenCount, chosenType, chosenPlayer);
	response = chosenPlayer->CountRequest(chosenCount, chosenType);

	game->Player1()->Intellegence()->registrateCountResponse(chosenPlayerInt, chosenType, chosenCount, response);
	game->Player2()->Intellegence()->registrateCountResponse(chosenPlayerInt, chosenType, chosenCount, response);
	game->Player3()->Intellegence()->registrateCountResponse(chosenPlayerInt, chosenType, chosenCount, response);
	game->Player4()->Intellegence()->registrateCountResponse(chosenPlayerInt, chosenType, chosenCount, response);

	//userInteraction->ShowCountResponse(response, chosenPlayer);
	if(!response){
		indexOfPlayer = (indexOfPlayer + 1) % 4;
		return false;
	}

	std::cout << '\n';
	for(int i = 0; i < 4; i++){
		std::cout << i + 1 << " - " << SuitTranslator(suits[i]) << '\n';
	}
	std::cout << '\n';

	std::vector<Suit> chosenSuits;
	std::vector<int> chosenSuitsInt;

	for(int i = 0; i < chosenCount; i++){
		int nextChoise = 5;
		while(nextChoise > 4 && find(chosenSuitsInt.begin(), chosenSuitsInt.end(), nextChoise) == chosenSuitsInt.end()){
			std::cout << "Выберите номер масти: ";
			std::cin >> nextChoise;
		}
		chosenSuitsInt.push_back(nextChoise - 1);
	}

	for(int i = 0; i < chosenCount; i++)
		chosenSuits.push_back(suits[chosenSuitsInt[i]]);

	//userInteraction->ShowSuitRequest(chosenType, chosenSuits, chosenPlayer);
	response = chosenPlayer->SuitRequest(chosenType, chosenSuits);

	game->Player1()->Intellegence()->registrateSuitResponse(chosenPlayerInt, indexOfPlayer, chosenType, chosenCount, chosenSuits, response);
	game->Player2()->Intellegence()->registrateSuitResponse(chosenPlayerInt, indexOfPlayer, chosenType, chosenCount, chosenSuits, response);
	game->Player3()->Intellegence()->registrateSuitResponse(chosenPlayerInt, indexOfPlayer, chosenType, chosenCount, chosenSuits, response);
    game->Player4()->Intellegence()->registrateSuitResponse(chosenPlayerInt, indexOfPlayer, chosenType, chosenCount, chosenSuits, response);

	//userInteraction->ShowSuitResponse(response, chosenPlayer);
	if(!response){
		indexOfPlayer = (indexOfPlayer + 1) % 4;
		return false;
	}

	for(int i = 0; i < chosenCount; i++){
		chosenPlayer->Deck().PopCard(chosenType, chosenSuits[i]);
		Card card(chosenSuits[i], chosenType);
		deck.AddNewCard(card);
	}

	if(IsHaveBox() != -1){
    	box++;
		Type boxType = types[IsHaveBox()];
		userInteraction->ShowNewBox(boxType, this);

		game->Player1()->Intellegence()->registrateNewChest(indexOfPlayer, boxType);
		game->Player2()->Intellegence()->registrateNewChest(indexOfPlayer, boxType);
		game->Player3()->Intellegence()->registrateNewChest(indexOfPlayer, boxType);
		game->Player4()->Intellegence()->registrateNewChest(indexOfPlayer, boxType);

		for(int i = 0; i < deck.GetSize(); i++){
			if(deck[i].Type() == boxType){
				deck.PopCard(deck[i].Type(), deck[i].Suit());
				i--;
			}
		}
	}

	return false;
}
