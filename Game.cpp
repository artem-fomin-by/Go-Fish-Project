// cpp file
// contains main Game class

#include "Game.h"

Game::Game() {                                        	  // Default constructure

}

void Game::MainLoop() {                               // Main loop

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

