#include "Intellegence.h"
#include <algorithm>
#include <cmath>
#include <iostream>

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

	enableTypes.resize(13, 1);
    peopleCanHaveType.resize(4, std::vector<bool> (13, 1));
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


    std::vector<int> cnt(13);

	for(auto card : myDeck){
		cnt[card.Type()]++;
	}

	for(int i = 0; i < 4; i++){
		if(i == me)
			continue;
		else {
			for(int t = 0; t < 13; t++){
				for(int j = 0; j < cnt[t] - 1; j++){
                    ñountCardByType[i][t].pop_back();
				}
			}
        }
	}
}

void Intellegence::registrateTypeResponse(int player, Type type, bool response) {
	std::vector<Suit> suits = {Hearts, Spades, Diamonds, Clubs};
	if(response || player == me) {
		return;
	}
	else {
        peopleCanHaveType[player][type] = 0;
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

			if(find(combinationsPeopleCantHave[player].begin(), combinationsPeopleCantHave[player].end(), newDeck) == combinationsPeopleCantHave[player].end()){
				combinationsPeopleCantHave[player].push_back(newDeck);
			}

			mask[4]++;
			if(mask[4] == 2){
				mask[4] = 0;
				int i = 3;
				while(mask[i] == 1){
					mask[i] = 0;
					i--;
				}
                mask[i] = 1;
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

			if(find(combinationsPeopleCantHave[player].begin(), combinationsPeopleCantHave[player].end(), newDeck) == combinationsPeopleCantHave[player].end() && newDeck.GetSize() != count){
				combinationsPeopleCantHave[player].push_back(newDeck);
			}

			mask[4]++;
			if(mask[4] == 2){
				mask[4] = 0;
				int i = 3;
				while(mask[i] == 1){
					mask[i] = 0;
					i--;
				}
                mask[i] = 1;
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
			peopleCanHaveType[player1][type] = 0;
            peopleCanHaveType[player2][type] = 1;
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

				if(find(combinationsPeopleCantHave[player1].begin(), combinationsPeopleCantHave[player1].end(), newDeck) == combinationsPeopleCantHave[player1].end()){
					combinationsPeopleCantHave[player1].push_back(newDeck);
				}

				mask[4]++;
				if(mask[4] == 2){
					mask[4] = 0;
					int i = 3;
					while(mask[i] == 1){
						mask[i] = 0;
						i--;
					}
                    mask[i] = 1;
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

			for(int i = 0; i < combinationsPeopleCantHave[player2].size(); i++){
				for(int j = 0; j < suit.size(); j++){
					if(combinationsPeopleCantHave[player2][i].HaveCardWithTypeAndSuit(type, suit[i]) != -1){
						combinationsPeopleCantHave[player2].erase(combinationsPeopleCantHave[player2].begin() + i);
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
        combinationsPeopleCantHave[player1].push_back(newDeck);
    }
}

void Intellegence::registrateNewChest(int player, Type type){
	std::vector<Suit> suits = {Hearts, Spades, Diamonds, Clubs};

	enableTypes[type] = 0;
    for(int i = 0; i < 4; i++){
        peopleCanHaveType[i][type] = 0;
	}

	if(player == me){
		for(auto i : suits){
            myDeck.PopCard(type, i);
		}
	}

	for(auto suit : suits) {
		if(peopleHave[player].HaveCardWithTypeAndSuit(type, suit) != -1)
            peopleHave[player].PopCard(type, suit);
		if(peopleCanHave[player].HaveCardWithTypeAndSuit(type, suit) != -1)
            peopleCanHave[player].PopCard(type, suit);
		if(peopleDontHave[player].HaveCardWithTypeAndSuit(type, suit) == -1)
            peopleDontHave[player].AddNewCard(type, suit);
        cardInGame.PopCard(type, suit);
	}
	ñountCardByType[player][type].clear();

	for(int i = 0; i < combinationsPeopleCantHave[player].size(); i++){
		if(combinationsPeopleCantHave[player][i].FindCardByType(type) != -1){
			combinationsPeopleCantHave[player].erase(combinationsPeopleCantHave[player].begin() + i);
            i--;
		}
	}
}

const int& Intellegence::Me() const{
    return me;
}

int& Intellegence::Me() {
    return me;
}

Turn Intellegence::MakeTurnEasy(){
	std::vector<Suit> suits = {Hearts, Spades, Diamonds, Clubs};
	std::vector<Type> types = {Two, Three, Four, Five, Six,	Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};

    Turn turn;

	std::vector<std::vector<Type>> counter(4);

	for(int p = 0; p < 4; p++){
		if(p == me)
			continue;
		for(int t = 0; t < 13; t++){
			if(!enableTypes[t])
                continue;
			if(ñountCardByType.size() == 1){
                counter[p].push_back(types[t]);
			}
		}
	}

	for(int p = 0; p < 4; p++){
		if(p == me)
			continue;
		for(int t = 0; t < counter[p].size(); t++){
			std::vector<Suit> suitsBuff = suits;
			for(auto card : myDeck){
				if(card.Type() == counter[p][t] && find(suitsBuff.begin(), suitsBuff.end(), card.Suit()) != suitsBuff.end()){
					suitsBuff.erase(find(suitsBuff.begin(), suitsBuff.end(), card.Suit()));
				}
			}
			for(auto card : peopleDontHave[p]) {
				if(card.Type() == counter[p][t] && find(suitsBuff.begin(), suitsBuff.end(), card.Suit()) != suitsBuff.end()){
                	suitsBuff.erase(find(suitsBuff.begin(), suitsBuff.end(), card.Suit()));
				}
			}
            for(int i = 0; i < 4; i++){
				if(me == i || i == p)
					continue;
				for(auto card : peopleHave[i]){
					if(card.Type() == turn.type && find(suitsBuff.begin(), suitsBuff.end(), card.Suit()) != suitsBuff.end()){
						suitsBuff.erase(find(suitsBuff.begin(), suitsBuff.end(), card.Suit()));
					}
				}
			}
            for(auto card : peopleHave[p]) {
				if(card.Type() == counter[p][t] && find(suitsBuff.begin(), suitsBuff.end(), card.Suit()) != suitsBuff.end()){
                	suitsBuff.erase(find(suitsBuff.begin(), suitsBuff.end(), card.Suit()));
				}
			}
			if(suitsBuff.size() < 2){
				turn.player = p;
				turn.count = ñountCardByType[p][t][0];
				turn.type = types[t];
				while(suitsBuff.size() > 0){
					turn.suit.push_back(*suitsBuff.rbegin());
                    suitsBuff.pop_back();
				}
				for(auto card : peopleHave[p]) {
					if(t == card.Type()){
						suitsBuff.push_back(card.Suit());
					}
				}
                return turn;
			}
		}
	}

	if(myDeck.GetSize() > 0){
		std::vector<int> cnt(13, 0);

		for(auto card : myDeck){
			cnt[card.Type()]++;
		}

		int maxType = 0;

		for(int i = 0; i < 13; i++){
			if(cnt[maxType] < cnt[i]){
                maxType = i;
			}
		}

		turn.type = types[maxType];
	}
	else{
		int t = rand() % 13;
        while(!enableTypes[t]) t = (t + 1) % 13;
    }

	//std::cout << turn.type << '\n';

	std::vector<int> players(4, 1);

	for(int i = 0; i < 4; i++){
		if(me == i){
			players[i] = 0;
		}
		else {
			players[i] = peopleCanHaveType[i][turn.type];
		}
	}

	int i = rand() % 4;
	while(!players[i]) i = (i + 1) % 4;
	turn.player = i;
//	std::cout << turn.player << ' ' << turn.type << ' ' << '\n';
//
//	std::cout << "-------------------------------------------------------------\n";
//
//	for(int i = 0; i < 4; i++){
//		for(int j = 0; j < 13; j++){
//			std::cout << j << " - ";
//			for(auto z : ñountCardByType[i][j]){
//				std::cout << z << ' ';
//			}
//			std::cout << '\n';
//		}
//		std::cout << "\n";
//	}
//
//	std::cout << "-------------------------------------------------------------\n";

	turn.count = ñountCardByType[turn.player][turn.type][rand() % ñountCardByType[turn.player][turn.type].size()];

	std::vector<Suit> suitsBuff = suits;
	int tcount = turn.count;
	for(auto card : myDeck){
		if(card.Type() == turn.type && find(suitsBuff.begin(), suitsBuff.end(), card.Suit()) != suitsBuff.end()){
			suitsBuff.erase(find(suitsBuff.begin(), suitsBuff.end(), card.Suit()));
		}
	}
	for(auto card : peopleDontHave[turn.player]) {
		if(card.Type() == turn.type && find(suitsBuff.begin(), suitsBuff.end(), card.Suit()) != suitsBuff.end()){
			suitsBuff.erase(find(suitsBuff.begin(), suitsBuff.end(), card.Suit()));
		}
	}
	for(int i = 0; i < 4; i++){
		if(me == i || i == turn.player)
			continue;
		for(auto card : peopleHave[i]){
			if(card.Type() == turn.type && find(suitsBuff.begin(), suitsBuff.end(), card.Suit()) != suitsBuff.end()){
				suitsBuff.erase(find(suitsBuff.begin(), suitsBuff.end(), card.Suit()));
			}
		}
	}
	for(auto card : peopleHave[turn.player]){
		if(card.Type() == turn.type && find(suitsBuff.begin(), suitsBuff.end(), card.Suit()) != suitsBuff.end()) {
			suitsBuff.erase(find(suitsBuff.begin(), suitsBuff.end(), card.Suit()));
			tcount--;
		}
	}

	if(suitsBuff.size() < 2){
		while(suitsBuff.size() > 0){
			turn.suit.push_back(*suitsBuff.rbegin());
			suitsBuff.pop_back();
		}
		for(auto card : peopleHave[turn.player]) {
			if(turn.type == card.Type()){
				suitsBuff.push_back(card.Suit());
			}
		}
		return turn;
	}

	else{
		std::vector<int> mask(suitsBuff.size() + 1, 0);
		std::vector<Deck> combinations;
		while(!mask[0]){
			int sum = 0;
			for(auto i : mask){
				sum += i;
			}
			if(sum == tcount){
				Deck newDeck;

				for(int i = 1; i <= suitsBuff.size(); i++){
					if(!mask[i])
						continue;
					Card card(suitsBuff[i - 1], turn.type);
					newDeck.AddNewCard(card);
				}
				combinations.push_back(newDeck);
			}

			mask[suitsBuff.size()]++;
			if(mask[suitsBuff.size()] == 2){
				mask[suitsBuff.size()] = 0;
				int i = suitsBuff.size() - 1;
				while(mask[i] == 1){
					mask[i] = 0;
					i--;
				}
                mask[i] = 1;
			}
		}
		for(auto deck : combinationsPeopleCantHave[turn.player]){
			auto it = find(combinations.begin(), combinations.end(), deck);
			if(it != combinations.end()){
				combinations.erase(it);
			}
		}
		int random = rand() % combinations.size();

		for(auto card : combinations[random]){
			turn.suit.push_back(card.Suit());
		}
		return turn;
	}
}
