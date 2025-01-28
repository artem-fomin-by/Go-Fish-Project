//---------------------------------------------------------------------------

#include <vector>
#include "CardAndDeck.h"
#include "Player.h"

#ifndef IntellegenceH
#define IntellegenceH
//---------------------------------------------------------------------------

struct turn{
	int player;
	Type type;
    int count;
	Suit suit;
};

class Intellegence {

	std::vector<Deck> peopleHave;
	std::vector<Deck> peopleDontHave;
	std::vector<Deck> peopleCanHave;
	std::vector<Deck> combinationsPeopleCantHave;
	Deck cardInGame;
	Deck myDeck;
	std::vector<int> countCard;
	std::vector<std::vector<std::vector<int>>> сountCardByType; 
	int me;

public:

	Intellegence();
    Intellegence(int, Deck);

	turn MekeTurn();
	void registrateTypeResponse(int, Type, bool);
	void registrateCountResponse(int, Type, int, bool);
	void registrateSuitResponse(int, int, Type, int, std::vector<Suit>, bool);
	void registrateUpdateDeck(int, int, Card);
	void registrateNewChest(int, Type);

//	const std::vector<Deck>& Decks() const;
	const int& Me() const;

//	std::vector<Deck> Decks();
    int Me();

};

#endif

