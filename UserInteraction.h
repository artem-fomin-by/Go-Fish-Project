//---------------------------------------------------------------------------

#ifndef UserInteractionH
#define UserInteractionH
//---------------------------------------------------------------------------
#include "CardAndDeck.h"
//---------------------------------------------------------------------------
class Player;


class UserInteraction
{
    public:
    virtual ~UserInteraction();
    
	virtual void ShowTypeRequest(Type, Player*) = 0;
	virtual void ShowTypeResponse(bool, Player*) = 0;
    
	virtual void ShowCountRequest(int, Type, Player*) = 0;
	virtual void ShowCountResponse(bool, Player*) = 0;

	virtual void ShowSuitRequest(Type, const std::vector<Suit>&, Player*) = 0;
	virtual void ShowSuitResponse(bool, Player*) = 0;
};
//---------------------------------------------------------------------------
class SystemUI : public UserInteraction
{
    public:
    SystemUI();
    ~SystemUI();
    
	void ShowTypeRequest(Type, Player*) override;
	void ShowTypeResponse(bool, Player*) override;
    
	void ShowCountRequest(int, Type, Player*) override;
	void ShowCountResponse(bool, Player*) override;

	void ShowSuitRequest(Type, const std::vector<Suit>&, Player*) override;
	void ShowSuitResponse(bool, Player*) override;
};
//---------------------------------------------------------------------------
#endif
