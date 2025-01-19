// h file
// Contains player's classes

#ifndef PlayerH
#define PlayerH

#include "CardAndDeck.h"
#include <string>
#include "GameCommands.h"

class UserInteraction;                          // declarations of UserInteraction class
class GameState;

//------------------------------------------------------------------------------

class Player{									// abstract class Player
private:
	UserInteraction* userInteraction;
	Deck deck;
	std::string name;

protected:
	Player();                                   // Default constructor, doing nothing

public:
	virtual ~Player();                          // Default destructor, doing nothing

	virtual std::vector<GameCommand*> MakeTurn(const GameState&) = 0;  
	              // Method which do turn of a player
	bool TypeRequest(Type);
	bool CountRequest(int, Type);
	bool SuitRequest(Type, const std::vector<Suit>&);

	const Deck& Deck() const;   
	const std::string& Name() const;
	const UserInteraction* UserInteraction() const;

	class Deck& Deck();
	std::string& Name();
	class UserInteraction* UserInteraction();
};

//------------------------------------------------------------------------------

class HumanPlayer : public Player{      		// HumanPlayer class
public:
	HumanPlayer();
	std::vector<GameCommand*> MakeTurn(const GameState&) override;                    		// Method which do turn of a player              		// Method which answer the question
};

//------------------------------------------------------------------------------

class InternalComputerPlayer : public Player {  // InternalComputerPlayer class
    InternalComputerPlayer();
	std::vector<GameCommand*> MakeTurn(const GameState&) override;                    		// Method which do turn of a player           		// Method which answer the question
};

//------------------------------------------------------------------------------

class ExternalComputerPlayer : public Player { 	// ExternalComputerPlayer class
    ExternalComputerPlayer();
	std::vector<GameCommand*> MakeTurn(const GameState&) override;                   		 	// Method which do turn of a player     		// Method which answer the question
};
#endif

