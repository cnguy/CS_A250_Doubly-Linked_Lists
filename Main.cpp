/***********************************************

	Class DoublyList

************************************************/

#include "DoublyList.h"

using namespace std;

int main() {
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

    cout << "Calculating the sum." << endl;
    cout << "Sum: " << intList.sum() << endl << endl;

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
    //cout << "Front: " << intList.front() << endl;
    cout << "insertFront 3 2 1 0" << endl;
    intList.insertFront(3);
    intList.insertFront(2);
    intList.insertFront(1);
    intList.insertFront(0);
    intList.printForward();
    cout << endl;
    cout << "Front: " << intList.front() << endl;
    cout << "Back: " << intList.back() << endl;
    cout << endl << endl;

    DoublyList testList;
    testList.insertFront(404);
    cout << "intList: ";
    intList.printForward();
    cout << endl;
    cout << "testList: ";
    testList.printForward();
    cout << endl;
    cout << "intList.copyToList(testList);" << endl;
    intList.copyToList(testList);
    cout << "testList: ";
    testList.printForward();
    cout << endl;

    cout << "insertBack 1 2 3" << endl;
    testList.insertBack(1);
    testList.insertBack(2);
    testList.insertBack(3);
    cout << "testList: ";
    testList.printForward();
    cout << endl << endl;

    cout << "Creating basicList and inserting 1 2 3 4 5 in order" << endl;
    DoublyList basicList;
    basicList.insertBack(1);
    basicList.insertBack(2);
    basicList.insertBack(3);
    basicList.insertBack(4);
    basicList.insertBack(5);
    basicList.printForward();
    cout << endl;
    basicList.printBackwards();
    cout << endl;

    cout << "---moveKeyNodeToFirst(5)---" << endl;
    basicList.moveKeyNodeToFirst(5);
    basicList.printForward();
    cout << endl;
    basicList.printBackwards();
    cout << endl;

    cout << "---moveKeyNodeToFirst(3)---" << endl;
    basicList.moveKeyNodeToFirst(3);
    basicList.printForward();
    cout << endl;
    basicList.printBackwards();
    cout << endl;

    cout << "---moveKeyNodeToFirst(4)---" << endl;
    basicList.moveKeyNodeToFirst(4);
    basicList.printForward();
    cout << endl;
    basicList.printBackwards();
    cout << endl;

    cout << "---moveKeyNodeToFirst(3)---" << endl;
    basicList.moveKeyNodeToFirst(3);
    basicList.printForward();
    cout << endl;
    basicList.printBackwards();
    cout << endl;

    cout << "---moveKeyNodeToFirst(1)---" << endl;
    basicList.moveKeyNodeToFirst(1);
    basicList.printForward();
    cout << endl;
    basicList.printBackwards();
    cout << endl;

    cout << "---moveKeyNodeToFirst(3)---" << endl;
    basicList.moveKeyNodeToFirst(3);
    basicList.printForward();
    cout << endl;
    basicList.printBackwards();
    cout << endl;

    cout << "---moveKeyNodeToFirst(2)---" << endl;
    basicList.moveKeyNodeToFirst(2);
    basicList.printForward();
    cout << endl;
    basicList.printBackwards();
    cout << endl;

    cout << endl;
    cout << "emptyList for moving" << endl;
    DoublyList emptyList;
    emptyList.moveKeyNodeToFirst(3);
    cout << endl;

    cout << "twoItemList for moving" << endl;
    DoublyList twoItemList;
    twoItemList.insertBack(1);
    twoItemList.insertBack(2);
    twoItemList.printForward();
    cout << endl;
    twoItemList.printBackwards();
    cout << endl;

    cout << "moveKeyNodeToFirst 2" << endl;
    twoItemList.moveKeyNodeToFirst(2);
    twoItemList.printForward();
    cout << endl;
    twoItemList.printBackwards();
    cout << endl;
    cout << "moveKeyNodeToFirst 2" << endl;
    twoItemList.moveKeyNodeToFirst(2);
    twoItemList.printForward();
    cout << endl;
    twoItemList.printBackwards();
    cout << endl << endl;

    cout << "Creating a new list" << endl;
    DoublyList stack;
    stack.pushTop(2);
    stack.pushTop(3);
    stack.pushTop(5);
    stack.printForward();
    cout << endl;

    stack.popTop();
    stack.printForward();
    cout << endl;

    stack.popTop();
    stack.printForward();
    cout << endl;

    cout << "CREATING A ONE ELEMENT LIST." << endl;
    DoublyList oneElemList;
    oneElemList.insertBack(3);
    oneElemList.moveKeyNodeToFirst(3);
    oneElemList.printForward();
    cout << endl;
    oneElemList.printBackwards();
    cout << endl;
    cout << endl;


    cout << endl << endl;
    //system("Pause");
    return 0;
}
