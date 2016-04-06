#include "DoublyList.h"

//constructor
DoublyList::DoublyList()
{
	count = 0;
	first = last = NULL;
}

//destructor
DoublyList::~DoublyList()
{
	destroyList();
}

//printForward
void DoublyList::printForward() const
{
	if (first == NULL)
		cerr << "Cannot print from an empty list." << endl;
	else
	{
		Node *current = first;
        cout << "FORWARDS: ";
		while (current != NULL)
		{
			cout << current->getData() << " ";
			current = current->getNext();
		}
	}
}

//printBackwards
void DoublyList::printBackwards() const
{
	if (first == NULL)
		cerr << "Cannot print frmo an empty list." << endl;
	else
	{
		Node *rCurrent = last; // r stands for reverse
        cout << "REVERSE: ";
		while (rCurrent != NULL)
		{
			cout << rCurrent->getData() << " ";
			rCurrent = rCurrent->getPrev();
		}
	}
}

//insertFront
void DoublyList::insertFront(int newData)
{
	Node *newNode = new Node(newData, NULL, first); // points to first, prev link to null

	if (first == NULL)
		first = last = newNode;
	else
	{
        first->setPrev(newNode); // sets the prevLink of the ORIGINAL node that was first TO the new node
		first = newNode; // newNode is now the first node
	}
	++count;
}

// insertBack
void DoublyList::insertBack(int newData)
{
	Node *newNode = new Node(newData, NULL, NULL);

	if (first == NULL)
		first = last = newNode;
	else
	{
        last->setNext(newNode);
        last->getNext()->setPrev(last);
		last = newNode;
	}
}

//search
bool DoublyList::search(int key) const
{
	if (first == NULL)
		cerr << "Cannot search from an empty list." << endl;
	else
	{
		Node *current = first;

		while (current != NULL)
		{
			if (current->getData() == key)
				return true;
			else
				current = current->getNext();
		}
	}
	return false;
}

//sum
int DoublyList::sum() const
{
	if (first == NULL)
		cerr << "Cannot delete from an empty list." << endl;
	else
	{
		Node *current = first;
		int total = 0;
		while (current != NULL)
		{
			total += current->getData();
			current = current->getNext();
		}
		return total;
	}
	return 0;
}

//front
int DoublyList::front() const
{
	if (first == NULL)
	{
		cerr << "The list is empty." << endl;
		exit(1);
	}
	else
		return first->getData();
}

//back
int DoublyList::back() const
{
	if (last == NULL)
	{
		cerr << "The list is empty." << endl;
		exit(1);
	}
	else
		return last->getData();
}

//deleteNode
void DoublyList::deleteNode(int deleteData)
{
	// Case 1: The list is empty.
	if (first == NULL)
		cerr << "Cannot delete from an empty list." << endl;
	else
	{
		Node *current = first;

		// Case 2: The node to be deleted is the first node
		if (first->getData() == deleteData)
		{
			first = first->getNext();

			// Case 2a: The list has only one node.
			if (first == NULL)
				last = NULL;
			else
                first->setPrev(NULL);

			--count;
			delete current;
			current = NULL;
		}
		else // start searching the list abcdefghijklmnopqrstuvwxyz
		{
			bool found = false;
			
			while (current != NULL && !found)
			{
				if (current->getData() == deleteData)
					found = true;
				else
					current = current->getNext();
			}

			if (current == NULL) // if (!found)
				cerr << "The item to be deleted is not in the list." << endl;
			else
			{
				// Case 3: The item to be deleted is in the middle of the list.
				if (current != last)
				{
                    current->getPrev()->setNext(current->getNext());
                    current->getNext()->setPrev(current->getPrev());
				}
				// Case 4: The item to be deleted is the last node.
				else
				{
					last = current->getPrev();
                    last->setNext(NULL);
				}
				--count;
				delete current;
				current = NULL;
			}
		}
	}
}

//copyTolist
void DoublyList::copyToList(DoublyList& otherList) const
{
	// calling object is empty
	if (first == NULL)
		otherList.destroyList();
	else if (count == otherList.count)
	{
		// the calling object and the parameter object have the same number of nodes
		Node *current = first; // calling object
		Node *otherCurrent = otherList.first;

		while (current != NULL)
		{
			// copy from calling object to current object
			otherCurrent->setData(current->getData());

			// iterate to next node
			current = current->getNext();
			otherCurrent = otherCurrent->getNext();
		}
	}
	else if (otherList.count < count)
	{
		Node *current = first;
		Node *otherCurrent = otherList.first;

		while (current != NULL)
		{
			if (otherCurrent == NULL)
			{
				// otherCurrent is null, so create a new node to match the node we're trying to copy from
				Node *newNode = new Node(0, otherList.last, NULL);

				if (otherList.first == NULL)
				{
					otherList.first = newNode;
					otherList.last = newNode;
					otherCurrent = otherList.last;
				}
				else
				{
                    otherList.last->setNext(newNode);
                    otherList.last->getNext()->setPrev(otherList.last);
					otherList.last = newNode;
					otherCurrent = otherList.last;
				}
				otherList.count++;
			}

			otherCurrent->setData(current->getData());

			current = current->getNext();
			otherCurrent = otherCurrent->getNext();
		}
	}
	else // the parameter object has more nodes than the calling object
	{
		Node *current = first;
		Node *otherCurrent = otherList.first;

		while (current != NULL)
		{
			otherCurrent->setData(current->getData());

			current = current->getNext();
			otherCurrent = otherCurrent->getNext();
		}

		otherList.last = otherCurrent->getPrev();
        otherList.last->setNext(NULL);
		delete otherCurrent;
		otherCurrent = NULL;
		otherList.count -= otherList.count - count;
	}
}

void DoublyList::moveKeyNodeToFirst(int key)
{
	if (first == NULL)
    {
        cerr << "List is empty. No items to move." << endl;
        cout << "error, no items to move." << endl;
    }
	else if (last->getData() == key)
	{
        last->setNext(first);
        first->setPrev(last);
        first = last;
        last = last->getPrev();
        last->setNext(NULL);
        first->setPrev(NULL);
//        last->setNext(first);
//        first->setPrev(last);
//
//        Node *temp = last;
//        last = last->getPrev();
//        temp->setPrev(NULL);
//        last->setNext(NULL);
//        first = temp;
//
//        temp = last->getNext();
//        delete temp;
	}
	else
	{
		// Node with key is anywhere but the first and the last.
        if (first->getData() != key)
        {
            Node *current = first->getNext();
            bool found = false;

            while (current != last->getPrev() && !found)
            {
                if (current->getData() == key)
                    found = true;
                else
                    current = current->getNext();
            }

            first->setPrev(current);
            current->getPrev()->setNext(current->getNext());
            current->getNext()->setPrev(current->getPrev());
            current->setNext(first);
            current->setPrev(NULL);
            first = current;

            current = last->getNext();
            delete current;
        }
	}
}

void DoublyList::destroyList()
{
	Node *temp;

	while (first != NULL)
	{
		temp = first;
		first = first->getNext();
		delete temp;
		temp = NULL; // not necessary
	}
	last = NULL;
	count = 0; // efficient compared 
			   // to decrementing it in the while loop
}
