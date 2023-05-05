#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include <fstream>

using namespace std;

int _stateMenu;

const int MAX_CLIENT = 100;

struct CLIENT {	
	string surname;
	string name;
	string otch;
	string kval;
	string other;
	string prof;

	string pred;
	string d;
	string adress;
	int phone;
};

void Menu() {
	cout << "Выберите нужный пункт:" << endl
		<< "(1) Я Работодатель" << endl
		<< "(2) Я Соискатель" << endl
		<< "(3) Составить Соглашение(договор) между обеими сторонами" << endl
		<< "(4) Вывод клиентов" << endl
		<< "(5) Поиск клиентов по индексу" << endl
		<< "(6) Поиск фамилии клиента по подстроке" << endl
		<< "(7) Запись в файл" << endl
		<< "(8) Чтение из файла" << endl
		<< "(9) Удаление одного клиента" << endl
		<< "(10) Удаление всех клиентов" << endl
		<< "(11) Сортировка" << endl
		<< "Ваш выбор: ";
	cin >> _stateMenu;
}

void Rabotadat(CLIENT Guests[], int& ClientsCount) {
	setlocale(LC_ALL, "rus");

	if (ClientsCount < MAX_CLIENT) {
		cout << "Введите ваши данные:" << endl;
		cout << "(1) Название предприятия:	";
		cin >> Guests[ClientsCount].pred;
		cout << "(2) Вид деятельности:	";
		cin >> Guests[ClientsCount].d;
		cout << "(3) Адрес:	";
		cin >> Guests[ClientsCount].adress;
		cout << "(4) Телефон:	";
		cin >> Guests[ClientsCount].phone;

		cout << "Данные введены!" << endl << endl;

		ClientsCount++;
		system("cls");
		Menu();
	}
	else {
		cout << "The array is full" << endl;
	}
}

void Soisk(CLIENT Guests[], int& ClientsCount) {
	setlocale(LC_ALL, "rus");

	if (ClientsCount < MAX_CLIENT) {
		cout << "Введите ваши данные:" << endl;
		cout << "(1) Фамилия:	";
		cin >> Guests[ClientsCount].surname;
		cout << "(2) Имя:	";
		cin >> Guests[ClientsCount].name;
		cout << "(3) Отчество:	";
		cin >> Guests[ClientsCount].otch;
		cout << "(4) Кваливикация:	";
		cin >> Guests[ClientsCount].kval;
		cout << "(5) Профессия:	";
		cin >> Guests[ClientsCount].prof;
		cout << "(6) Иные данные:	";
		cin >> Guests[ClientsCount].other;

		cout << "Данные введены!" << endl << endl;

		ClientsCount++;
		system("pause");
		system("cls");
		Menu();
	}
	else {
		cout << "The array is full" << endl;
	}

}

void Dogovor() {
	setlocale(LC_ALL, "rus");
	string soisk, rabotodat, post, commission;

	cout << "Введите ваши данные:" << endl;
	cout << "(1) Кто является Соискателем:" ;
	cin >> soisk;
	cout << "(2) Кто является Работодателем:" ;
	cin >> rabotodat;
	cout << "(3) Должность Соискателя:" ;
	cin >> post;
	cout << "(4) Комиссионные бюро:" ;
	cin >> commission;

	cout << "Составлен договор между " << soisk << " и " << rabotodat << "!" << endl;
	system("pause");
	system("cls");
	Menu();
}

void printClients(CLIENT Clients[], int ClientsCount) {
	if (ClientsCount != 0) {
		for (int i = 0; i < ClientsCount; i++) {
			if (Clients[i].surname != "") {
				cout << "Соискатель: \n"
					<< "\tФИО:	" << Clients[i].surname << " " << Clients[i].name << " " << Clients[i].otch << endl
					<< "\tКваливикация:	" << Clients[i].kval << endl
					<< "\tПрофессия:	" << Clients[i].prof << endl
					<< "\tИные данные:	" << Clients[i].other << endl << endl;
			}
			else {
				cout << "Работодатель: \n";
				cout << "\tПредприятие:	"<< Clients[i].pred << endl 
					<< "\tДеятельность:	" << Clients[i].d << endl 
					<< "\tАдрес:	" << Clients[i].adress << endl 
					<< "\tТелефон:	" << Clients[i].phone << endl << endl;
			}
		}
	}
	else {
		cout << "Нет клиентов" << endl << endl;
	}
	system("pause");
	system("cls");
	Menu();
}

int searchClientIndex(CLIENT Clients[], int ClientsCount, string surname) {
	for (int i = 0; i < ClientsCount; i++) {
		if (Clients[i].surname == surname) {
			return i;
		}
		else {
			cout << "Клиент не найден" << endl << endl;
		}
	}
	return -1;
}

