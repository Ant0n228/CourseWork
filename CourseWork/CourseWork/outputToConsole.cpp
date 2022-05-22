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
			break;
		}
	}

}

// ����� ������� ��������� ������
void productTableOutput(ProductInfo* arrayOfProduct, int sizeArrayOfData) {
	cout << "|" << setw(2) << "#" << setw(2) << "|" << setw(2) << "���� ����� ������ ���������" << setw(2) << "|"
		<< setw(2) << "����� ����" << setw(2) << "|" << setw(2) << "�������� ��������" << setw(2) << "|"
		<< setw(2) << "���������� ���������� ������" << setw(2) << "|" << "��� ������������� �� ���� � ������ ����" << setw(2) << "|\n";
	for (int i = 0; i < sizeArrayOfData; i++) {
		cout << "---------------------------------------------------------\n";
		cout << "|" << setw(2) << i << setw(2) << "|" << setw(2) << arrayOfProduct[i].dayWhenProductCreate.day << "." <<
			arrayOfProduct[i].dayWhenProductCreate.month << "." << arrayOfProduct[i].dayWhenProductCreate.year << setw(2) << "|"
			<< setw(2) << arrayOfProduct[i].workShopNumber << setw(2) << "|" << setw(2) << arrayOfProduct[i].productName << setw(2) << "|"
			<< setw(2) << arrayOfProduct[i].numberOfProductsProduced << setw(2) << "|" << arrayOfProduct[i].responsiblePerson << setw(2) << "|\n";
	}
	cout << "---------------------------------------------------------\n";
	
}

// ����� ������� �������������
void userTableOutput(Users* arrayOfUsers, int sizeArrayOfUsers) {
	cout << "|" << setw(2) << "#" << setw(2) << "|" << setw(17) << "��� ������������" << setw(2) << "|"
		<< setw(20) << "������������ ������" << setw(2) << "|"
		<< setw(5) << "����" << setw(2) << "|" << setw(7) << "������" << setw(3) << "|\n";
	for (int i = 0; i < sizeArrayOfUsers; i++) {
		cout << "--------------------------------------------------------------\n";
		cout << "|" << setw(2) << i << setw(2) << "|" << setw(10) << arrayOfUsers[i].nickname << setw(9) << "|"
			<< setw(20) << arrayOfUsers[i].saltedHashPassword << setw(2) << "|"
			<< setw(3) << arrayOfUsers[i].role << setw(4) << "|" << setw(5) << arrayOfUsers[i].access << setw(5) << "|\n";
	}
	cout << "--------------------------------------------------------------";
}

void outputSorting(ProductInfo* arrayOfProduct, int sizeArrayOfData) {
	
	system("cls");
	productTableOutput(arrayOfProduct, sizeArrayOfData);
	cout << " �� ������ ������ ����� �����������:\n 1) �� ���� ����� �� ��� ��������� \n"
		<< " 2) ���������� �� ������ ���� \n 3) �� ���������� ���������� ������ \n 4) �����\n ������� �����: ";
	int sortingChoice;
	cin >> sortingChoice;
	if (sortingChoice == 4) {
		return;
	}
	sorting(arrayOfProduct, sizeArrayOfData, sortingChoice);

	system("cls");
}

void outputSearch(ProductInfo* arrayOfProduct, int sizeArrayOfData) {
	system("cls");
	ProductInfo* searchingArray = new ProductInfo[1];
	string nameOfResponsible, nameOfProduct;
	int searchingChoice, date, element, count, numberOfWorkshop;
	productTableOutput(arrayOfProduct, sizeArrayOfData);
	cout << " �� ������ ������ ����� ������:\n 1) �� ��� ����� �� ��� ��������� \n"
		<< " ���������� �� ������ ���� \n 3) �� �������� �������� \n 4) �� ���������� ���������� ������"
		<< "\n 5) �� ����� ������������� \n 6) ����� \n ������� �����: ";
	cin >> searchingChoice;

	system("cls");
	productTableOutput(arrayOfProduct, sizeArrayOfData);

	switch (searchingChoice) {

	case 1:
		cout << " ������� ���: ";
		cin >> date;
		searchingArray = searchByDayWhenProductCreate(arrayOfProduct, sizeArrayOfData, date);
		break;

	case 2:
		cout << " ������� ����� ����: ";
		cin >> element;
		searchingArray = searchByWorkShopNumber(arrayOfProduct, sizeArrayOfData, element);
		break;

	case 3:
		cout << " ������� �������� ��������: ";
		cin >> nameOfProduct;
		searchingArray = searchByProductName(arrayOfProduct, sizeArrayOfData, nameOfProduct);
		break;

	case 4:
		cout << " ������� ���������� ���������� ���������: ";
		cin >> count;
		searchingArray = searchByNumberOfProductsProduced(arrayOfProduct, sizeArrayOfData, count);
		break;
	case 5:
		cout << " ������� ������������� � ���� ������� ���������: ";
		cin >> nameOfResponsible;
		searchingArray = searchByResponsiblePerson(arrayOfProduct, sizeArrayOfData, nameOfResponsible);
		break;
	case 6:
		return;
	default:
		cout << " ������ ����� ��� �������� �����";
	}
	productTableOutput(searchingArray, 1);
	system("pause");
	system("cls");

}

