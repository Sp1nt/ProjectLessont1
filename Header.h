#include <iostream>
#include <fstream>

using namespace std;

struct worker {
	char* firstName = new char[120];
	char* lastName = new char[120];
	char* number = new char[120];
	double salary;
};

void inputWorker(worker&);
void printWorker(const worker&);

//void addWorker();
void delWorker(worker*& workers, int& quantity);

void searchBySalaryRange(const worker* workers, int quantity, double minSalary, double maxSalary);


void printEmployeeList(const worker* workers, int quantity);
//void searchWorker(const worker);
//bool loadWorkerFromFile(const char* filename, worker* newWorker);
//
//
//bool saveWorkerToFile(const char* filename, const worker* newWorker);



bool onlyDigits(const char*); 
bool onlyLetters(const char*); 
bool numberOfCharacters(const char*); 