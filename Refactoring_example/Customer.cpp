#include "Customer.h"

string Customer::statement() {
	//int frequentRenterPoints = 0; //gettotalbnus
	string result = "������ " + getName() + "\n";

	for (auto& each : _rentals) {
		// ����� ����������� ��� ������� �������
		result += "\t" + each.getMovie().getTitle() + "\t" +
			to_string(each.getCharge()) + "\n";
		
	}

	// ���������� �����������
	result += "����� �������������: " +
		to_string(getTotalAmount()) + "\n";
	result += "�� ���������� " + to_string(getTotalBonus()) +
		" �������� �����";
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



