#pragma once
#include "Athlete.h"
#include <iostream>


template <class T>
struct Node {
	T data; // Data type that our linked list will hold
	Node<T>* next; // Pointer to node. This pointer can hold the address of any object in our Node structure.
};

template <typename T>
class LinkedList {
	// Here we are creating a pointer to the address of the first object(node) of our linked list.
	Node<T>* head; // Head should never move
public:
	LinkedList<T>();
	~LinkedList<T>();

	void insertNodeInFront(const T&); // Function to insert a node to the list;
	void appendNode(const T&); // Function to add node to the end of the list
	void insertInPosition(const T&, int); // Function to add a node in a certain position in the list 
	void deleteNodeByPos(int);
	void deleteNode(const T&);
	size_t getNumberOfNodes() const; // size_t is a macro coming from c
	void displayLinkedList() const;
	void sortList();
	int searchList(int);
	Node<T>* atPosition(unsigned int);
	LinkedList<T> mergeTwoLists(const LinkedList<T>&);
	void insertInSorted(const T&);
	//Node<T>* atPosition(int);
};

template<typename T>
inline LinkedList<T>::LinkedList()
{
	head = nullptr;
}

template<typename T>
inline LinkedList<T>::~LinkedList()
{
	Node<T>* currNode = head;



	while (currNode != nullptr) {
		Node<T>* nextNode = currNode->next;
		delete currNode;
		currNode = nextNode;
	}
}

template<typename T>
inline void LinkedList<T>::insertNodeInFront(const T& dat)
{
	Node<T>* nodeToBeInserted = new Node<T>; // We created a variable of type node. There is no data in the node yet.
	// We need to prepare the node i.e., put the data and next in the node
	nodeToBeInserted->data = dat;
	nodeToBeInserted->next = head;
	head = nodeToBeInserted;
	// We have the address of the next node
};

template<typename T>
inline void LinkedList<T>::appendNode(const T& dat)
{
	// The end of a linked list is denoted by letting the last node point to a null;
	Node <T>* newNode = new Node<T>; // Pointer to the new node
	Node <T>* currNode;

	// Prepare new node. The newNode we created above has two members, a data member and pointer to the next node
	newNode->data = dat; // This is the data that our node will hold
	newNode->next = nullptr; // We know that this new node will be at the end of the list so the next will always point to a null

	// Check if the list is empty and if it is, give the address of the newNode as the head.
	if (!head) { // If head is null.
		head = newNode;
	}

	else {// Otherwise insert newNode at the end
		// We want to keep updating currNode node until it points to nothing i.e., end of list
		currNode = head; // Pointer to traverse the list
		while (currNode->next) {
			currNode = currNode->next;
		}

		// Once we get to the end of the list, we let currNode.next point to the newNode
		currNode->next = newNode;
	}

}

template<typename T>
inline void LinkedList<T>::insertInPosition(const T& dat, int pos)
{
	Node<T>* previousNode = head;
	Node<T>* newNode = new Node<T>;
	Node<T>* nextNode = head;
	int count = 1;
	newNode->data = dat;
	newNode->next = nullptr;

	if (pos == 1 || !head) {
		insertNodeInFront(dat);
	}
	else if (pos == (getNumberOfNodes() + 1)) {
		appendNode(dat);
	}
	else if (pos > (getNumberOfNodes() + 1)) {
		cout << "Error, position too big for my list :(" << endl;
	}
	else {
		while (nextNode != 0 && count < pos) {
			count++;
			previousNode = nextNode;
			nextNode = nextNode->next;
		}
		newNode->next = nextNode;
		previousNode->next = newNode;

	}
}

//template<typename T>
//inline void LinkedList<T>::deleteNodeByPos(int)
//{
//}

template<typename T>
inline void LinkedList<T>::deleteNode(const T& dat)
{
	//Declare two pointers of type T, both starting at the head
	Node<T>* previousNode = new Node<T>;
	Node<T>* currNode = new Node<T>;
	previousNode = currNode = head;

	// If list is empty, do nothing
	if (!head)
		return;

	// Check if the first member of the list is the one we want to delete
	if (currNode->data == dat) {
		head = head->next;
		delete currNode;
	}
	else {
		currNode = currNode->next;
		while (currNode != nullptr && currNode->data != dat) {
			previousNode = currNode;
			currNode = currNode->next;
		}
		previousNode->next = currNode->next;
		delete currNode;
		cout << "CurrNode still has an address and it is: " << currNode << endl;
		currNode = nullptr;
		cout << "Now we've set currNode to nullptr and the new address is: " << currNode << endl;
	}
}

