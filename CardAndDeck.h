// h file
// Contains enum classes Suit and Type
// Also contains classes Card and Deck

#ifndef CardAndDeckH
#define CardAndDeckH

#include <vector>

enum Suit{
	Hearts,       //Черви
	Spades,       //Пики
	Diamonds,     //Бубы
	Clubs         //Крести
};

enum Type {
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	Ace
};

class Card{                            				 // Card class
private:

	Suit suit;
	Type type;

public:

	Card();                            		 		 // Default Construcor. Initialise based card (two of Hearts)
	Card(Suit, Type);                  		 		 // Initialize card with params
	const Suit& Suit() const;              		 	 // Getter method, returned Suit
	enum Suit& Suit();                                    // Setter method, seted Suit
	const Type& Type() const;              		 	 // Getter method, returned Type
	enum Type& Type();                                    // Setter method, seted Type
};

class Deck{                            		 		 // Deck class
private:

	std::vector<Card> deck;
	int size;

public:

	Deck();                           		 		 // Default constructor
	Deck(std::vector<Card>);          		 	 	 // Takes vector of
													 // Cards and initialize private fields
	void AddNewCard(Card);
	int GetSize();                     		 		 // Returned size of deck
	std::vector<Card> GetDeck();             		 // Returned vector of cards
	Card FindCardByIndex(int);         		 		 // Returned card by index
	int FindCardBySuit(Suit);          		 		 // Returned first index of card with taken suit
	int FindCardByType(Type);            	 		 // Returned first index of card with taken type
	int HaveCardWithTypeAndSuit(Type, Suit); 		 // Returned -1, if deck hasn't a card with taken type and suit and index of a card if else
	int CountOfCardsWithSuit(Suit);          		 // Returned count of cards with taken suit
	int CountOfCardsWithType(Type);          		 // Returned count of cards with taken type
	void PopCard(Type, Suit);
	std::vector<Card>::iterator begin();     		 // Returned begin iterator
	std::vector<Card>::reverse_iterator rbegin();    // Returned rbegin iterator
	std::vector<Card>::iterator end();         		 // Returned end iterator
	std::vector<Card>::reverse_iterator rend();      // Returned rend iterator
};
#endif

