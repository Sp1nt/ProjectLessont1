#include <iostream>
#include "header.h"

using namespace std;

int main() {
	setlocale(0, "");

	// MENU

	int quantity = 0;

	cout << "n worker: ";
	cin >> quantity;

	worker* newWorker = new worker[quantity];

	for (int i = 0; i < quantity; i++)
		inputWorker(newWorker[i]);
	cout << endl;

	for (int i = 0; i < quantity; i++)
		printWorker(newWorker[i]);
	cout << endl;

	cout << "Index list worker:" << endl;
	printEmployeeList(newWorker, quantity);

	cout << endl << "Delete worker for index:" << endl;
	delWorker(newWorker, quantity);
	
	for (int i = 0; i < quantity; i++)
		printWorker(newWorker[i]);
	cout << endl;

	double minSalary, maxSalary;
	cout << "Enter the minimum and maximum wages to search for: ";
	cin >> minSalary >> maxSalary;

	cout << "Result  searched:" << endl;
	searchBySalaryRange(newWorker, quantity, minSalary, maxSalary);

	delete newWorker;
	newWorker = nullptr;

	return 0;
}