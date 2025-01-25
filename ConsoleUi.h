// .h file
// contains Console UI classes

#include "UserInteraction.h"

class ConsoleUI : public UserInteraction {

public:
	ConsoleUI();

	void ShowTypeRequest(Type) override;
	void ShowTypeResponse(bool) override;

	void ShowCountRequest(int, Type) override;
	void ShowCountResponse(bool) override;

	void ShowSuitRequest(Type, const std::vector<Suit>&) override;
	void ShowSuitResponse(bool) override;
};
