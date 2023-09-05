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

		if (!onlyDigits(temp)) {
			newWorker.salary = stod(temp);
		}
	} while (newWorker.salary <= 0);
	
	cout << endl;
}


void printWorker(const worker& newWorker) {
	cout << "Name: " << newWorker.firstName << endl;
	cout << "Lastname: " << newWorker.lastName << endl;
	cout << "Number: " << newWorker.number << endl;
	cout << "salary: " << newWorker.salary << endl;
}

void addWorker(worker* oldWorker, int oldNumberWorker, int newNumberWorker) {
	int numberWorkers = oldNumberWorker + newNumberWorker; 
	worker* newAddWorker = new worker[numberWorkers];

	cout << "numberEmployees: " << numberWorkers << endl; // 3
	cout << "oldNumberEmployee: " << oldNumberWorker << endl; // 2
	cout << "newNumberEmployee: " << newNumberWorker << endl; // 1

	for (int i = 0; i < oldNumberWorker; i++) {
		newAddWorker[i] = oldWorker[i];
	}

	for (int i = oldNumberWorker; i < numberWorkers; i++) {
		inputWorker(newAddWorker[i]);
	}

	for (int i = 0; i <= newNumberWorker; i++) {
		printWorker(newAddWorker[i]);
	}

	cout << "Check100%" << endl;

	delete newAddWorker;
	newAddWorker = nullptr;
}

int compareStrings(char* a, char* b) {
	while (*a == *b) {
		++a;
		++b;
	}
	return *a - *b;
}

void sortByLastName(worker* sortLastName, int size) {

	cout << "Check 1" << endl;

	for (int i = 1; i < size; i++) {
		char* current = sortLastName[i].lastName;
		int j = i - 1;

		cout << "Check: " << sortLastName[i].lastName << endl;

		while (j >= 0 && compareStrings(sortLastName[j].lastName, current) > 0) {
			sortLastName[j + 1].lastName = sortLastName[j].lastName;
			--j;
		}

		sortLastName[j + 1].lastName = current;
	}

	cout << "Last check!" << endl;
}

void searchByLastName(const worker* workers, int quantity, const char* searchLastName) {
	bool found = false;

	for (int i = 0; i < quantity; i++) {
		if (strcmp(workers[i].lastName, searchLastName) == 0) {
			printWorker(workers[i]);
			cout << endl;
			found = true;
		}
	}

	if (!found) {
		cout << "Worker с фамилией " << searchLastName << " не найдены." << endl;
	}
}


void delWorker(worker* workers, int &quantity) {
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
char answ;
cout << "Are you sure you want delete this worker?(y/n)";
	cin >> answ;

	if (answ == 'y') {

	
delete[] workers[index].firstName;
delete[] workers[index].lastName;
delete[] workers[index].number;

for (int i = index; i < quantity - 1; i++) {
	workers[i] = workers[i + 1];
}

quantity--;
cout << "Worker deleted." << endl;
	}
	else {
		cout << "Deletion canceled" << endl;
	}
}

void searchBySalaryRange(const worker* workers, int quantity, double minSalary, double maxSalary) {
	bool found = false;

	
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