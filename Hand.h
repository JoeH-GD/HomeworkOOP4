#pragma once
#include <vector>
#include "Card.h"

class Hand {
private:

	std::vector<Card*> cardPointers;

public:

	void getCard(Card* newCardPointer);

	void clear();

	int getValue() const;

};