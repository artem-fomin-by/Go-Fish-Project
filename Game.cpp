// cpp file
// contains main Game class

#include "Game.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>

Game::Game() {                                        	  // Default constructure

}

void Game::MainLoop() {                               // Main loop

}

void Game::StartGame(Player* player1, Player* player2, Player* player3, Player* player4) {
	this->player1 = player1;
	this->player2 = player2;
	this->player3 = player3;
	this->player4 = player4;

	std::vector<Suit> suits = {Hearts, Spades, Diamonds, Clubs};
    std::vector<Type> types = {Two, Three, Four, Five, Six,	Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};

	std::vector<Card> cards;

	for(int i = 0; i < 13; i++){
		for(int j = 0; j < 4; j++){
			cards.push_back(Card(suits[j], types[i]));
		}
	}

	srand(time(nullptr));

	std::random_shuffle(cards.begin(), cards.end());

    int indexOfCards = 0;

	for(int i = 0; i < 13; i++){
		player1->Deck().AddNewCard(cards[indexOfCards++]);
		player2->Deck().AddNewCard(cards[indexOfCards++]);
		player3->Deck().AddNewCard(cards[indexOfCards++]);
		player4->Deck().AddNewCard(cards[indexOfCards++]);
	}
}

const Player* Game::Player1() const {                 // Getter method's
    return player1;
}

const Player* Game::Player2() const {
    return player2;
}

const Player* Game::Player3() const {
    return player3;
}

const Player* Game::Player4() const {
    return player4;
}

Player* Game::Player1() {                             // Setter method's
    return player1;
}

Player* Game::Player2() {
    return player2;
}

Player* Game::Player3() {
	return player3;
}

Player* Game::Player4(){
    return player4;
}

