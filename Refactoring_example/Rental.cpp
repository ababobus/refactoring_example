#include "Rental.h"

double Rental::getCharge()
{
	double result = 0;
	switch (getMovie().getPriceCode()) {
	case Movie::REGULAR:
		result += 2;

		if (getDaysRented() > 2)
			result += (getDaysRented() - 2) * 1.5;
		break;

	case Movie::NEW_RELEASE:
		result += getDaysRented() * 3;
		break;

	case Movie::CHILDREN:
		result += 1.5;
		if (getDaysRented() > 3)
			result += (getDaysRented() - 3) * 1.5;
		break;
	}
	return result;
}
int Rental::getBonusPoints() {

	int frequentRenterPoints = 0;
	frequentRenterPoints++;

	// Бонус за двухдневный прокат новинки
	if ((getMovie().getPriceCode() == Movie::NEW_RELEASE) &&
		getDaysRented() > 1)
		frequentRenterPoints++;
	return frequentRenterPoints;
}