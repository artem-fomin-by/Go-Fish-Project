//---------------------------------------------------------------------------

#ifndef UserInteractionH
#define UserInteractionH
//---------------------------------------------------------------------------
#include "CardAndDeck.h"
//---------------------------------------------------------------------------
class UserInteraction
{
    public:
    virtual ~UserInteraction();
    
    virtual void ShowTypeRequest(Type) = 0;
    virtual void ShowTypeResponse(bool) = 0;    
    
    virtual void ShowCountRequest(int, Type) = 0;
    virtual void ShowCountResponse(bool) = 0;

    virtual void ShowSuitRequest(Type, const std::vector<Suit>&) = 0;
    virtual void ShowSuitResponse(bool) = 0;
};
//---------------------------------------------------------------------------
class SystemUI : public UserInteraction
{
    public:
    SystemUI();
    ~SystemUI();
    
    void ShowTypeRequest(Type) override;
	void ShowTypeResponse(bool) override;
    
	void ShowCountRequest(int, Type) override;
    void ShowCountResponse(bool) override;

    void ShowSuitRequest(Type, const std::vector<Suit>&) override;
    void ShowSuitResponse(bool) override;
};
//---------------------------------------------------------------------------
#endif
