// .h file
// consists GameUI class

//---------------------------------------------------------------------------

#ifndef GameUIH
#define GameUIH
//---------------------------------------------------------------------------

#include <vector>
#include "Player.h"

class GameUI{
public:
    GameUI();
	virtual void ShowWin(std::vector<Player*>) = 0;
    virtual void ShowWhoseTurnNow(Player*) = 0;
};



class VisualGameUI : public GameUI{
public:
	VisualGameUI();
	void ShowWin(std::vector<Player*>) override;
    void ShowWhoseTurnNow(Player*) override;
};

#endif
