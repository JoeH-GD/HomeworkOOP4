#include "Card.h"

Card::Card(){

	mCurrentCardPoints = QUEEN;
}

void Card::Flip() {

	!isFaceUp ? isFaceUp = true : isFaceUp = false;
}

int Card::GetValue() const
{
	if (mCurrentCardPoints >= ACE && mCurrentCardPoints < KING) return mCurrentCardPoints;
	else return 10;
    
}
