/**
	  ---------------------------------------------------
	  |        Made by Skachko Anton (@Ant0n228)        |
	  |             2021 - BSUIR - FCP - PMS            |
	  |          *** All rights reserved ***	    |
	  |						    |
	  |	        \_____________________/		    |
	  |	         ___/__|_______|__\___		    |
	  |	         /+++  _________  +++\		    |
	  |	         \___ /_GTR R34_\ ___/		    |
	  |	         \_|_|_|       |_|_|_/		    |
	  ---------------------------------------------------
														   **/
// ïîäêëþ÷àåì çàãîëîâî÷íûå ôàéëû
#include "outputToConsole.h"
#include "workingWithUsers.h"
#include "workWithData.h"
#include <iostream>
using namespace std; 


int main() {

	// ïîäêëþ÷åíèå ðóññêîãî ÿçûêà 
	setlocale(LC_ALL, "Russian");


	int sizeArrayOfData = 1, sizeArrayOfUsers = 1;
	ProductInfo* arrayOfData = new ProductInfo[sizeArrayOfData];
	readProductFile(arrayOfData, sizeArrayOfData);
	
	Users* arrayOfUsers = new Users[sizeArrayOfUsers];
	readUserFile(arrayOfUsers, sizeArrayOfUsers);
	

	// âûâîä 
	writeToConsole(arrayOfData, arrayOfUsers, sizeArrayOfData, sizeArrayOfUsers);


	return 0;
}
