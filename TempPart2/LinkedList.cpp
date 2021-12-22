#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList() {
	// Implement this function
}

LinkedList::~LinkedList() {
	// Implement this function
}

LinkedList::LinkedList(const LinkedList& source) {
	// Implement this function
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// Implement this function
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	// Implement this function
}

void LinkedList::clear() {
	// Implement this function
}

Node* LinkedList::getHead() const {
	// Implement this function it will be used to help grade other functions
}

string LinkedList::print() const {
	string outputString;
	// Implement this function
	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}
