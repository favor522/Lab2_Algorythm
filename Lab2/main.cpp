#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

void gui();

void Task1() {
	cout << "�������������..." << '\n';
	ifstream task1;
	char Words[2048];
	char NewWords[2048];
	task1.open("C:\\Users\\User\\Desktop\\C++2kurs\\Algorythm and struct of data\\Lab2\\Lab2_Algorythm\\Words1.txt", ios::in);
	if (task1.is_open()) {
		cout << "���� ��� ������� ������" << '\n';
		if (task1.peek() == 0) {
			cout << "���� ����! ��������� ��� � ������������� ���������!" << '\n';
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
		cout << "�� ������� ����� ����! ��������, �� ��� ����� ��� ������������" << '\n';
		gui();
	}
}

void Task2() {
	cout << "�������������..." << '\n';
	ifstream task2;
	task2.open("Telephones1.txt");
	if (task2.is_open()) {
		cout << "���� ��� ������� ������" << '\n';

	}
	else {
		cout << "�� ������� ����� ����! ��������, �� ��� ����� ��� ������������" << '\n';
		gui();
	}
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
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	gui();
	return 0;
}