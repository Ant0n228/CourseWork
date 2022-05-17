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

string validation(Users* arrayOfUsers, int sizeArrayOfUsers) {
	int attempts = 3; // ���������� ������� � ������������
	string username, password;
	while (true) {
		system("cls");

		cout << " ������� �����: "; cin >> username;
		cout << " ������� ������: ";
		password = EnterPassword();

		if (isPasswordCorrect(password, username, arrayOfUsers, sizeArrayOfUsers) &&
			isUsernameCorrect(username, arrayOfUsers, sizeArrayOfUsers)) {
			return username;
		}
		cout << " �������� ������ ��� �����, ���������� �������, � ��� �������� ������� " << attempts;
		--attempts;
		if (attempts == 0) {
			cout << " ��� ����� ��������";
			return;
		}
	}

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


void userTableOutput(Users* arrayOfUsers, int sizeArrayOfUsers) {
	cout << "|" << setw(2) << "#" << setw(2) << "|" << setw(2) << "��� ������������" << setw(2) << "|"
		<< setw(2) << "����" << setw(2) << "|" << setw(2) << "������" << setw(2) << "|\n";
	for (int i = 0; i < sizeArrayOfUsers; i++) {
		cout << "--------------------------------------------------------------------------------------------";
		cout << "|" << setw(2) << i << setw(2) << "|" << setw(2) << arrayOfUsers[i].nickname << setw(2) << "|"
			<< setw(2) << arrayOfUsers[i].role << setw(2) << "|" << setw(2) << arrayOfUsers[i].access << setw(2) << "|\n";
	}
	cout << "--------------------------------------------------------------------------------------------";
}

void adminOutput(ProductInfo* arrayOfProduct, Users* arrayOfUsers, int sizeArrayOfData, int sizeArrayOfUsers) {

}

void userOutput(ProductInfo* arrayOfProduct, int sizeArrayOfData) {
	productTableOutput(arrayOfProduct, sizeArrayOfData);
	cout << "\n 1) ���������� \n 2) ����� \n 3) �����";
	int choice, sortingChoice;
	cin >> choice;

	switch (choice) {
		case 1:
			/* 1 - sorting by date (int)
			   2 - sorting by workShopNumber (int)
			   3 - sorting by productName (string)
			   4 - sorting by numberOfProductsProduced (int)
			   5 - sorting by responsiblePerson (string)

			*/
			productTableOutput(arrayOfProduct, sizeArrayOfData);
			cout << " �� ������ ������ ����� �����������:\n 1) �� ��� ����� �� ��� ��������� \n"
				<< " ���������� �� ������ ���� \n 3) �� �������� �������� \n 4) �� ���������� ���������� ������"
				<< "\n 5) �� ����� �������������";
			sorting(arrayOfProduct, sizeArrayOfData, sortingChoice);

		case 2:
			
	}
}

void writeToConsole(ProductInfo* arrayOfProduct, Users* arrayOfUsers, int sizeArrayOfData, int sizeArrayOfUsers) {
	setlocale(LC_ALL, "Russian");
	cout << " 1) ����� \n2) ������� ����� ������� \n3) ����� �� ������� \n";

	string username;
	int choice;
	cout << " ������� ��� �����: ";
	cin >> choice;

	switch (choice) {
		case 1: 
			username = validation(arrayOfUsers, sizeArrayOfUsers);
			
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
