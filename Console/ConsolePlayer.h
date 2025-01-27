// .h file
// consists Console human Player class

#include "../Player.h"

class ConsoleHumanPlayer : public HumanPlayer {
public:
    ConsoleHumanPlayer();
	bool MakeTurn(int&) override;                    		// Method which do turn of a player
};
