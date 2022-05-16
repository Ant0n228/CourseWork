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

void productTableOutput(ProductInfo* arrayOfProduct, int sizeArrayOfData) {
	cout << "|" << setw(2) << "#" << setw(2) << "|" << setw(2) << "���� ����� ������ ���������" << setw(2) << "|"
		<< setw(2) << "����� ����" << setw(2) << "|" << setw(2) << "�������� ��������" << setw(2) << "|"
		<< setw(2) << "���������� ���������� ������" << setw(2) << "|" << "��� ������������� �� ���� � ������ ����" << setw(2) << "|\n";
	for (int i = 0; i < sizeArrayOfData; i++) {
		cout << "--------------------------------------------------------------------------------------------";
		cout << "|" << setw(2) << i << setw(2) << "|" << setw(2) << arrayOfProduct[i].dayWhenProductCreate.day << "." <<
			arrayOfProduct[i].dayWhenProductCreate.month << "." << arrayOfProduct[i].dayWhenProductCreate.year << setw(2) << "|"
			<< setw(2) << arrayOfProduct[i].workShopNumber << setw(2) << "|" << setw(2) << arrayOfProduct[i].productName << setw(2) << "|"
			<< setw(2) << arrayOfProduct[i].numberOfProductsProduced << setw(2) << "|" << arrayOfProduct[i].responsiblePerson << setw(2) << "|\n";
	}
	cout << "--------------------------------------------------------------------------------------------";
}

void writeToConsole(ProductInfo* arrayOfProduct, Users* arrayOfUsers, int sizeArrayOfData, int sizeArrayOfUsers) {
	setlocale(LC_ALL, "Russian");
	cout << "1) ����� \n2) ������� ����� ������� \n3) ����� �� ������� \n";

	int choice;
	cout << "������� ��� �����: ";
	cin >> choice;

	switch (choice) {
		case 1: 
			int attempts = 3; // ���������� ������� � ������������
			string username, password;
			while (attempts > 0) {
				system("cls");
				
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

			if (isItAdmin(username, arrayOfUsers, sizeArrayOfUsers)) {

				productTableOutput(arrayOfProduct, sizeArrayOfData);
			}
			else {
				if (isAccess(username, arrayOfUsers, sizeArrayOfUsers)) {
					productTableOutput(arrayOfProduct, sizeArrayOfData); 
				}
			}


	}

}
