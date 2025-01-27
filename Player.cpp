// cpp file
// Contains player class

#include "Player.h"
#include "Game.h"
#include "UserInteraction.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>

Player::Player(){
	boxes = 0;
}

Player::~Player() {                          		// Default destructor, doing nothing

}

const Deck& Player::Deck() const {      			// Getter's method's
	return deck;
}

const std::string& Player::Name() const {
	return name;
}

class Deck& Player::Deck() {                  		  	// Setter's method's
	return deck;
}

std::string& Player::Name() {
	return name;
}

const UserInteraction* Player::UserInteraction() const {
	return userInteraction;
}

UserInteraction*& Player::UserInteraction() {
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

int Player::IsHaveBox() {
	std::vector<Type> types = {Two, Three, Four, Five, Six,	Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};
	std::vector<int> counter(13);

	for(auto i : deck)
        counter[i.Type()]++;

	for(int i = 0; i < 13; i++)
		if(counter[i] == 4)
			return i;
    return -1;
}

const int& Player::Boxes() const {
    return boxes;
}

int& Player::Boxes(){
    return boxes;
}

const Game* Player::Game() const{
    return game;
}

Game*& Player::Game(){
    return game;
}

//------------------------------------------------------------------------------

HumanPlayer::HumanPlayer(){
	boxes = 0;
}

bool HumanPlayer::MakeTurn(int&){                    					// Method which do turn of a player

}

//------------------------------------------------------------------------------

InternalComputerPlayer::InternalComputerPlayer(){
	boxes = 0;
}

bool InternalComputerPlayer::MakeTurn(int& indexOfPlayer){

	std::vector<Suit> suits = {Hearts, Spades, Diamonds, Clubs};
	std::vector<Type> types = {Two, Three, Four, Five, Six,	Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};

//	while(true){
	int chosenPlayerInt = rand() % 3;

	if(chosenPlayerInt == indexOfPlayer)
		chosenPlayerInt++;

	Type chosenType = types[rand() % 13];
	bool response;
	Player* chosenPlayer;

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
	userInteraction->ShowTypeRequest(chosenType, chosenPlayer);
	response = chosenPlayer->TypeRequest(chosenType);
	//userInteraction->ShowTypeResponse(response, chosenPlayer);
	if(!response){
		indexOfPlayer = (indexOfPlayer + 1) % 4;
		return false;
	}


	int chosenCount = rand() % 3 + 1;
	userInteraction->ShowCountRequest(chosenCount, chosenType, chosenPlayer);
	response = chosenPlayer->CountRequest(chosenCount, chosenType);
	//userInteraction->ShowCountResponse(response, chosenPlayer);
	if(!response){
		indexOfPlayer = (indexOfPlayer + 1) % 4;
		return false;
	}

	std::vector<Suit> chosenSuits;
	std::vector<Suit> suitsBuff = suits;

	std::random_shuffle(suitsBuff.begin(), suitsBuff.end());

	for(int i = 0; i < chosenCount; i++)
		chosenSuits.push_back(suitsBuff[i]);

	userInteraction->ShowSuitRequest(chosenType, chosenSuits, chosenPlayer);
	response = chosenPlayer->SuitRequest(chosenType, chosenSuits);
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
		Type boxType = types[IsHaveBox()];
		userInteraction->ShowNewBox(boxType, this);
		for(int i = 0; i < deck.GetSize(); i++){
			if(deck[i].Type() == boxType){
				deck.PopCard(deck[i].Type(), deck[i].Suit());
				i--;
			}
		}
	}
//	}
    return false;
}

//------------------------------------------------------------------------------

ExternalComputerPlayer::ExternalComputerPlayer(){
    boxes = 0;
}

bool ExternalComputerPlayer::MakeTurn(int&){                    					// Method which do turn of a player

}
