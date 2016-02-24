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

	cout << "Deleting one bye one." << endl << endl;
	cout << "Deleting 1." << endl;
	intList.deleteNode(1);
	intList.printForward();
	cout << endl;
	cout << "Deleting 2." << endl;
	intList.deleteNode(2);
	intList.printForward();
	cout << endl;
	cout << "Deleting 3." << endl;
	intList.deleteNode(3);
	intList.printForward();
	cout << endl;
	cout << "Deleting 4." << endl;
	intList.deleteNode(4);
	intList.printForward();
	cout << endl;
	cout << "Deleting 5." << endl;
	intList.deleteNode(5);
	//intList.printForward();
	cout << "Deleting 6." << endl;
	intList.deleteNode(6);
	//intList.printForward();

	cout << endl << endl;

	cout << endl << endl;
	//system("Pause");
	return 0;
}