template<typename T>
inline void LinkedList<T>::displayLinkedList() const
{
	cout << "The list has " << getNumberOfNodes() << " members." << endl;
	Node <T>* currNode = head;
	if (!head) {
		cout << "The list is empty." << endl;
	}
	else {
		while (currNode) { //We cannot use currNode.next cause our last node has a null pointer and will not be printed
			cout << currNode->data << endl;
			currNode = currNode->next;
		}
	}
}

template<typename T>
inline size_t LinkedList<T>::getNumberOfNodes() const
{
	Node <T>* currNode = head; // Create a node to traverse through the linked list
	int count = 0; // Counter variable
	while (currNode) {
		count++;
		currNode = currNode->next;
	}
	return count;
}

//template<typename T>
//void swap(Node<T>* a, Node<T>* b) {
//	Node<T>* temp;
//	temp = a;
//	a = b;
//	b = temp;
//
//}
// It's more efficient to swap what pointers are pointing to than swapping nodes
template <typename T> 
inline void LinkedList<T>::sortList() {
		bool swap;

		do
		{
			swap = false;
			Node<T>* currNode = head;
			Node<T>* prevNode = nullptr;

			while (currNode->next != nullptr)
			{
				// Compare the nodes next to each other 
				// If condition is true rearrange the links
				if (currNode->data > currNode->next->data)
				{
					Node<T>* temp = currNode->next;

					currNode->next = temp->next;
					temp->next = currNode;

					if (prevNode == nullptr)
					{
						head = temp; 
					}
					else
					{
						prevNode->next = temp;
					}

					swap = true;
				}

				prevNode = currNode;
				currNode = currNode->next;
			}

		} while (swap);
}

template <typename T>
inline int LinkedList<T>::searchList(int dat) {
	// Create an int to keep track of the position we're at in the list
	int position = 1;
	// Create a pointer that starts at head
	Node<T>* currNode = head;

	// While the pointer has sth, check if the comparison number is equal to the number being searched for
	// In our case, I overloaded the == operator to compare ath.jerseyNumber to the int and return true if they're equal
	// Users will use the jerseyNumber to search for a player
	while (currNode)
	{
		if (currNode->data == dat)
		{
			return position;
		}

		currNode = currNode->next;
		position++;
	}

	return -1;
	//int first = 1, middle, last = getNumberOfNodes();
	//bool found = false;
	//int position = -1;
	//while (!found && first <= last) {
	//	middle = (first + last) / 2;
	//	if (atPosition(middle)->data == dat) {
	//		found = true;
	//		position = middle;
	//	}
	//	else if (atPosition(middle)->data < dat) {
	//		last = middle - 1;
	//	}
	//	else {
	//		first = middle + 1;
	//	}

	//}
	//return position;
}

// Function for returning an athlete in a certain position in the list
template<typename T>
inline Node<T>* LinkedList<T>::atPosition(unsigned int pos)
{	
	Node<T>* currNode = new Node<T>;
	// Assign head to currNode
	if (pos > getNumberOfNodes()) {
		cout << "That athlete does not exist in our list" << endl;
		currNode = 0;
		return currNode;
	}
	else {
		currNode = head;
		// Loop until position = count then return that currNode
		for (int count = 1; count != pos && count != 0 && currNode != nullptr; count++) {
			currNode = currNode->next;
		}
		return currNode;
	}

}

template <typename T>
inline LinkedList<T> LinkedList<T>::mergeTwoLists(const LinkedList<T>& other) {
	// Read access violation if we declare it non-dynamically.
	LinkedList<T> * merged = new LinkedList<T>();
	// Assign currNode to the head of the first list and add all the nodes to merged list
	Node<T>* currNode = this->head;

	while (currNode) {
		merged->appendNode(currNode->data);
		currNode = currNode->next;
	}

	// Assign currNode to the head of second list and add all the nodes to merged list
	currNode = other.head;
	while (currNode) {
		merged->appendNode(currNode->data);
		currNode = currNode->next;
	}

	return *merged;
}

// Function for inserting in sorted list
template<typename T>
inline void LinkedList<T>::insertInSorted(const T& dat)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = dat;
	Node<T>* prevNode = nullptr, * nextNode = head;

	// If the list is empty, make the newNode the first node
	if (!head) {
		head = newNode;
		newNode->next = nullptr;
	}
	// If the newNode is the smallest off the bat then assign it to the front of the list
	else if (newNode->data < head->data) {
		insertNodeInFront(dat);
	}
	// Else, traverse the list and insert the node before the first node that has a greater value than it
	else {
		while (newNode->data >= nextNode->data && nextNode != nullptr) {
			prevNode = nextNode;
			nextNode = nextNode->next;
		}
		newNode->next = nextNode;
		prevNode->next = newNode;
	}
}

