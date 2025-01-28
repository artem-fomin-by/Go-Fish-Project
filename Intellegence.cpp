#include "Intellegence.h"
#include <algorithm>
#include <cmath>

int min(int a, int b){
	if(a < b)
		return a;
	return b;
}

Intellegence::Intellegence() {

}

Intellegence::Intellegence(int me, Deck deck) {
	std::vector<Suit> suits = {Hearts, Spades, Diamonds, Clubs};
	std::vector<Type> types = {Two, Three, Four, Five, Six,	Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};

	combinationsPeopleCantHave.resize(4);
	peopleHave.resize(4);
	peopleDontHave.resize(4);
	peopleCanHave.resize(4);
	//ñountCardByType.resize(4);

	this->me = me;
    myDeck = deck;
	peopleHave[me] = deck;

	for(auto i : types){
		for(auto j : suits){
			Card card(j, i);
			cardInGame.AddNewCard(card);
		}
	}

	for(int i = 0; i < 4; i++){
		if(i == me) {
			peopleDontHave[me] = cardInGame;
			for(auto card : peopleHave[me]){
				peopleDontHave[me].PopCard(card);
			}
		}
		else{
			peopleDontHave[i] = deck;
			peopleCanHave[i] = cardInGame;
			for(auto card : deck){
				peopleCanHave[i].PopCard(card);
			}
        }
	}
	//ñountCardByType
	ñountCardByType.resize(4, std::vector<std::vector<int>> (13, {1, 2, 3}));


	for(auto card : myDeck){
		for(int i = 0; i < 4; i++){
			if(i == me)
				continue;
			ñountCardByType[i][card.Type()].pop_back();
		}
	}
}

void Intellegence::registrateTypeResponse(int player, Type type, bool response) {
	std::vector<Suit> suits = {Hearts, Spades, Diamonds, Clubs};
	if(response || player == me) {
		return;
	}
	else {
        for(int i = 0; i < peopleCanHave[player].GetSize(); i++){
			if(peopleCanHave[player][i].Type() == type){
				peopleCanHave[player].PopCard(peopleCanHave[player][i].Type(), peopleCanHave[player][i].Suit());
				i--;
			}
		}
		for (int i = 0; i < 4; i++){
			if(peopleDontHave[player].HaveCardWithTypeAndSuit(type, suits[i]) == -1){
				peopleDontHave[player].AddNewCard(type, suits[i]);
			}
		}
		std::vector<int> mask(5, 0);
		while(mask[0] == 0){
			Deck newDeck;

			for(int i = 1; i < 5; i++){
				if(mask[i]){
					newDeck.AddNewCard(type, suits[i - 1]);
				}
			}

			if(find(combinationsPeopleCantHave.begin(), combinationsPeopleCantHave.end(), newDeck) == combinationsPeopleCantHave.end()){
				combinationsPeopleCantHave.push_back(newDeck);
			}

			mask[4]++;
			if(mask[4] == 2){
				mask[4] = 0;
				int i = 3;
				while(mask[i] == 1){
					mask[i] = 0;
					i--;
				}
			}
		}
		ñountCardByType[player][type].clear();
	}
}

void Intellegence::registrateCountResponse(int player, Type type, int count, bool response){
    std::vector<Suit> suits = {Hearts, Spades, Diamonds, Clubs};
	if(player == me)
        return;
	if(response){
    	std::vector<int> mask(5, 0);
		while(mask[0] == 0){
			Deck newDeck;

			for(int i = 1; i < 5; i++){
				if(mask[i]){
					newDeck.AddNewCard(type, suits[i - 1]);
				}
			}

			if(find(combinationsPeopleCantHave.begin(), combinationsPeopleCantHave.end(), newDeck) == combinationsPeopleCantHave.end() && newDeck.GetSize() != count){
				combinationsPeopleCantHave.push_back(newDeck);
			}

			mask[4]++;
			if(mask[4] == 2){
				mask[4] = 0;
				int i = 3;
				while(mask[i] == 1){
					mask[i] = 0;
					i--;
				}
			}
		}
		ñountCardByType[player][type].clear();
        ñountCardByType[player][type].push_back(count);
	}
	else{
    	auto it = find(ñountCardByType[player][type].begin(), ñountCardByType[player][type].end(), count);
		if(it != ñountCardByType[player][type].end())
			ñountCardByType[player][type].erase(it);
    }
}

