
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

// initialize a new head
// for the linked list
Node* head = NULL;
class Linkedlist {
public:
	// insert new value at the start
	void insert(int value)
	{
		Node* newNode = new Node(value);
		if (head == NULL)
			head = newNode;
		else {
			newNode->next = head;
			head = newNode;
		}
	}

	// detect if there is a loop
	// in the linked list
	Node* detectLoop()
	{
		Node *slowPointer = head, *fastPointer = head;

		while (slowPointer != NULL && fastPointer != NULL
			&& fastPointer->next != NULL) {
			slowPointer = slowPointer->next;
			fastPointer = fastPointer->next->next;
			if (slowPointer == fastPointer)
				break;
		}

		// if no loop exists
		if (slowPointer != fastPointer)
			return NULL;

		// reset slow pointer to head
		// and traverse again
		slowPointer = head;
		while (slowPointer != fastPointer) {
			slowPointer = slowPointer->next;
			fastPointer = fastPointer->next;
		}

		return slowPointer;
	}
};

int main()
{
	Linkedlist l1;
	// inserting new values
	l1.insert(10);
	l1.insert(20);
	l1.insert(30);
	l1.insert(40);
	l1.insert(50);

	// adding a loop for the sake
	// of this example
	Node* temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	// loop added;
	temp->next = head;

	Node* loopStart = l1.detectLoop();
	if (loopStart == NULL)
		cout << "Loop does not exists" << endl;
	else {
		cout << "Loop does exists and starts from "
			<< loopStart->data << endl;
	}

	return 0;
}
