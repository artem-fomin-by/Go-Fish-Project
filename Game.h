// h file
// consider main Game class

#include "Player.h"

class Game{                                        // Main Game class
private:
	Player* player1;
	Player* player2;
	Player* player3;
	Player* player4;

public:
	Game();                                        // Default constructure

	void MainLoop();                               // Main loop

	const Player* Player1() const;                 // Getter method's
	const Player* Player2() const;
	const Player* Player3() const;
	const Player* Player4() const;

	Player* Player1();                             // Setter method's
	Player* Player2();
	Player* Player3();
	Player* Player4();
};
