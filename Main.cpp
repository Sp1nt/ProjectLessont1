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
        cout << "Меню:" << endl;
        cout << "1. Добавить сотрудника" << endl;
        cout << "2. Вывести информацию о всех сотрудниках" << endl;
        cout << "3. Поиск по фамилии" << endl;
        cout << "4. Поиск по диапазону зарплаты" << endl;
        cout << "5. Сортировка по фамилии" << endl;
        cout << "6. Удалить сотрудника" << endl;
        cout << "7. Загрузить данные из файла" << endl;
        cout << "8. Сохранить данные в файл" << endl;
        cout << "9. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore(); // Очистка буфера ввода

        switch (choice) {
        case '1': // Добавить сотрудника
            for (int i = 0; i < quantity; i++)
                inputWorker(newWorker[i]);
            cout << endl;
            break;
        case '2': // Вывести информацию о всех сотрудниках
            for (int i = 0; i < quantity; i++)
		printWorker(newWorker[i]);
	cout << endl;
            break;
        case '3': // Поиск по фамилии
        {
            char searchLastName[150];
            cout << "Введите фамилию для поиска: ";
            cin.ignore(); // Очистка буфера ввода перед считыванием строки
            cin.getline(searchLastName, sizeof(searchLastName));
            searchByLastName(newWorker, quantity, searchLastName);
        }
        break;

        
        case '4': // Поиск по диапазону зарплаты
        {
            double minSalary, maxSalary;
            cout << "Enter the minimum and maximum wages to search for: ";
            cin >> minSalary >> maxSalary;

            cout << "Result  searched:" << endl;
            searchBySalaryRange(newWorker, quantity, minSalary, maxSalary);
        }
        break;
        case '5': // Сортировка по фамилии
            sortByLastName(newWorker, quantity);
            break;
        case '6': // Удалить сотрудника
        {
            cout << "Index list worker:" << endl;
            printEmployeeList(newWorker, quantity);

            cout << endl << "Delete worker for index:" << endl;
            delWorker(newWorker, quantity);
        }
        break;
        case '7': // Загрузить данные из файла
            /*readFromFile(employees, employeeCount);*/
            break;
        case '8': // Сохранить данные в файл
            /*writeToFile(employees, employeeCount);*/
            break;
        case '9': // Выход
            /*cout << "Выход из программы." << endl;*/
            return 0;
        default:
            cout << "Неверный выбор, попробуйте снова." << endl;
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