void searchClient(CLIENT Clients[], int ClientsCount) {
	int i;
	int index;

	if (ClientsCount != 0) {
		cout << "Введите индекс клиента для поиска: ";
		cin >> index;
		if (index != -1) {
			if (Clients[index].surname != "") {
				cout << "Соискатель: \n"
					<< "\tФИО:	" << Clients[index].surname << " " << Clients[index].name << " " << Clients[index].otch << endl << endl
					<< "\tКваливикация:	" << Clients[index].kval << endl
					<< "\tПрофессия:	" << Clients[index].prof << endl
					<< "\tИные данные:	" << Clients[index].other << endl;
			}
			else {
				cout << "Работодатель: \n";
				cout << "\tПредприятие:	"<< Clients[index].pred << endl
					<< "\tДеятельность:	" << Clients[index].d << endl
					<< "\tАдрес:	" << Clients[index].adress << endl
					<< "\tТелефон:	" << Clients[index].phone << endl << endl;
			}
		}
		else {
			cout << "Неверный индекс" << endl;
		}
	}
	else {
		cout << "Нет клиентов" << endl << endl;
	}
	
	system("pause");
	system("cls");
	Menu();
}

void writeToFile(CLIENT Clients[], int ClientsCount) {
	system("cls"); // очистка консоли

	int _write;
	cout << "Выберите\n" << "(1) Свой файл\n" << "(2) Файл 'Client.txt'\n\n";
	cin >> _write;

	string fileName;

	if (_write == 1) {
		cout << "Введите название файла:\n";
		cin >> fileName;

		ofstream fout(fileName);

		if (ClientsCount != 0) {
			for (int i = 0; i < ClientsCount; i++) {
				if (Clients[i].surname != "") {
					fout << "Соискатель: \n"
						<< "\tФИО:	" << Clients[i].surname << " " << Clients[i].name << " " << Clients[i].otch << endl
						<< "\tКваливикация:	" << Clients[i].kval << endl
						<< "\tПрофессия:	" << Clients[i].prof << endl
						<< "\tИные данные:	" << Clients[i].other << endl;
				}
				else {
					fout << "Работодатель: \n"
						<< "\tПредприятие:	" << Clients[i].pred << endl
						<< "\tДеятельность:	" << Clients[i].d << endl
						<< "\tАдрес:	" << Clients[i].adress << endl
						<< "\tТелефон:	" << Clients[i].phone << endl << endl;
				}
			}
			cout << "Данные записаны" << endl;
		}
		else {
			cout << "Нет клиентов" << endl << endl;
			fout << "Нет клиентов";
		}

		fout.close();
	}
	if (_write == 2) {
		ofstream fout("Client.txt");

		if (ClientsCount != 0) {
			for (int i = 0; i < ClientsCount; i++) {
				if (Clients[i].surname != "") {
					fout << "Соискатель: \n"
						<< "\tФИО:	" << Clients[i].surname << " " << Clients[i].name << " " << Clients[i].otch << endl
						<< "\tКваливикация:	" << Clients[i].kval << endl
						<< "\tПрофессия:	" << Clients[i].prof << endl
						<< "\tИные данные:	" << Clients[i].other << endl;
				}
				else {
					fout << "Работодатель: \n"
						<< "\tПредприятие:	" << Clients[i].pred << endl
						<< "\tДеятельность:	" << Clients[i].d << endl
						<< "\tАдрес:	" << Clients[i].adress << endl
						<< "\tТелефон:	" << Clients[i].phone << endl << endl;
				}
			}
			cout << "Данные записаны" << endl;
		}
		else {
			cout << "Нет клиентов" << endl << endl;
			fout << "Нет клиентов";
		}

		fout.close();
	}

	system("pause");
	system("cls");
	Menu();
}

void readFromFile(CLIENT Clients[], int& ClientsCount) {
	system("cls"); // очистка консоли

	int _read;
	cout << "Выберите\n" << "(1) Свой файл\n" << "(2) Файл 'Client.txt'\n\n";
	cin >> _read;

	string fileName;
	string line;


	if (_read == 1) {
		cout << "\nВведите название файла:\n";
		cin >> fileName;

		ifstream fin(fileName);

		if (!fin.is_open())
			cout << "\nНет файла с таким названием" << fileName << endl;

		cout << endl;
		while (getline(fin, line)) {
			cout << line << endl;
		}
		fin.close();
	}
	if (_read == 2) {
		ifstream fin("Client.txt");
		while (getline(fin, line)) {
			cout << line << endl;
		}
		fin.close();
	}

	cout << endl;

	system("pause");
	system("cls");
	Menu();
}

void deleteClients(CLIENT Clients[], int& ClientsCount) {
	string secondname;

	if (ClientsCount != 0) {
		cout << "Введите фамилию или название предприятия клиента:	";
		cin >> secondname;
		cout << endl;
		for (int i = 0; i < ClientsCount; i++) {
			if (Clients[i].surname == secondname || Clients[i].pred == secondname) {
				for (int j = i; j < ClientsCount - 1; j++) {
					Clients[j] = Clients[j + 1];
				}
				ClientsCount--;
				cout << "Клиент удален\n\n";
			}
		}
	}
	else {
		cout << "Нет клиентов\n\n";
	}

	system("pause");
	system("cls");
	Menu();
}

