// h file
// Contains player's classes

#ifndef PlayerH
#define PlayerH

#include "CardAndDeck.h"
#include <string>
#include "GameCommands.h"
#include "UserInteraction.h"
#include "Intellegence.h"

class Game;

//------------------------------------------------------------------------------

class Player{									// abstract class Player
protected:
	Deck deck;
	std::string name;
    Game* game;
	UserInteraction* userInteraction;
	Player();							  // Default constructor, doing nothing
	int boxes;
	Intellegence* intellegence;


public:
	virtual ~Player();                          // Default destructor, doing nothing

	virtual bool MakeTurn(int&) = 0;                // Method which do turn of a player
	bool TypeRequest(Type);
	bool CountRequest(int, Type);
	bool SuitRequest(Type, const std::vector<Suit>&);

	const Deck& Deck() const;   
	const std::string& Name() const;
	const UserInteraction* UserInteraction() const;
	const Intellegence* Intellegence() const;
	const int& Boxes() const;
    const Game* Game() const;

    int& Boxes();
	class Deck& Deck();
	std::string& Name();
	class UserInteraction*& UserInteraction();
    class Intellegence*& Intellegence();
    class Game*& Game();

    int IsHaveBox();
};

//------------------------------------------------------------------------------

class HumanPlayer : public Player{      		// HumanPlayer class
public:
	HumanPlayer();
	bool MakeTurn(int&) override;                    		// Method which do turn of a player              		// Method which answer the question
};

//------------------------------------------------------------------------------

class InternalComputerPlayer : public Player {  // InternalComputerPlayer class
public:
	InternalComputerPlayer();
	bool MakeTurn(int&) override;                    		// Method which do turn of a player           		// Method which answer the question
};

//------------------------------------------------------------------------------

class ExternalComputerPlayer : public Player { 	// ExternalComputerPlayer class
public:
	ExternalComputerPlayer();
	bool MakeTurn(int&) override;                   		 	// Method which do turn of a player     		// Method which answer the question
};
#endif