void outputIndividualTask(ProductInfo* arrayOfProduct, int sizeArrayOfData) {
	system("cls");
	Date beginning, end;
	int numberOfWorkshop;

	cout << " ������� ����� ����: ";
	cin >> numberOfWorkshop;

	cout << " ������� ������ ������� \n ������: \n	����: ";
	cin >> beginning.day;
	cout << "	�����: ";
	cin >> beginning.month;
	cout << "	���:";
	cin >> beginning.year;

	cout << " ������� ������ ������� \n �����: \n	����: ";
	cin >> end.day;
	cout << "	�����: ";
	cin >> end.month;
	cout << "	���:";
	cin >> end.year;
	system("cls");
	int buf_size;
	auto buf = OutputOfNumberOfManufacturedProducts(arrayOfProduct, beginning, end, numberOfWorkshop, sizeArrayOfData, buf_size);
	productTableOutput(buf, buf_size);
	system("pause");
	system("cls");
}

// ��� ������ �������� � �������� �������������
void userOutput(ProductInfo*& arrayOfProduct, int sizeArrayOfData, int choice) {
	// sortingChoice � searchingChoice ���������� ��� ������ ������ ���������� � ������ �������������
	
	int sizeArrayOfProduct;
	string nameOfProduct, nameOfResponsible;
	system("cls");
	switch (choice) {
		case 1:
			outputSorting(arrayOfProduct, sizeArrayOfData);
			break;

		case 2:
			outputSearch(arrayOfProduct, sizeArrayOfData);
			break;

		case 3:
			outputIndividualTask(arrayOfProduct, sizeArrayOfData);
			break;

		default:
			system("cls");
			cout << " ������� ��������� �����!";
	}
}

void outputWorkdWithUsers(Users*& arrayOfUsers, int& sizeArrayOfUsers) {
	system("cls");

	userTableOutput(arrayOfUsers, sizeArrayOfUsers);
	int choiceOfUserTable, numberOfUser;
	while (true) {
		cout << "\n 1) �������� ������������\n 2) �������� ����������� \n 3) ������� �������� ������� \n 4) ����� \n ������� �����: ";
		cin >> choiceOfUserTable;
		switch (choiceOfUserTable) {
			case 1:
				system("cls");

				userTableOutput(arrayOfUsers, sizeArrayOfUsers);
				cout << " ������� ����� ���������� ������������: ";
				cin >> numberOfUser;

				deleteUser(arrayOfUsers, sizeArrayOfUsers, numberOfUser);
				break;

			case 2:
				system("cls");

				userTableOutput(arrayOfUsers, sizeArrayOfUsers);
				cout << " ������� ����� ����������� ������������: ";
				cin >> numberOfUser;

				approveUser(arrayOfUsers, sizeArrayOfUsers, numberOfUser);
				break;

			case 3:
				system("cls");

				userTableOutput(arrayOfUsers, sizeArrayOfUsers);
				cout << " ������� ����� ��������, ������� ������ ���� �������: ";
				cin >> numberOfUser;

				makeUserAdmin(arrayOfUsers, sizeArrayOfUsers, numberOfUser);
				break;

			case 4:
				cout << " ��������! ";
				system("cls");
				return;

			default:
				system("cls");
				cout << " ������� ��������� �����!";
				break;
		}
	}
}
void displayAdditionalFeatures(ProductInfo*& arrayOfProduct, int& sizeArrayOfData, int choiceOfProduct) {
	int deletingElement;
	switch (choiceOfProduct) {
		case 5:
			system("cls");
			productTableOutput(arrayOfProduct, sizeArrayOfData);
			addInArray(arrayOfProduct, sizeArrayOfData);
			break;
		
		case 6:
			system("cls");
			productTableOutput(arrayOfProduct, sizeArrayOfData);
			cout << " ������� ����� ���������� ��������: ";
			cin >> deletingElement;
			deleteElement(arrayOfProduct, sizeArrayOfData, deletingElement);
			break;
	}
}

