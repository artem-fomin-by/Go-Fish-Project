// cpp file
// Contains enum classes Suit and Type
// Also contains classes Card and Deck

#include "CardAndDeck.h"

//Card methods

Card::Card(){                                    // Default Construcor. Initialise based card (two of Hearts)
	suit = Suit::Hearts;
    type = Type::Two;
}
Card::Card(enum Suit suit, enum Type type){      // Initialize card with params
	this->suit = suit;
    this->type = type;
}
const Suit& Card::Suit() const{               	 // Getter method, returned Suit
	return suit;
}
const Type& Card::Type() const{               	 // Getter method, returned Type
	return type;
}

enum Suit& Card::Suit() {               	 	 // Setter method, seted Suit
	return suit;
}
enum Type& Card::Type(){                   		 // Setter method, seted Type
    return type;
}


//---------------------------------------------------------------------------
// Deck methods

Deck::Deck(){                            		 // Default constructor
	size = 0;
}

Deck::Deck(std::vector<Card> deck){     		 // Takes vector of
	this->deck = deck;           		 		 // Cards and initialize private fields
	size = this->deck.size();
}

void Deck::AddNewCard(Card card){        		 // Push new card to Deck
	deck.push_back(card);
	size++;
}

int Deck::GetSize(){                     		 // Returned size of deck
	return size;
}

std::vector<Card> Deck::GetDeck(){            	 // Returned vector of cards
    return deck;
}

Card Deck::FindCardByIndex(int index){         	 // Returned card by index
	return deck[index];
}

int Deck::FindCardBySuit(Suit suit){          	 // Returned first index of card with taken suit
	for(int i = 0; i < size; i++)
		if(deck[i].Suit() == suit)
			return i;
}

int Deck::FindCardByType(Type type){              // Returned first index of card with taken type
	for(int i = 0; i < size; i++)
		if(deck[i].Type() == type)
            return i;
}

int Deck::HaveCardWithTypeAndSuit(Type type, Suit suit){  // Returned -1, if deck hasn't a card with taken type and suit and index of a card if else
    for(int i = 0; i < size; i++)
		if(deck[i].Type() == type && deck[i].Suit() == suit)
            return true;
}

int Deck::CountOfCardsWithSuit(Suit suit){       // Returned count of cards with taken suit
	int count = 0;
	for(int i = 0; i < size; i++)
		if(deck[i].Suit() == suit)
			count++;
    return count;
}

int Deck::CountOfCardsWithType(Type type){       // Returned count of cards with taken type
    int count = 0;
	for(int i = 0; i < size; i++)
		if(deck[i].Type() == type)
			count++;
    return count;
}

void Deck::PopCard(Type type, Suit suit){        // Pop card with taken type and suit
	for(int i = 0; i < size; i++){
		if(deck[i].Suit() == suit && deck[i].Type() == type){
			deck.erase(deck.begin() + i);
            return;
		}
	}
}

std::vector<Card>::iterator Deck::begin(){       // Returned begin iterator
    return deck.begin();
}

std::vector<Card>::reverse_iterator Deck::rbegin(){      // Returned rbegin iterator
	return deck.rbegin();
}

std::vector<Card>::iterator Deck::end(){         // Returned end iterator
    return deck.end();
}

std::vector<Card>::reverse_iterator Deck::rend(){        // Returned rend iterator
    return deck.rend();
}
