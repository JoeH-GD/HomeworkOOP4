#include "Hand.h"
#include "Card.h"

void Hand::getCard(Card* newCardPointer)
{
	cardPointers.push_back(newCardPointer);
}

int Hand::getValue() const
{
	int valueSum = 0;
	for (size_t i = 0; i < cardPointers.size(); i++)
	{
		valueSum += cardPointers[i]->GetValue();
		if (valueSum <= 10 && cardPointers[i]->GetValue() == 1) valueSum += cardPointers[i]->GetValue() + 10;
	}

	return valueSum;

}

void Hand::clear()
{
	for (size_t i = cardPointers.size()-1; i >=0; i--)
	{
		cardPointers.pop_back();
	}
}
