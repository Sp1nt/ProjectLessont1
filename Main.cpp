#include <iostream>
#include "header.h"

using namespace std;

int main() {
	setlocale(0, "");

	// MENU

	int quantity = 0;
	int newNumbWorker = 0;
	
	cout << "n worker: ";
	cin >> quantity;

	/*quantity = newNumbWorker;*/

	worker* newWorker = new worker[quantity];

    char choice;

    while (true) {
        cout << "����:" << endl;
        cout << "1. �������� ����������" << endl;
        cout << "2. ������� ���������� � ���� �����������" << endl;
        cout << "3. ����� �� �������" << endl;
        cout << "4. ����� �� ��������� ��������" << endl;
        cout << "5. ���������� �� �������" << endl;
        cout << "6. ������� ����������" << endl;
        cout << "7. ��������� ������ �� �����" << endl;
        cout << "8. ��������� ������ � ����" << endl;
        cout << "9. �����" << endl;
        cout << "�������� ��������: ";
        cin >> choice;
        cin.ignore(); // ������� ������ �����

        switch (choice) {
        case '1': // �������� ����������
            for (int i = 0; i < quantity; i++)
                inputWorker(newWorker[i]);
            cout << endl;
            break;
        case '2': // ������� ���������� � ���� �����������
            for (int i = 0; i < quantity; i++)
		printWorker(newWorker[i]);
	cout << endl;
            break;
        case '3': // ����� �� �������
        {
            char searchLastName[150];
            cout << "������� ������� ��� ������: ";
            cin.ignore(); // ������� ������ ����� ����� ����������� ������
            cin.getline(searchLastName, sizeof(searchLastName));
            searchByLastName(newWorker, quantity, searchLastName);
        }
        break;

        
        case '4': // ����� �� ��������� ��������
        {
            double minSalary, maxSalary;
            cout << "Enter the minimum and maximum wages to search for: ";
            cin >> minSalary >> maxSalary;

            cout << "Result  searched:" << endl;
            searchBySalaryRange(newWorker, quantity, minSalary, maxSalary);
        }
        break;
        case '5': // ���������� �� �������
            sortByLastName(newWorker, quantity);
            break;
        case '6': // ������� ����������
        {
            cout << "Index list worker:" << endl;
            printEmployeeList(newWorker, quantity);

            cout << endl << "Delete worker for index:" << endl;
            delWorker(newWorker, quantity);
        }
        break;
        case '7': // ��������� ������ �� �����
            /*readFromFile(employees, employeeCount);*/
            break;
        case '8': // ��������� ������ � ����
            /*writeToFile(employees, employeeCount);*/
            break;
        case '9': // �����
            /*cout << "����� �� ���������." << endl;*/
            return 0;
        default:
            cout << "�������� �����, ���������� �����." << endl;
        }
    }



	/*for (int i = 0; i < quantity; i++)
		inputWorker(newWorker[i]);
	cout << endl;

	for (int i = 0; i < quantity; i++)
		printWorker(newWorker[i]);
	cout << endl;

	cout << "add: ";
	cin >> quantity;
	for (int i = 0; i < quantity; i++) {
		addWorker(newWorker, newNumbWorker, quantity);

	}


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
	searchBySalaryRange(newWorker, quantity, minSalary, maxSalary);*/

	delete newWorker;
	newWorker = nullptr;

	return 0;
}