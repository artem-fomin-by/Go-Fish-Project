// cpp file
// Contains player class

#include "Player.h"

Player::Player(){

}

Player::~Player() {                          	// Default destructor, doing nothing

}

const Deck& Player::Deck() const {      			// Getter's method's
	return deck;
}

const Game* Player::Game() const{
	return game;
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

class Game* Player::Game() {
   return game;
}

std::string& Player::Name() {
	return name;
}

class UserInteraction* Player::UserInteraction(){
	return userInteraction;
}


//------------------------------------------------------------------------------

HumanPlayer::HumanPlayer(){

}

void HumanPlayer::MakeTurn() {                    					// Method which do turn of a player

}

void HumanPlayer::MakeRequests() {                					// Method which ask another player

}

void HumanPlayer::AsnwerRequest() {               					// Method which answer the question

}

//------------------------------------------------------------------------------

InternalComputerPlayer::InternalComputerPlayer(){

}

void InternalComputerPlayer::MakeTurn() {                    					// Method which do turn of a player

}

void InternalComputerPlayer::MakeRequests() {                					// Method which ask another player

}

void InternalComputerPlayer::AsnwerRequest() {               					// Method which answer the question

}

//------------------------------------------------------------------------------

ExternalComputerPlayer::ExternalComputerPlayer(){

}

void ExternalComputerPlayer::MakeTurn() {                    					// Method which do turn of a player

}

void ExternalComputerPlayer::MakeRequests() {                					// Method which ask another player

}

void ExternalComputerPlayer::AsnwerRequest() {               					// Method which answer the question

}