void deleteAllClients(CLIENT Clients[], int& ClientsCount) {

	if (ClientsCount != 0) {
		for (int i = 0; i < MAX_CLIENT; i++) {
			Clients[i].~CLIENT();
			ClientsCount = 0;
		}
		cout << "Все записи удалены\n\n";
	}
	else {
		cout << "Нет клиентов\n\n";
	}


	system("pause");
	system("cls");
	Menu();
}

void sortClients(CLIENT Clients[], int ClientsCount) {
	int _sort;
	bool sorted = false;

	if (ClientsCount != 0) {
		cout << "Выберите вид сортировки\n" << "(1) По убыванию\n" << "(2) По возрастанию\n";
		cin >> _sort;

		switch (_sort)
		{
		case 1:
			while (!sorted) {
				sorted = true;
				for (int i = 0; i < ClientsCount - 1; i++) {
					if (Clients[i].surname > Clients[i + 1].surname) {
						swap(Clients[i], Clients[i + 1]);
						sorted = false;
					}
				}
				/*
				for (int i = 0; i < ClientsCount - 1; i++) {
					if (Clients[i].pred > Clients[i + 1].pred) {
						swap(Clients[i], Clients[i + 1]);
						sorted = false;
					}
				}
				*/

			}
			cout << "Сортировка выполнена\n\n";
			break;
		case 2:
			while (!sorted) {
				sorted = true;
				for (int i = 0; i < ClientsCount - 1; i++) {
					if (Clients[i].surname < Clients[i + 1].surname) {
						swap(Clients[i], Clients[i + 1]);
						sorted = false;
					}
					/*
						if (Clients[i].pred < Clients[i + 1].pred) {
							swap(Clients[i], Clients[i + 1]);
							sorted = false;
						}
					*/

				}
			}
			cout << "Сортировка выполнена\n\n";
			break;
		default:
			break;
		}
	}
	else {
		cout << "Нет клиентов\n\n";
	}

	system("pause");
	system("cls");
	Menu();
}

void searchBySubstring(CLIENT Clients[], int& ClientsCount) {
	string substring;

	if (ClientsCount != 0) {
		cout << "Введите подстроку для поиска по фамилии: " << endl;
		cin >> substring;
		for (int i = 0; i < MAX_CLIENT; i++) {
			size_t posS = Clients[i].surname.find(substring);
			size_t posP = Clients[i].pred.find(substring);
			if (posS != string::npos || posP != string::npos) {
				if (Clients[i].surname != "") {
					cout << "Соискатель: \n"
						<< "\tФИО:	" << Clients[i].surname << " " << Clients[i].name << " " << Clients[i].otch << endl
						<< "\tКваливикация:	" << Clients[i].kval << endl
						<< "\tПрофессия:	" << Clients[i].prof << endl
						<< "\tИные данные:	" << Clients[i].other << endl;
				}
				else {
					cout << "Работодатель: \n"
						<< "\tПредприятие:	" << Clients[i].pred << endl
						<< "\tДеятельность:	" << Clients[i].d << endl
						<< "\tАдрес:	" << Clients[i].adress << endl
						<< "\tТелефон:	" << Clients[i].phone << endl << endl;
				}
			}
		}
	}
	else {
		cout << "Нет клиентов\n\n";
	}

	system("pause");
	system("cls");
	Menu();
}

//--------------------------------------

int main() {
	setlocale(LC_ALL, "ru");

	int ClientsCount = 0;
	CLIENT Clients[MAX_CLIENT];

	Menu();

	while (_stateMenu != 0) {

		switch (_stateMenu)
		{
		case 1:
			system("cls"); // очистка консоли
			cout << "Данные введены! \n" << endl;
			Rabotadat(Clients, ClientsCount);
			break;
		case 2:
			system("cls");
			cout << "Данные выведены! \n" << endl;
			Soisk(Clients, ClientsCount);
			break;
		case 3:
			system("cls");
			cout << "Заполнение договора! \n" << endl;
			Dogovor();
			break;
		case 4:
			system("cls");
			cout << "Данные введены! \n" << endl;
			printClients(Clients, ClientsCount);
			break;
		case 5:
			system("cls");
			cout << "Данные введены! \n" << endl;
			searchClient(Clients, ClientsCount);
			break;
		case 6:
			system("cls");
			cout << "Данные введены! \n" << endl;
			searchBySubstring(Clients, ClientsCount);
			break;
		case 7:
			system("cls");
			cout << "Данные введены! \n" << endl;
			writeToFile(Clients, ClientsCount);
			break;
		case 8:
			system("cls");
			cout << "Данные введены! \n" << endl;
			readFromFile(Clients, ClientsCount);
			break;
		case 9:
			system("cls");
			cout << "Данные введены! \n" << endl;
			deleteClients(Clients, ClientsCount);
			break;
		case 10:
			system("cls");
			cout << "Данные введены! \n" << endl;
			deleteAllClients(Clients, ClientsCount);
			break;
		case 11:
			system("cls");
			cout << "Данные введены! \n" << endl;
			sortClients(Clients, ClientsCount);
			break;
		default:
			system("cls");
			cout << "Неверно введен номер действия! \n" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		}
	}
}