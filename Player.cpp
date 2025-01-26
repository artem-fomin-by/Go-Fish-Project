// cpp file
// Contains player class

#include "Player.h"
#include "Game.h"
#include "UserInteraction.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>

Player::Player(){

}

Player::~Player() {                          		// Default destructor, doing nothing

}

const Deck& Player::Deck() const {      			// Getter's method's
	return deck;
}

const std::string& Player::Name() const {
	return name;
}

const UserInteraction* Player::UserInteraction() const {
	return userInteraction;
}

class Deck& Player::Deck() {                  		  	// Setter's method's
	return deck;
}

std::string& Player::Name() {
	return name;
}

class UserInteraction* Player::UserInteraction(){
	return userInteraction;
}

bool Player::TypeRequest(Type t){
	auto res = deck.FindCardByType(t) >= 0;

	userInteraction->ShowTypeResponse(res, this);
	
	return res;
}

bool Player::CountRequest(int count, Type t){
	auto res = deck.CountOfCardsWithType(t) == count;
	
	userInteraction->ShowCountResponse(res, this);
	
	return res;
}

bool Player::SuitRequest(Type t, const std::vector<Suit>& suits){
	auto res = true;
	for(auto suit : suits){
		res &= deck.HaveCardWithTypeAndSuit(t, suit) >= 0;
	}

	userInteraction->ShowSuitResponse(res, this);

	return res;
}

//------------------------------------------------------------------------------

HumanPlayer::HumanPlayer(){

}

void HumanPlayer::MakeTurn(int){                    					// Method which do turn of a player

}

//------------------------------------------------------------------------------

InternalComputerPlayer::InternalComputerPlayer(){

}

void InternalComputerPlayer::MakeTurn(int indexOfPlayer){
	GameCommand* command;

    srand(time(nullptr));

    std::vector<Suit> suits = {Hearts, Spades, Diamonds, Clubs};
    std::vector<Type> types = {Two, Three, Four, Five, Six,	Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};

	while(true){
		int chosenPlayerInt = rand() % 3;

		if(chosenPlayerInt == indexOfPlayer)
			chosenPlayerInt++;

		Type chosenType = types[rand() % 13];
		bool response;
		Player* chosenPlayer;

        userInteraction->ShowTypeRequest(chosenType, chosenPlayer);

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
		userInteraction->ShowTypeResponse(response, chosenPlayer);
		if(!response)
			return;

		int chosenCount = rand() % 4;
		userInteraction->ShowCountRequest(chosenCount, chosenType, chosenPlayer);
		response = chosenPlayer->CountRequest(chosenCount, chosenType);
        userInteraction->ShowCountResponse(response, chosenPlayer);
		if(!response)
			return;

		std::vector<Suit> chosenSuits;
		std::vector<Suit> suitsBuff = suits;

		std::random_shuffle(suitsBuff.begin(), suitsBuff.end());

		for(int i = 0; i < chosenCount; i++)
			chosenSuits.push_back(suitsBuff[i]);

        userInteraction->ShowSuitRequest(chosenType, chosenSuits, chosenPlayer);
		response = chosenPlayer->SuitRequest(chosenType, chosenSuits);
        userInteraction->ShowSuitResponse(response, chosenPlayer);
		if(!response)
			return;

		for(int i = 0; i < chosenCount; i++){
			chosenPlayer->Deck().PopCard(chosenType, chosenSuits[i]);
			Card card(chosenSuits[i], chosenType);
			deck.AddNewCard(card);
		}
	}
}

//------------------------------------------------------------------------------

ExternalComputerPlayer::ExternalComputerPlayer(){

}

void ExternalComputerPlayer::MakeTurn(int){                    					// Method which do turn of a player

}

