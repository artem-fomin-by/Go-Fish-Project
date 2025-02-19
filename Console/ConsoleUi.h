// .h file
// contains Console UI classes

#include "../UserInteraction.h"
#include "../GameUI.h"

class ConsoleUI : public UserInteraction {

public:
	ConsoleUI();

    void ShowWhoseTurnNow(Player*);

	void ShowTypeRequest(Type, Player*) override;
	void ShowTypeResponse(bool, Player*) override;

	void ShowCountRequest(int, Type, Player*) override;
	void ShowCountResponse(bool, Player*) override;

	void ShowSuitRequest(Type, const std::vector<Suit>&, Player*) override;
	void ShowSuitResponse(bool, Player*) override;

	void ShowNewBox(Type, Player*) override;
    void ShowCards(Player*);
};

class ConsoleGameUI : public GameUI {
public:
    ConsoleGameUI();
	void ShowWin(std::vector<Player*>) override;
    void ShowWhoseTurnNow(Player*) override;
};
