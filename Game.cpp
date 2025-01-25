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

const std::function<bool(Type)>& GameState::getPlayer1TypeRequest() const{
    return player1TypeRequest;
}
const std::function<bool(Type)>& GameState::getPlayer2TypeRequest() const{
    return player2TypeRequest;
}
const std::function<bool(Type)>& GameState::getPlayer3TypeRequest() const{
    return player3TypeRequest;
}
const std::function<bool(Type)>& GameState::getPlayer4TypeRequest() const{
    return player4TypeRequest;
}

const std::function<bool(int, Type)>& GameState::getPlayer1CountRequest() const{
    return player1CountRequest;
}
const std::function<bool(int, Type)>& GameState::getPlayer2CountRequest() const{
    return player2CountRequest;
}
const std::function<bool(int, Type)>& GameState::getPlayer3CountRequest() const{
	return player3CountRequest;
}
const std::function<bool(int, Type)>& GameState::getPlayer4CountRequest() const{
    return player4CountRequest;
}

const std::function<bool(Type, const std::vector<Suit>&)>& GameState::getPlayer1SuitRequest() const{
    return player1SuitRequest;
}
const std::function<bool(Type, const std::vector<Suit>&)>& GameState::getPlayer2SuitRequest() const{
    return player2SuitRequest;
}
const std::function<bool(Type, const std::vector<Suit>&)>& GameState::getPlayer3SuitRequest() const{
    return player3SuitRequest;
}
const std::function<bool(Type, const std::vector<Suit>&)>& GameState::getPlayer4SuitRequest() const{
    return player4SuitRequest;
}

void GameState::setPlayer1TypeRequest(const std::function<bool(Type)>& callback){
    player1TypeRequest = callback;
}
void GameState::setPlayer2TypeRequest(const std::function<bool(Type)>& callback){
    player2TypeRequest = callback;
}
void GameState::setPlayer3TypeRequest(const std::function<bool(Type)>& callback){
    player3TypeRequest = callback;
}
void GameState::setPlayer4TypeRequest(const std::function<bool(Type)>& callback){
    player4TypeRequest = callback;
}

void GameState::setPlayer1CountRequest(const std::function<bool(int, Type)>& callback){
    player1CountRequest = callback;
}
void GameState::setPlayer2CountRequest(const std::function<bool(int, Type)>& callback){
    player2CountRequest = callback;
}
void GameState::setPlayer3CountRequest(const std::function<bool(int, Type)>& callback){
    player3CountRequest = callback;
}
void GameState::setPlayer4CountRequest(const std::function<bool(int, Type)>& callback){
    player4CountRequest = callback;
}

void GameState::setPlayer1SuitRequest(const std::function<bool(Type, const std::vector<Suit>&)>& callback){
    player1SuitRequest = callback;
}
void GameState::setPlayer2SuitRequest(const std::function<bool(Type, const std::vector<Suit>&)>& callback){
    player2SuitRequest = callback;
}
void GameState::setPlayer3SuitRequest(const std::function<bool(Type, const std::vector<Suit>&)>& callback){
    player3SuitRequest = callback;
}
void GameState::setPlayer4SuitRequest(const std::function<bool(Type, const std::vector<Suit>&)>& callback){
    player4SuitRequest = callback;
}

GameState::GameState(){

}

GameState::GameState(Player* player1, Player* player2, Player* player3, Player* player4){
    player1TypeRequest = player1->TypeRequest;
    player2TypeRequest = player2->TypeRequest;
    player3TypeRequest = player3->TypeRequest;
    player4TypeRequest = player4->TypeRequest;

    player1CountRequest = player1->CountRequest;
    player2CountRequest = player2->CountRequest;
    player3CountRequest = player3->CountRequest;
    player4CountRequest = player4->CountRequest;

    player1SuitRequest = player1->SuitRequest;
    player2SuitRequest = player2->SuitRequest;
    player3SuitRequest = player3->SuitRequest;
    player4SuitRequest = player4->SuitRequest;
}

