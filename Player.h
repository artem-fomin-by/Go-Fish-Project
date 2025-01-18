// h file
// Contains player's classes

#include "CardAndDeck.h"

class Game{ 									// delete after writing real class game

};

class UserInteraction{                          // delete after writing real UserInteraction class

};

//------------------------------------------------------------------------------

class Player{									// abstract class Player
private:
	Game& game;
	UserInteraction& usetInteraction;
	Deck deck;
	string name;

public:
	Player();                                   // Default constructor, doing nothing
	virtual ~Player();                          // Default destructor, doing nothing

	virtual void MakeTurn();                    // Method which do turn of a player
	virtual void MakeRequests();                // Method which ask another player

	const enum Deck& Deck() const;      		// Getter's method's
	const Game& Game() const;
	const string& Name() const;
	const UserInteraction& UserInteraction() const;

	enum Deck& Deck();                  		// Setter's method's
	Game& Game();
	string& Name();
	UserInteraction& UserInteraction();
};

//------------------------------------------------------------------------------

class HumanPlayer : public Player{      		// HumanPlayer class
public:
	void MakeTurn();                    		// Method which do turn of a player
	void MakeRequests();                		// Method which ask another player
	void AsnwerRequest();               		// Method which answer the question
};

//------------------------------------------------------------------------------

class InternalComputerPlayer : public Player {  // InternalComputerPlayer class
	void MakeTurn();                    		// Method which do turn of a player
	void MakeRequests();                		// Method which ask another player
	void AsnwerRequest();               		// Method which answer the question
};

//------------------------------------------------------------------------------

class ExternalComputerPlayer : public Player { 	// ExternalComputerPlayer class
	void MakeTurn();                   		 	// Method which do turn of a player
	void MakeRequests();                		// Method which ask another player
    void AsnwerRequest();               		// Method which answer the question
};
