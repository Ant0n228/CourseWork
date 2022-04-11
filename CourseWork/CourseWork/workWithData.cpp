#include "workWithData.h"

ProductInfo* resizeArray(int& oldSize, int newSize, ProductInfo* array) {
	if (oldSize == newSize) {
		return array;
	}
	
	ProductInfo* newArray = new ProductInfo[newSize];
	oldSize = newSize < oldSize ? newSize : oldSize;
	for (int i = 0; i < oldSize; i++) {
		newArray[i] = array[i];
	}
	oldSize = newSize;
	delete[] array;
	return newArray;
}

ProductInfo* readFile(ProductInfo* array, int size) {
	ifstream file;
	file.open("productFile.txt");

	if (!file.is_open()) {
		cout << "We have a problem" << endl;
	}
	else {
		int numberOfLines = 0;
		while (!file.eof()) {
			if (numberOfLines >= size) {
				array = resizeArray(size, size + 1, array);
			}
			file >> array[numberOfLines].dayWhenProductCreate.day;
			file >> array[numberOfLines].dayWhenProductCreate.month;
			file >> array[numberOfLines].dayWhenProductCreate.year;
			file >> array[numberOfLines].workShopNumber;
			file >> array[numberOfLines].productName;
			file >> array[numberOfLines].numberOfProductsProduced;
			file >> array[numberOfLines].responsiblePerson;

			numberOfLines++;
		}
		array = resizeArray(size, size - 1, array);
	}
	file.close();
	return array;
}


void addInFile(ProductInfo temp, int size) {
	ofstream file;
	file.open("productFile.txt");
	
	file << endl << temp.dayWhenProductCreate.day << " ";
	file << temp.dayWhenProductCreate.month << " ";
	file << temp.dayWhenProductCreate.year << " ";
	file << temp.workShopNumber << " ";
	file << temp.productName << " ";
	file << temp.numberOfProductsProduced << " ";
	file << temp.responsiblePerson << endl;

	file.close();
	
}
bool compByDayWhenProductCreate(ProductInfo& begin, ProductInfo& end) {
	return begin.dayWhenProductCreate.year < begin.dayWhenProductCreate.year;
}

bool compByWorkShopNumber(ProductInfo& begin, ProductInfo& end) {
	return begin.workShopNumber < end.workShopNumber;
}

bool compByProductName(ProductInfo& begin, ProductInfo& end) {
	if(begin.productName != end.productName){
		return begin.productName < end.productName;
	}
}

bool compByNumberOfProductsProduced(ProductInfo& begin, ProductInfo& end) {
	return begin.numberOfProductsProduced < end.numberOfProductsProduced;
}

bool compByResponsiblePerson(ProductInfo& begin, ProductInfo& end) {
	if (begin.responsiblePerson != end.responsiblePerson) {
		return begin.responsiblePerson < end.responsiblePerson;
	}
}

void sorting(ProductInfo*& array, int size, int choice) {
	
	/* 1 - sorting by date (int)
	   2 - sorting by workShopNumber (int)
	   3 - sorting by productName (string)
	   4 - sorting by numberOfProductsProduced (int)
	   5 - sorting by responsiblePerson (string)
	
	*/
	
	switch (choice) {
		// TO DO ������� ����� ���������� ���������� � ������ ������ � ���
		case 1:
			sort(array, array + size, compByDayWhenProductCreate);
			break;
		
		case 2:
			sort(array, array + size, compByWorkShopNumber);
			break;
		
		case 3:
			sort(array, array + size, compByProductName);
			break;

		case 4: 
			sort(array, array + size, compByNumberOfProductsProduced);
			break;

		case 5: 
			sort(array, array + size, compByResponsiblePerson);
			break;

	}
}

// make better search
void search(ProductInfo*& array, int size) {
	
}



// ����� ���������� ������� ��������� � ���������� � ������������ ��������
// deletingElement ������� ����� �������

void deleteElement(ProductInfo*& array, int& size, int deletingElement) {
	//����� ��������� ��� ������� ������� � �����
	
	for (int i = deletingElement - 1; i < size - 1; i++) {
		array[i] = array[i + 1];
	}
	array = resizeArray(size, size - 1, array);
}

// TO DO better
Date getCurrentDate() {
	tm localTime;
	time_t now = time(NULL);
	localtime_s(&localTime, &now);
	Date currentDate;
	currentDate.day = localTime.tm_mday;
	currentDate.month = 1 + localTime.tm_mon;
	currentDate.year = 1900 + localTime.tm_year;
	return currentDate;
}

int day(ProductInfo* array) {
	
}


ProductInfo* IndividualTask(ProductInfo* array, Date beginning, Date end, int size) {
	sorting(array, size, 1);
	
	int numberOfLines = 1;
	// make better name!!
	ProductInfo* IndividualArray = new ProductInfo[numberOfLines];

	for (int i = 0; i < size; i++) {
		if (array[i].dayWhenProductCreate.month) {
			cout << "your an idiot";
		}
	}
}