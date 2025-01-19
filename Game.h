// h file
// consider main Game class

#include "CardAndDeck.h"
#include <functional>
#include <vector>

class Player;

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

class GameState
{
	std::function<bool(Type)> player1TypeRequest;
	std::function<bool(Type)> player2TypeRequest;
	std::function<bool(Type)> player3TypeRequest;
	std::function<bool(Type)> player4TypeRequest;

	std::function<bool(int)> player1CountRequest;
	std::function<bool(int)> player2CountRequest;
	std::function<bool(int)> player3CountRequest;
	std::function<bool(int)> player4CountRequest;

	std::function<bool(Type, const std::vector<Suit>&)> player1SuitRequest;
	std::function<bool(Type, const std::vector<Suit>&)> player2SuitRequest;
	std::function<bool(Type, const std::vector<Suit>&)> player3SutiRequest;
	std::function<bool(Type, const std::vector<Suit>&)> player4SuitRequest;

	const std::function<bool(Type)> getPlayer1TypeRequest() const;
	const std::function<bool(Type)> getPlayer2TypeRequest() const;
	const std::function<bool(Type)> getPlayer3TypeRequest() const;
	const std::function<bool(Type)> getPlayer4TypeRequest() const;

	const std::function<bool(int)> getPlayer1CountRequest() const;
	const std::function<bool(int)> getPlayer2CountRequest() const;
	const std::function<bool(int)> getPlayer3CountRequest() const;
	const std::function<bool(int)> getPlayer4CountRequest() const;

	const std::function<bool(Type, const std::vector<Suit>&)> getPlayer1SuitRequest() const;
	const std::function<bool(Type, const std::vector<Suit>&)> getPlayer2SuitRequest() const;
	const std::function<bool(Type, const std::vector<Suit>&)> getPlayer3SuitRequest() const;
	const std::function<bool(Type, const std::vector<Suit>&)> getPlayer4SuitRequest() const;

	void setPlayer1TypeRequest(const std::function<bool(Type)>&);
	void setPlayer2TypeRequest(const std::function<bool(Type)>&);
	void setPlayer3TypeRequest(const std::function<bool(Type)>&);
	void setPlayer4TypeRequest(const std::function<bool(Type)>&);

	void setPlayer1CountRequest(const std::function<bool(int)>&);
	void setPlayer2CountRequest(const std::function<bool(int)>&);
	void setPlayer3CountRequest(const std::function<bool(int)>&);
	void setPlayer4CountRequest(const std::function<bool(int)>&);

	void setPlayer1SuitRequest(const std::function<bool(Type, const std::vector<Suit>&)>&);
	void setPlayer2SuitRequest(const std::function<bool(Type, const std::vector<Suit>&)>&);
	void setPlayer3SuitRequest(const std::function<bool(Type, const std::vector<Suit>&)>&);
	void setPlayer4SuitRequest(const std::function<bool(Type, const std::vector<Suit>&)>&);

	public:
	GameState();
	GameState(Player* player1, Player* player2, Player* player3, Player* player4);

	__property const std::function<bool(Type)>& Player1TypeRequest = { read = getPlayer1TypeRequest, write = setPlayer1TypeRequest };
	__property const std::function<bool(Type)>& Player2TypeRequest = { read = getPlayer2TypeRequest, write = setPlayer2TypeRequest };
	__property const std::function<bool(Type)>& Player3TypeRequest = { read = getPlayer3TypeRequest, write = setPlayer3TypeRequest };
	__property const std::function<bool(Type)>& Player4TypeRequest = { read = getPlayer4TypeRequest, write = setPlayer4TypeRequest };

	__property const std::function<bool(int)>& Player1CountRequest = { read = getPlayer1CountRequest, write = setPlayer1CountRequest };
	__property const std::function<bool(int)>& Player2CountRequest = { read = getPlayer2CountRequest, write = setPlayer2CountRequest };
	__property const std::function<bool(int)>& Player3CountRequest = { read = getPlayer3CountRequest, write = setPlayer3CountRequest };
	__property const std::function<bool(int)>& Player4CountRequest = { read = getPlayer4CountRequest, write = setPlayer4CountRequest };

	__property const std::function<bool(Type, const std::vector<Suit>&)>& Player1SuitRequest = { read = getPlayer1SuitRequest, write = setPlayer1SuitRequest };
	__property const std::function<bool(Type, const std::vector<Suit>&)>& Player2SuitRequest = { read = getPlayer2SuitRequest, write = setPlayer2SuitRequest };
	__property const std::function<bool(Type, const std::vector<Suit>&)>& Player3SuitRequest = { read = getPlayer3SuitRequest, write = setPlayer3SuitRequest };
	__property const std::function<bool(Type, const std::vector<Suit>&)>& Player4SuitRequest = { read = getPlayer4SuitRequest, write = setPlayer4SuitRequest };
};
