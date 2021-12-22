#include <string>
#include "Node.h"

using namespace std;

// Default constructor
Node::Node(): data(TemperatureData()), next(nullptr) {} // remember to initialize next to nullptr

// Parameterized constructor
Node::Node(string id, int year, int month, double temperature): data(TemperatureData(id,year,month,temperature)), next(nullptr) {}
// remember to initialize next to nullptr

void Node::add(Node* other) {
	Node* t = next;
	next = other;
	other->next = t;
}

bool Node::operator<(const Node& b) {
	//cout<<"! '<' used"<<endl;
	return this->data<b.data;
}
