#include "outputToConsole.h"

string EnterPassword() {
	string pass;
	char symbol;
	const char BACK_SPACE = 0;
	const char ENTER = 13;
	while (true) {
		symbol = _getch();
		if (symbol == ENTER) {
			break; 
		}
		else if (symbol == BACK_SPACE) {
			if (pass.size() > 0) {
				pass.pop_back();
				cout << "\b \b";
			}
		}
		else if (symbol > 31) {
			cout << "*";
			pass += symbol;
		}
		else {
			cout << "\b \b";
		}
	}
	cout << "\n";
	return pass;
}

void writeToConsole(ProductInfo* arrayOfData, Users* arrayOfUsers, int sizeArrayOfData, int sizeArrayOfUsers) {
	setlocale(LC_ALL, "Russian");
	cout << "1) ����� \n2) ������� ����� ������� \n3) ����� �� ������� \n";

	int choice;
	cout << "������� ��� �����: ";
	cin >> choice;

	switch (choice) {
		case 1: 
			int attempts = 3; // ���������� ������� � ������������
			while (attempts) {
				system("cls");
				
				string username, password;
				cout << "������� �����: "; cin >> username;
				cout << "������� ������: ";
				password = EnterPassword();

				if (isPasswordCorrect(password, username, arrayOfUsers, sizeArrayOfUsers) &&
					isUsernameCorrect(username, arrayOfUsers, sizeArrayOfUsers)) {
					break;
				}
				cout << "�������� ������ ��� �����, ���������� �������, � ��� �������� ������� " << attempts;
				--attempts;
			}

			if ()



	}

}
