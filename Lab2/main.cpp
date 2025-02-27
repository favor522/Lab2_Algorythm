#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

void gui();

void Task1() {
	cout << "Инициализация..." << '\n';
	ifstream task1;
	char Words[2048];
	char NewWords[2048];
	task1.open("C:\\Users\\User\\Desktop\\C++2kurs\\Algorythm and struct of data\\Lab2\\Lab2_Algorythm\\Words1.txt", ios::in);
	if (task1.is_open()) {
		cout << "Файл был успешно открыт" << '\n';
		if (task1.peek() == 0) {
			cout << "Файл пуст! Заполните его и перезапустите программу!" << '\n';
		}
		else {
			task1 >> Words;
			for (int i = 0; i < sizeof(Words); i++) {
				if (Words[i] != '<<' || Words[i] != ' >> ') {
					NewWords[i] = Words[i];
				}
			}
			task1.close();
			ofstream task1;
			task1.open("C:\\Users\\User\\Desktop\\C++2kurs\\Algorythm and struct of data\\Lab2\\Lab2_Algorythm\\Words1.txt", ios::out);
				task1 << NewWords;1
		}
	}
	else {
		cout << "Не удалось найти файл! Возможно, он был удалён или переименован" << '\n';
		gui();
	}
}

void Task2() {
	cout << "Инициализация..." << '\n';
	ifstream task2;
	task2.open("Telephones1.txt");
	if (task2.is_open()) {
		cout << "Файл был успешно открыт" << '\n';

	}
	else {
		cout << "Не удалось найти файл! Возможно, он был удалён или переименован" << '\n';
		gui();
	}
}

void gui() {
	string choose;
	cout << "Выберите действие: " << '\n';
	cout << "1. Задание на удаление всех переносов" << '\n';
	cout << "2. Задание на базу абонентов номеров" << '\n';
	cout << "3. Выйти" << '\n';
	cin >> choose;
	if (choose == "1") {
		cout << "Инициализация..." << '\n';
		Task1();
	}
	else if (choose == "2") {
		cout << "Инициализация..." << '\n';
	}
	else if (choose == "3") {
		exit;
	}
	else {
		cout << "Введено неверное действие, попробуйте ещё раз" << '\n';
		gui();
	}
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	gui();
	return 0;
}