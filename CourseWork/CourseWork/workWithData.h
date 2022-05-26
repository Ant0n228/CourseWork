#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

struct Date {
	int day;
	int month;
	int year;
};

struct ProductInfo {
	Date dayWhenProductCreate;
	int workShopNumber;
	string productName;
	int numberOfProductsProduced;
	string responsiblePerson;
};

// work with file
void readProductFile(ProductInfo*& arrayOfProduct, int& size);
ProductInfo* resizeArray(int& oldSize, int newSize, ProductInfo*& arrayOfProduct);
void addInArray(ProductInfo*& arrayOfProduct, int& size);
void deleteElement(ProductInfo*& arrayOfProduct, int& size, int deletingElement);
void writeInFile(ProductInfo* arrayOfProduct, int size);

// сортировка
bool compByDayWhenProductCreate(ProductInfo& begin, ProductInfo& end);
bool compByWorkShopNumber(ProductInfo& begin, ProductInfo& end);
bool compByNumberOfProductsProduced(ProductInfo& begin, ProductInfo& end);
void sorting(ProductInfo* arrayOfProduct, int size, int choice);

// searching
ProductInfo* searchByDayWhenProductCreate(ProductInfo* arrayOfProduct, int size, int& sizeOfTempArray, int date);
ProductInfo* searchByWorkShopNumber(ProductInfo* arrayOfProduct, int size, int& sizeOfTempArray, int element);
ProductInfo* searchByProductName(ProductInfo* arrayOfProduct, int size, int& sizeOfTempArray, string nameOfProduct);
ProductInfo* searchByNumberOfProductsProduced(ProductInfo* arrayOfProduct, int size, int& sizeOfTempArray, int count);
ProductInfo* searchByResponsiblePerson(ProductInfo* arrayOfProduct, int size, int& sizeOfTempArray, string person);


// make bettter name!!
ProductInfo* OutputOfNumberOfManufacturedProducts(ProductInfo* arrayOfProduct, Date beginning, Date end,int numberOfWorkshop, int size, int &sizeOfManufacturedProduct);
Date getCurrentDate();
int convertToDay(Date day);

// other func