void adminOutput(ProductInfo*& arrayOfProduct, Users*& arrayOfUsers, int& sizeArrayOfData, int& sizeArrayOfUsers) {
	system("cls");

	int choice, choiceOfProduct;

	while (true) {
		cout << " 1) ������ � �������� ��������� \n 2) ������ � �������� ������������� \n 3) ����� �� ������� \n ������� �����: ";

		cin >> choice;
		switch (choice) {
			case 1:
				while (true) {
					productTableOutput(arrayOfProduct, sizeArrayOfData);
					cout << "\n 1) ���������� \n 2) ����� \n 3) ����� ���������� ���������� ������� �� ������� ������������ \n 4) �����";
					cout << "\n 5) ���������� ��������\n 6) �������� �������� \n ";
					cout << " ������� �����: ";
					cin >> choiceOfProduct;
					if (choiceOfProduct < 4) {
						userOutput(arrayOfProduct, sizeArrayOfData, choiceOfProduct);
					}
					else if(choiceOfProduct == 4) {
						cout << " ��������\n";
						break;
					}
					else {
						displayAdditionalFeatures(arrayOfProduct, sizeArrayOfData, choiceOfProduct);
					}
					
				}
				break;
			
			case 2:
				outputWorkdWithUsers(arrayOfUsers, sizeArrayOfUsers);
				break;

			case 3:
				
				cout << "��������";
				return;

			default:
				cout << "������� ��������� �����";
				break;

		}
	}

}

void createNewAccount(Users*& arrayOfUsers, int &sizeArrayOfUsers) {
	system("cls");
	string password, username;

	arrayOfUsers = resizeUserArray(arrayOfUsers, sizeArrayOfUsers + 1, sizeArrayOfUsers);
	while (true) {
		cout << " ������� �����: "; cin >> username;

		if (isUsernameCorrect(username, arrayOfUsers, sizeArrayOfUsers - 1)) {
			cout << " ���� ����� �����, ������� �����!!";
		}
		else {
			break;
		}
	}
	cout << " ������� ������: "; cin >> password;

	getSalt(arrayOfUsers, password, sizeArrayOfUsers - 1);
	password += arrayOfUsers[sizeArrayOfUsers - 1].salt;
	arrayOfUsers[sizeArrayOfUsers - 1].saltedHashPassword = hashing(password);
	arrayOfUsers[sizeArrayOfUsers - 1].role = 0;
	arrayOfUsers[sizeArrayOfUsers - 1].access = 0;
	arrayOfUsers[sizeArrayOfUsers - 1].nickname = username;

	cout << " ������� �������, �������� ��������� ������ ��������";
}

void writeToConsole(ProductInfo* arrayOfProduct, Users*& arrayOfUsers, int sizeArrayOfData, int sizeArrayOfUsers) {
	setlocale(LC_ALL, "Russian");
	
	string username;
	int choice, choiceOfUsers;
	while(true){
		system("cls");
		cout << " 1) ����� \n 2) ������� ����� ������� \n 3) ����� �� ������� \n";
		cout << " ������� ��� �����: ";
		cin >> choice;

		switch (choice) {
			case 1:
				system("cls");
				username = validation(arrayOfUsers, sizeArrayOfUsers);

				if (isItAdmin(username, arrayOfUsers, sizeArrayOfUsers)) {
					productTableOutput(arrayOfProduct, sizeArrayOfData);
					adminOutput(arrayOfProduct, arrayOfUsers, sizeArrayOfData, sizeArrayOfUsers);
				}
				else {
					if (isAccess(username, arrayOfUsers, sizeArrayOfUsers)) {
						productTableOutput(arrayOfProduct, sizeArrayOfData);
						cout << "\n 1) ���������� \n 2) ����� \n 3) ����� ���������� ���������� ������� �� ������� ������������ \n 4) �����\n";
						cin >> choiceOfUsers;
						if (choiceOfUsers == 4) {
							cout << " ��������!\n ";
							break;
						}
						userOutput(arrayOfProduct, sizeArrayOfData, choiceOfUsers);
					}
					else {
						cout << " � ��� ��� ��� �������";
						break;
					}
				}
				break;
			case 2:
				system("cls");
				createNewAccount(arrayOfUsers, sizeArrayOfUsers);
				system("pause");
				break;

			case 3:
				system("cls");
				cout << " ��������! ";
				writeInUsersFile(arrayOfUsers, sizeArrayOfUsers);
				writeInFile(arrayOfProduct, sizeArrayOfData);
				return;

			default:
				cout << " ������� ��������� �����!!";
				break;
		}
	}
}
