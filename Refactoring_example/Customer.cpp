#include "Customer.h"

string Customer::statement() {
	double totalAmount = 0;
	int frequentRenterPoints = 0;
	string result = "������ " + getName() + "\n";

	for (auto& each : _rentals) {

		// ���������� �������� �����
		frequentRenterPoints++;

		// ����� �� ����������� ������ �������
		if ((each.getMovie().getPriceCode() == Movie::NEW_RELEASE) &&
			each.getDaysRented() > 1)
			frequentRenterPoints++;

		// ����� ����������� ��� ������� �������
		result += "\t" + each.getMovie().getTitle() + "\t" +
			to_string(each.getCharge()) + "\n";
		totalAmount += each.getCharge();
	}

	// ���������� �����������
	result += "����� �������������: " +
		to_string(totalAmount) + "\n";
	result += "�� ���������� " + to_string(frequentRenterPoints) +
		" �������� �����";
	return result;
}

