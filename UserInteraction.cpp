//---------------------------------------------------------------------------

#pragma hdrstop

#include "UserInteraction.h"
#include "Player.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
UserInteraction::~UserInteraction(){ }

SystemUI::SystemUI(){}

void SystemUI::ShowTypeRequest(Type, Player*){ }
void SystemUI::ShowTypeResponse(bool, Player*){ }

void SystemUI::ShowCountRequest(int, Type, Player*){ }
void SystemUI::ShowCountResponse(bool, Player*){ }
void SystemUI::ShowSuitRequest(Type, const std::vector<Suit>&, Player*){ }
void SystemUI::ShowSuitResponse(bool, Player*){ }
