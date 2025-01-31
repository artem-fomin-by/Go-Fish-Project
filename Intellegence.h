//---------------------------------------------------------------------------

#include <vector>
#include "CardAndDeck.h"
#include "Player.h"
#include "Game.h"

#ifndef IntellegenceH
#define IntellegenceH
//---------------------------------------------------------------------------

struct Turn{
	int player;
	Type type;
    int count;
	std::vector<Suit> suit;
}; 

class Intellegence {

	std::vector<Deck> peopleHave;
	std::vector<Deck> peopleDontHave;
	std::vector<Deck> peopleCanHave;
	std::vector<std::vector<Deck>> combinationsPeopleCantHave;
	std::vector<std::vector<bool>> peopleCanHaveType;
	Deck cardInGame;
	std::vector<bool> enableTypes;
	Deck myDeck;
	std::vector<int> countCard;
	std::vector<std::vector<std::vector<int>>> сountCardByType; 
	int me;

public:

	Intellegence();
    Intellegence(int, Deck);

	Turn MakeTurnEasy();
	void registrateTypeResponse(int, Type, bool);
	void registrateCountResponse(int, Type, int, bool);
	void registrateSuitResponse(int, int, Type, int, std::vector<Suit>, bool);
//	void registrateUpdateDeck(int, int, Card);
	void registrateNewChest(int, Type);

//	const std::vector<Deck>& Decks() const;
	const int& Me() const;

//	std::vector<Deck> Decks();
    int& Me();

};

#endif