void Intellegence::registrateSuitResponse(int player1, int player2, Type type, int count, std::vector<Suit> suit, bool response){
    std::vector<Suit> suits = {Hearts, Spades, Diamonds, Clubs};
	if(response){
		if(player1 != me) {
			for(int i = 0; i < suit.size(); i++){
				if(peopleHave[player1].HaveCardWithTypeAndSuit(type, suit[i]) != -1){
					peopleHave[player1].PopCard(type, suit[i - 1]);
				}
				if(peopleCanHave[player1].HaveCardWithTypeAndSuit(type, suit[i]) != -1){
					peopleCanHave[player1].PopCard(type, suit[i - 1]);
				}
				peopleDontHave[player1].AddNewCard(type, suit[i - 1]);
			}
			ñountCardByType[player1][type].clear();
			std::vector<int> mask(5, 0);
			while(mask[0] == 0){
				Deck newDeck;

				for(int i = 1; i < 5; i++){
					if(mask[i]){
						newDeck.AddNewCard(type, suits[i - 1]);
					}
				}

				if(find(combinationsPeopleCantHave.begin(), combinationsPeopleCantHave.end(), newDeck) == combinationsPeopleCantHave.end()){
					combinationsPeopleCantHave.push_back(newDeck);
				}

				mask[4]++;
				if(mask[4] == 2){
					mask[4] = 0;
					int i = 3;
					while(mask[i] == 1){
						mask[i] = 0;
						i--;
					}
				}
			}
		}
		else
			for(int i = 0; i < suit.size(); i++)
                myDeck.PopCard(type, suit[i]);

		if(player2 != me){
			for(int i = 0; i < suit.size(); i++){
				if(peopleDontHave[player2].HaveCardWithTypeAndSuit(type, suit[i]) != -1){
					peopleDontHave[player2].PopCard(type, suit[i - 1]);
				}
				if(peopleCanHave[player2].HaveCardWithTypeAndSuit(type, suit[i]) != -1){
					peopleCanHave[player2].PopCard(type, suit[i - 1]);
				}
				peopleHave[player2].AddNewCard(type, suit[i - 1]);
			}

			int maxCount = *ñountCardByType[player2][type].rbegin();

			for(int i = maxCount + 1; i < min(4, maxCount + suit.size() + 1); i++)
				ñountCardByType[player2][type].push_back(i);

			for(int i = 0; i < combinationsPeopleCantHave.size(); i++){
				for(int j = 0; j < suit.size(); j++){
					if(combinationsPeopleCantHave[i].HaveCardWithTypeAndSuit(type, suit[i]) != -1){
						combinationsPeopleCantHave.erase(combinationsPeopleCantHave.begin() + i);
						i--;
						break;
					}
				}
			}
		}
		else
			for(int i = 0; i < suit.size(); i++)
				myDeck.AddNewCard(type, suit[i]);
	}
	else{
		if(me == player1)
			return;
		if(suit.size() == 1){
			peopleDontHave[player1].AddNewCard(type, suit[0]);
			if(peopleCanHave[player1].HaveCardWithTypeAndSuit(type, suit[0]) != -1){
				peopleCanHave[player1].PopCard(type, suit[0]);
			}
		}
        Deck newDeck;
		for(int i = 0; i < suit.size(); i++){
            newDeck.AddNewCard(type, suit[i]);
		}
        combinationsPeopleCantHave.push_back(newDeck);
    }
}
