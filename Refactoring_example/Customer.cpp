#include "Customer.h"

string Customer::statement() {
	//int frequentRenterPoints = 0; //gettotalbnus
	string result = "Прокат " + getName() + "\n";

	for (auto& each : _rentals) {
		// Вывод результатов для каждого проката
		result += "\t" + each.getMovie().getTitle() + "\t" +
			to_string(each.getCharge()) + "\n";
		
	}

	// Добавление колонтитула
	result += "Сумма задолженности: " +
		to_string(getTotalAmount()) + "\n";
	result += "Вы заработали " + to_string(getTotalBonus()) +
		" бонусных очков";
	return result;
}

int Customer::getBonus(Rental& each) {
	return each.getBonusPoints();
}

double Customer::getTotalAmount() {

	double totalAmount = 0;
	for (auto& each : _rentals) {
		totalAmount += each.getCharge();
	}
	return totalAmount;
}
int Customer::getTotalBonus() {
	int frequentRenterPoints = 0;
	for (auto& each : _rentals) {
		frequentRenterPoints += each.getBonusPoints();
	}
	return frequentRenterPoints;
}



