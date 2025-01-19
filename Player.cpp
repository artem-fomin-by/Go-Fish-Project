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

bool Player::TypeRequest(Type t){
	auto res = deck.FindCardByType(t) >= 0;
	
	//userInteraction->ShowTypeResponse(res);
	
	return res;
}
bool Player::CountRequest(int count, Type t){
	auto res = deck.CountOfCardsWithType(t) == count;
	
	//userInteraction->ShowCountResponse(res);
	
	return res;
}
bool Player::SuitRequest(Type t, const std::vector<Suit>& suits){
	auto res = true;
	for(auto suit : suits){
		res &= deck.HaveCardWithTypeAndSuit(t, suit) >= 0;
	}

	//userInteraction->ShowSuitResponse(res);

	return res;
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

