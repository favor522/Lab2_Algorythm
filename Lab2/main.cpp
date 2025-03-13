#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <locale>
#include <set>
#include <algorithm>
#include <sstream>
using namespace std;

void gui();
void AdditionalTask2();

void AdditionalTask1() {
	ofstream task1;
	string buffer;
	int n = 0;
	task1.open("Words2.txt", ios::app);
	
	for (int i = 0; i < 10; i++) {
		int number = rand()% 10 - 5;
		cout << number << " ";
		task1 << number << " ";
	}
	cout << '\n';
	task1.close();
	ifstream task11;
	task11.open("Words2.txt", ios::in);
	
	while (getline(task11, buffer)) {
		for (int i = 0; i < buffer.size(); i++) {
			if (buffer[i] == '-') {
				n++;
			}
		}
	}
	cout << "Всего чисел со знаком - встречено: " << n << '\n';
}

void Task1() {
	cout << "Инициализация..." << '\n';
	ifstream task1;
	string line;
	string NewWords = "";
	task1.open("Words1.txt", ios::in);
	if (task1.is_open()) {
		cout << "Файл был успешно открыт" << '\n';
		task1.seekg(0, ios::end);
		if (task1.tellg() == 0) {
			cout << "Файл пуст! Заполните его и перезапустите программу!" << '\n';
		}
		else {
			task1.seekg(0, ios::beg);
			while (getline(task1, line)) 
			{
				for (int i = 0; i < line.size(); i++) {
					if (line[i] != '<' && line[i] != '>') {
						NewWords += line[i];
						cout << line[i]<< '\n';
					}
				}
				NewWords += '\n';
			}

			task1.close();
			ofstream task1;
			task1.open("Words2.txt", ios::out);
			task1 << NewWords;
			task1.close();
			AdditionalTask1();
			AdditionalTask2();
		}
	}
	else {
		cout << "Не удалось найти файл! Возможно, он был удалён или переименован" << '\n';
		gui();
	}
}

void AdditionalTask2() {
	ifstream task2("Words2.txt");
	if (!task2.is_open()) {
		cout << "Не удалось открыть файл Words2.txt" << '\n';
		gui();
	}
	string line;
	set <string> uniqueWords; 
	while (getline(task2, line)) {
		stringstream ss(line); 
		string word;
		while (ss >> word) { 
			cout << word << " ";
			uniqueWords.insert(word);
		}
	}
	cout << '\n' << "Количество уникальных слов в файле Words2.txt: " << uniqueWords.size() << '\n';
	task2.close();
}

void Task2() {
	cout << "Инициализация..." << '\n';
	ifstream task2("Telephones.txt");
	if (task2.is_open()) {
		cout << "Файл был успешно открыт" << '\n';
		task2.seekg(0, ios::end);
		if (task2.tellg() == 0) {
			cout << "Файл пуст! Заполните его и перезапустите программу!" << '\n';
		}
		else {
			task2.seekg(0, ios::beg);
			string surname, line;
			string number, searchsurname = "";
			bool flag = false;
			cout << "Введите Фамилию искомого абонента" << '\n';
			cin >> surname;
			while (getline(task2, line)) {
				searchsurname.clear();
				number.clear();
				for (char c : line) {
					if ((c >= 'А' && c <= 'Я') || (c >= 'а' && c <= 'я')) {
						searchsurname += c;
					}
					else if ((c >= '0' && c <= '9') || c == '+') {
						number += c;
					}
					else {
						if (c == ' ') { continue; }
						cout << "Данные одного из абонентов поврежденны!" << '\n';
						cin.clear();
						break;
						}
				}
				if (surname == searchsurname) {
					cout << "Абонент: " << surname << " найден! Номер телефона: " << number << '\n';
					flag = true;
					break;
				}
			}
			if (!flag) {
				cout << "Абонент: " << surname << " не найден!" << '\n';
			}
		}
	}
	else {
		cout << "Не удалось найти файл! Возможно, он был удалён или переименован" << '\n';
		}
	gui();
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
		Task2();
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
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	gui();
	return 0;
}