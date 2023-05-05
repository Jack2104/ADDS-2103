#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
	head = nullptr;
}

LinkedList::~LinkedList() {
	while (head != nullptr) {
		deleteFront();
	}
}

void LinkedList::insertFront(int item) {
	Node* newNode = new Node(item, head);
	head = newNode;
}

void LinkedList::deleteFront() {
	if(head != nullptr) {
		Node* oldHead = head;
		head = head->link;
		delete oldHead;
	}
}

void LinkedList::printList() {
	Node* currNode = head;
	while(currNode != nullptr) {
		std::cout << currNode->data << " ";
		currNode = currNode->link;
	}
}

/////////// your code goes here... DO NOT change the function signatures ///////////

bool LinkedList::swap(int pos1, int pos2) {
	
}

bool LinkedList::find_and_delete(int target) {
	// Instantly return false if the list is empty. Prevents error from occuring if head = nullptr (when creating next_node).
	if (head == nullptr) {
		return false;
	}

	Node* current_node = head;
	Node* prev_node = head;
	Node* next_node = head->link;

	while (current_node != nullptr) {
		if (current_node->data == target) {
			prev_node->link = next_node;
			delete current_node;

			return false;
		}

		prev_node = current_node;
		current_node = current_node->link;
		next_node = current_node->link;
	}

	return false;
}