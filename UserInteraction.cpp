//---------------------------------------------------------------------------

#pragma hdrstop

#include "UserInteraction.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
UserInteraction::~UserInteraction(){ }

SystemUI::SystemUI(){}

void SystemUI::ShowTypeRequest(Type){ }
void SystemUI::ShowTypeResponse(bool){ }

void SystemUI::ShowCountRequest(int, Type){ }
void SystemUI::ShowCountResponse(bool){ }
void SystemUI::ShowSuitRequest(Type, const std::vector<Suit>&){ }
void SystemUI::ShowSuitResponse(bool){ }