#include <iostream>
#include <fstream>

using namespace std;

struct worker {
	char* firstName = new char[150];
	char* lastName = new char[150];
	char* number = new char[150];
	double salary;
};

//int* resizeArray(int*, int&, int);

void inputWorker(worker&);
void printWorker(const worker&);

void addWorker(worker*, int, int);

void delWorker(worker* workers, int& quantity);

int compareStrings(const char*, const char*);


void searchByLastName(const worker* workers, int quantity, const char* searchLastName);

void sortByLastName( worker*, int);

void searchBySalaryRange(const worker* workers, int quantity, double minSalary, double maxSalary);


void printEmployeeList(const worker* workers, int quantity);
void searchWorker(const worker);



bool onlyDigits(const char*); 
bool onlyLetters(const char*); 
bool numberOfCharacters(const char*); 