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

std::vector<GameCommand*> HumanPlayer::MakeTurn(const GameState&, int){                    					// Method which do turn of a player

}

//------------------------------------------------------------------------------

InternalComputerPlayer::InternalComputerPlayer(){

}

std::vector<GameCommand*> InternalComputerPlayer::MakeTurn(const GameState& gameState, int indexOfPlayer){                    					// Method which do turn of a player
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

	std::function<bool(Type)> TypeRequest;
	std::function<bool(int, Type)> CountRequest;
	std::function<bool(Type, std::vector<Suit>&)> SuitRequest;

	switch (chosenPlayer) {
		case 0:
			TypeRequest = gameState.Player1TypeRequest;
			CountRequest = gameState.Player1CountRequest;
			SuitRequest = gameState.Player1SuitRequest;
			break;
		case 1:
			TypeRequest = gameState.Player2TypeRequest;
			CountRequest = gameState.Player2CountRequest;
			SuitRequest = gameState.Player2SuitRequest;
			break;
		case 2:
			TypeRequest = gameState.Player3TypeRequest;
			CountRequest = gameState.Player3CountRequest;
			SuitRequest = gameState.Player3SuitRequest;
			break;
		case 3:
			TypeRequest = gameState.Player4TypeRequest;
			CountRequest = gameState.Player4CountRequest;
			SuitRequest = gameState.Player4SuitRequest;
            break;
	}

	response = TypeRequest(chosenType);
	if(!response)
		return commands;
}

//------------------------------------------------------------------------------

ExternalComputerPlayer::ExternalComputerPlayer(){

}

std::vector<GameCommand*> ExternalComputerPlayer::MakeTurn(const GameState&, int){                    					// Method which do turn of a player

}

