// cpp file
// Contains player class

#include "Player.h"
#include "Game.h"
#include "UserInteraction.h"
#include <ctime>
#include <cstdlib>

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

std::vector<GameCommand*> HumanPlayer::MakeTurn(int){                    					// Method which do turn of a player

}

//------------------------------------------------------------------------------

InternalComputerPlayer::InternalComputerPlayer(){

}

void InternalComputerPlayer::MakeTurn(int indexOfPlayer){                    					// Method which do turn of a player
	std::vector<GameCommand*> commands;
	GameCommand* command;

    srand(time(nullptr));

    std::vector<Suit> suits = {Hearts, Spades, Diamonds, Clubs};
    std::vector<Type> types = {Two, Three, Four, Five, Six,	Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};

	int chosenPlayer = rand() % 3;

	if(chosenPlayer == indexOfPlayer)
		chosenPlayer++;

	Type chosenType = types[rand() % 13];

	bool response;

	Player chosenPlayer;

	switch (chosenPlayer) {
		case 0:
			chosenPlayer = Game->Player1();
			break;
		case 1:
			chosenPlayer = Game->Player2();
			break;
		case 2:
			chosenPlayer = Game->Player3();
			break;
		case 3:
			chosenPlayer = Game->Player4();
            break;
	}

	response = chosenPlayer->TypeRequest(chosenType);
	if(!response)
        return;
}

//------------------------------------------------------------------------------

ExternalComputerPlayer::ExternalComputerPlayer(){

}

std::vector<GameCommand*> ExternalComputerPlayer::MakeTurn(int){                    					// Method which do turn of a player

}

