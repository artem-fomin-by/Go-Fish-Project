// h file
// Contains player's classes

#include "CardAndDeck.h"
#include <string>

class Game;                                     // declarations of Game class
class UserInteraction;                          // declarations of UserInteraction class

//------------------------------------------------------------------------------

class Player{									// abstract class Player
private:
	Game* game;
	UserInteraction* userInteraction;
	Deck deck;
	std::string name;

protected:
	Player();                                   // Default constructor, doing nothing

public:
	virtual ~Player();                          // Default destructor, doing nothing

	virtual void MakeTurn() = 0;                // Method which do turn of a player
	virtual void MakeRequests() = 0;            // Method which ask another player

	const Deck& Deck() const;      				// Getter's method's
	const Game* Game() const;
	const std::string& Name() const;
	const UserInteraction* UserInteraction() const;

	class Deck& Deck();                  		// Setter's method's
	class Game* Game();
	std::string& Name();
	class UserInteraction* UserInteraction();
};

//------------------------------------------------------------------------------

class HumanPlayer : public Player{      		// HumanPlayer class
public:
	HumanPlayer();
	void MakeTurn();                    		// Method which do turn of a player
	void MakeRequests();                		// Method which ask another player
	void AsnwerRequest();               		// Method which answer the question
};

//------------------------------------------------------------------------------

class InternalComputerPlayer : public Player {  // InternalComputerPlayer class
    InternalComputerPlayer();
	void MakeTurn();                    		// Method which do turn of a player
	void MakeRequests();                		// Method which ask another player
	void AsnwerRequest();               		// Method which answer the question
};

//------------------------------------------------------------------------------

class ExternalComputerPlayer : public Player { 	// ExternalComputerPlayer class
    ExternalComputerPlayer();
	void MakeTurn();                   		 	// Method which do turn of a player
	void MakeRequests();                		// Method which ask another player
    void AsnwerRequest();               		// Method which answer the question
};
