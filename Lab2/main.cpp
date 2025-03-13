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
	cout << "����� ����� �� ������ - ���������: " << n << '\n';
}

void Task1() {
	cout << "�������������..." << '\n';
	ifstream task1;
	string line;
	string NewWords = "";
	task1.open("Words1.txt", ios::in);
	if (task1.is_open()) {
		cout << "���� ��� ������� ������" << '\n';
		task1.seekg(0, ios::end);
		if (task1.tellg() == 0) {
			cout << "���� ����! ��������� ��� � ������������� ���������!" << '\n';
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
		cout << "�� ������� ����� ����! ��������, �� ��� ����� ��� ������������" << '\n';
		gui();
	}
}

void AdditionalTask2() {
	ifstream task2("Words2.txt");
	if (!task2.is_open()) {
		cout << "�� ������� ������� ���� Words2.txt" << '\n';
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
	cout << '\n' << "���������� ���������� ���� � ����� Words2.txt: " << uniqueWords.size() << '\n';
	task2.close();
}

void Task2() {
	cout << "�������������..." << '\n';
	ifstream task2("Telephones.txt");
	if (task2.is_open()) {
		cout << "���� ��� ������� ������" << '\n';
		task2.seekg(0, ios::end);
		if (task2.tellg() == 0) {
			cout << "���� ����! ��������� ��� � ������������� ���������!" << '\n';
		}
		else {
			task2.seekg(0, ios::beg);
			string surname, line;
			string number, searchsurname = "";
			bool flag = false;
			cout << "������� ������� �������� ��������" << '\n';
			cin >> surname;
			while (getline(task2, line)) {
				searchsurname.clear();
				number.clear();
				for (char c : line) {
					if ((c >= '�' && c <= '�') || (c >= '�' && c <= '�')) {
						searchsurname += c;
					}
					else if ((c >= '0' && c <= '9') || c == '+') {
						number += c;
					}
					else {
						if (c == ' ') { continue; }
						cout << "������ ������ �� ��������� �����������!" << '\n';
						cin.clear();
						break;
						}
				}
				if (surname == searchsurname) {
					cout << "�������: " << surname << " ������! ����� ��������: " << number << '\n';
					flag = true;
					break;
				}
			}
			if (!flag) {
				cout << "�������: " << surname << " �� ������!" << '\n';
			}
		}
	}
	else {
		cout << "�� ������� ����� ����! ��������, �� ��� ����� ��� ������������" << '\n';
		}
	gui();
}

void gui() {
	string choose;
	cout << "�������� ��������: " << '\n';
	cout << "1. ������� �� �������� ���� ���������" << '\n';
	cout << "2. ������� �� ���� ��������� �������" << '\n';
	cout << "3. �����" << '\n';
	cin >> choose;
	if (choose == "1") {
		cout << "�������������..." << '\n';
		Task1();
	}
	else if (choose == "2") {
		cout << "�������������..." << '\n';
		Task2();
	}
	else if (choose == "3") {
		exit;
	}
	else {
		cout << "������� �������� ��������, ���������� ��� ���" << '\n';
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