// cpp file
// Contains player class

#include "Player.h"
#include "Game.h"

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

bool Player::TypeRequest(Type){

}
bool Player::CountRequest(int, Type){

}
bool Player::SuitRequest(Type, const std::vector<Suit>&){

}

//------------------------------------------------------------------------------

HumanPlayer::HumanPlayer(){

}

std::vector<GameCommand*> HumanPlayer::MakeTurn(const GameState&){                    					// Method which do turn of a player

}

//------------------------------------------------------------------------------

InternalComputerPlayer::InternalComputerPlayer(){

}

std::vector<GameCommand*> InternalComputerPlayer::MakeTurn(const GameState&){                    					// Method which do turn of a player

}

//------------------------------------------------------------------------------

ExternalComputerPlayer::ExternalComputerPlayer(){

}

std::vector<GameCommand*> ExternalComputerPlayer::MakeTurn(const GameState&){                    					// Method which do turn of a player

}

