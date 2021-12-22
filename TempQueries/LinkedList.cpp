#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList(): head(nullptr), tail(nullptr) {
	// Implement this function
}

LinkedList::~LinkedList() {
	// Implement this function
	clear();
}

LinkedList::LinkedList(const LinkedList& source): head(nullptr), tail(nullptr) {
	// Implement this function
	Node* m = source.head;

	while(m != nullptr){
		addNode(m->data);
		m = m->next;
	}

}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// Implement this function
	if(this!=&source){
		clear();
		Node* m = source.head;
		while(m != nullptr){
			addNode(m->data);
			m = m->next;
		}
	}

	return *this;
}

void LinkedList::addNode(TemperatureData n) {
	Node* node = new Node(n.id,n.year,n.month,n.temperature);

	if (tail == nullptr) head = node;
	else tail->add(node);

	tail = node;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	// Implement this function
	Node* node = new Node(location,year,month,temperature);	//new node

	if (tail == nullptr){// If list is empty
		//cout<<"!empty"<<endl;
		head = node;
		tail = node;
	}else if(node->data<head->data){
		//cout<<"!head"<<endl;
		node->next = head;
		head = node;
	}else{
		//cout<<"!else"<<endl;
		Node* m = head;			//marker
		//cout<<"	?1"<<endl;
		Node* p = nullptr;	//previous node
		//cout<<"	?2"<<endl;
		while(m->data<node->data){
			p = m;
			if(m->next==nullptr){
				//m->node(tail)
				m->next = node;
				tail = node;
				node->next = nullptr;
				return;
			}
			m = m->next;
		}
			//p->node->m
		p->next = node;
		node->next = m;
	}
	//cout<<head->data.month<<endl;
	return;
}
void LinkedList::clear() {
	// Implement this function
	Node* m = nullptr;

	while(head != nullptr){
		m = head;
		head = head->next;
		delete m;
	}

	head = nullptr;
	tail = nullptr;

	return;
}

Node* LinkedList::getHead() const {
	// Implement this function it will be used to help grade other functions
	return head;
}

string LinkedList::print() const {
	string outputString = "";
	// Implement this function
	//cout<<"!?!?printing"<<endl;
	Node* m = head;
	ostringstream temp;
	string tOut;
	while(m!=nullptr){
		temp.str("");
		temp<<noshowpoint<<(m->data.temperature);
		tOut = temp.str();
		outputString+= m->data.id +" "+ to_string(m->data.year) +" "+ to_string(m->data.month) +" "+ tOut + "\n";
		m = m->next;
	}
	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}
