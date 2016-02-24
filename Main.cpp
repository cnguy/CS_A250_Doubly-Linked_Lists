/***********************************************

	Class DoublyList

************************************************/

#include "DoublyList.h"

using namespace std;

int main()
{
	cout << "Creating list" << endl;
	DoublyList intList;
	cout << endl;

	cout << "Inserting 5 4 3 2 1 thru insertFront" << endl;
	intList.insertFront(5);
	intList.insertFront(4);
	intList.insertFront(3);
	intList.insertFront(2);
	intList.insertFront(1);
	cout << endl;

	cout << "Printing with a forward iterator." << endl;
	intList.printForward();
	cout << endl;

	cout << "Printing with a reverse iterator." << endl;
	intList.printBackwards();
	cout << endl << endl;

	cout << "Searching for a 1: " << boolalpha << intList.search(1) << endl;
	cout << "Searching for a 2: " << boolalpha << intList.search(2) << endl;
	cout << "Searching for a 5: " << boolalpha << intList.search(5) << endl;
	cout << "Searching for a 6: " << boolalpha << intList.search(6) << endl;
	cout << endl;



	cout << endl << endl;
	//system("Pause");
	return 0;
}
