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
	// Traverse to pos1
	int curr_pos1 = 0;
	Node* curr_node1 = head;
	Node* prev_node1 = head;

	while (curr_pos1 < pos1 && curr_node1 != nullptr) {
		curr_pos1++;
		prev_node1 = curr_node1;
		curr_node1 = curr_node1->link;
	}

	// Traverse to pos2
	int curr_pos2 = 0;
	Node* curr_node2 = head;
	Node* prev_node2 = head;

	while (curr_pos2 < pos2 && curr_node2 != nullptr) {
		curr_pos2++;
		prev_node2 = curr_node2;
		curr_node2 = curr_node2->link;
	}

	// Return false if pos1 or pos2 are out of bounds
	if (curr_node1 == nullptr || curr_node2 == nullptr) {
		return false;
	}

	// Set pos1 to point to pos2->link and vice versa
	Node* temp_node2_link = curr_node2->link;
	curr_node2->link = curr_node1->link;
	curr_node1->link = temp_node2_link;

	// Set pos1 prev to point to pos2 and vice versa
	prev_node2->link = curr_node1;
	prev_node1->link = curr_node2;

	return true;
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
			// Will throw error when deleting current_node if current_node = head
			if (current_node != head)
				prev_node->link = next_node;
			else
				head = next_node; // If deleting from head, set head (not prev_node->link) to next_node

			delete current_node;

			return true;
		}

		prev_node = current_node;
		current_node = current_node->link;
		next_node = current_node != nullptr ? current_node->link : nullptr;
	}

	return false;
}