// cpp file
// Contains player class

#include "Player.h"

Player::Player() {                                   	// Default constructor, doing nothing

}

virtual Player::~Player() {                          	// Default destructor, doing nothing

}

const enum Deck& Player::Deck() const {      			// Getter's method's
	return deck;
}

const Game& Player::Game() const{
	return game;
}

const string& Player::Name() const {
	return name;
}

const UserInteraction& Player::UserInteraction() const {
	return userInteraction;
}

enum Deck& Player::Deck() {                  		  	// Setter's method's
	return deck;
}

Game& Player::Game() {
   return game;
}

string& Player::Name() {
	return name;
}

UserInteraction& Player::UserInteraction(){
	return userInteraction;
}


//------------------------------------------------------------------------------

void MakeTurn() {                    					// Method which do turn of a player

}

void MakeRequests() {                					// Method which ask another player

}

void AsnwerRequest() {               					// Method which answer the question

}

//------------------------------------------------------------------------------

void MakeTurn() {                    					// Method which do turn of a player

}

void MakeRequests() {                					// Method which ask another player

}

void AsnwerRequest() {               					// Method which answer the question

}

//------------------------------------------------------------------------------

void MakeTurn() {                    					// Method which do turn of a player

}

void MakeRequests() {                					// Method which ask another player

}

void AsnwerRequest() {               					// Method which answer the question

}
