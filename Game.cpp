// cpp file
// contains main Game class

#include "Game.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "Intellegence.h"

Game::Game() {                                        	  // Default constructure

}

void Game::MainLoop() {                               // Main loop
	std::vector<Player*> players = {player1, player2, player3, player4};

	while(true){
		//srand(time(nullptr));
        gameUI->ShowWhoseTurnNow(players[currentPlayer]);
		if(players[currentPlayer]->MakeTurn(currentPlayer))
			break;
		if(CheckEndOfGame() != -1){
			int maxCountOfBox = CheckEndOfGame();

            std::vector<Player*> winners;

			for(auto i : players){
				if(i->Boxes() == maxCountOfBox)
                    winners.push_back(i);
			}

			gameUI->ShowWin(winners);
            break;
		}
		//currentPlayer = (currentPlayer + 1) % 4;
	}
}

void Game::StartGame(Player* player1, Player* player2, Player* player3, Player* player4, UserInteraction* userInteraction, GameUI* gameUI) {
    srand(time(nullptr));
	player1->UserInteraction() = userInteraction;
	player2->UserInteraction() = userInteraction;
	player3->UserInteraction() = userInteraction;
	player4->UserInteraction() = userInteraction;

    player1->Game() = this;
	player2->Game() = this;
	player3->Game() = this;
	player4->Game() = this;

    currentPlayer = 0;
    this->gameUI = gameUI;

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

	auto Intellegence1 = new Intellegence(0, player1->Deck());
	auto Intellegence2 = new Intellegence(1, player2->Deck());
	auto Intellegence3 = new Intellegence(2, player3->Deck());
	auto Intellegence4 = new Intellegence(3, player4->Deck());

	player1->Intellegence() = Intellegence1;
	player2->Intellegence() = Intellegence2;
	player3->Intellegence() = Intellegence3;
	player4->Intellegence() = Intellegence4;

	this->player1 = player1;
	this->player2 = player2;
	this->player3 = player3;
	this->player4 = player4;

}

int Game::CheckEndOfGame(){
	std::vector<Player*> players = {player1, player2, player3, player4};

	for(auto i : players)
		if(i->Deck().GetSize() != 0)
            return -1;

	int maxOfBoxes = 0;
	for(int i = 0; i < 4; i++)
		if(players[maxOfBoxes]->Boxes() < players[i]->Boxes())
			maxOfBoxes = i;

    return maxOfBoxes;
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

