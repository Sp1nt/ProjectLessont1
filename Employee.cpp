#include <iostream>
#include <string>
#include "header.h"

using namespace std;


void inputWorker(worker& newWorker) {
	char* temp = new char[126];

	do {
		cout << "name: ";
		cin >> newWorker.firstName;
	} while (onlyLetters(newWorker.firstName));

	do {
		cout << "lastName: ";
		cin >> newWorker.lastName;
	} while (onlyLetters(newWorker.lastName));

	do {
		cout << "Number: ";
		cin >> newWorker.number;
	} while (onlyDigits(newWorker.number) || numberOfCharacters(newWorker.number));



	do {
		cout << "Salary: ";
		cin >> temp;

		/*
		if (temp <= "0")
			cout << "×èñëî äîëæíî áûòü áîëüøå 0!" << endl << endl;
			*/
	} while (onlyDigits(temp));
	newWorker.salary = stod(temp);
}


void printWorker(const worker& newWorker) {
	cout << "Name: " << newWorker.firstName << endl;
	cout << "Lastname: " << newWorker.lastName << endl;
	cout << "Number: " << newWorker.number << endl;
	cout << "salary: " << newWorker.salary << endl;
}

void delWorker(worker*& workers, int& quantity) {
	if (quantity <= 0) {
		cout << "There are no worker to remove." << endl;
		return;
	}

	int index;
	cout << "Enter the worker index to delete (0-" << quantity - 1 << "): ";
	cin >> index;

	if (index < 0 || index >= quantity) {
		cout << "Invalid worker index." << endl;
		return;
	}

	delete[] workers[index].firstName;
	delete[] workers[index].lastName;
	delete[] workers[index].number;

	for (int i = index; i < quantity - 1; i++) {
		workers[i] = workers[i + 1];
	}

	quantity--;
	cout << "Worker deleted." << endl;
}

void searchBySalaryRange(const worker* workers, int quantity, double minSalary, double maxSalary) {
	bool found = false;

	cout << "Result  searched:" << endl;
	for (int i = 0; i < quantity; i++) {
		if (workers[i].salary >= minSalary && workers[i].salary <= maxSalary) {
			printWorker(workers[i]);
			cout << endl;
			found = true;
		}
	}

	if (!found) {
		cout << "Workers with salaries ranging from " << minSalary << " to " << maxSalary << " not found." << endl;
	}
}

bool onlyLetters(const char* content) { 
	for (int i = 0; i < strlen(content); i++) {
		if (isdigit(content[i])) {
			cout << "You wrong input symbol!" << endl << endl;
			return true;
		}
	}

	return false;
}
bool onlyDigits(const char* content) { 
	for (int i = 0; i < strlen(content); i++) {
		if (isalpha(content[i]) || content[i] == ' ') {
			cout << "You wrong input symbol!" << endl << endl;
			return true;
		}
	}

	return false;
}
bool numberOfCharacters(const char* content) { 
	if (strlen(content) < 8) {
		cout << "The length should not be less than 8 characters!" << endl << endl;
		return true;
	}
	else if (strlen(content) > 10) {
		cout << "The length should not be less than 10 characters!" << endl << endl;
		return true;
	}

	return false;
}

void printEmployeeList(const worker* workers, int quantity) {
	for (int i = 0; i < quantity; i++) {
		cout << "index: " << i << endl;
		printWorker(workers[i]);
		cout << endl;
	}
}