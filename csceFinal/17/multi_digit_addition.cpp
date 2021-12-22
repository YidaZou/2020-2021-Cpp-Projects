/*
----- Linked List Addition Problem -----
Implement the add function.
*/

#include "multi_digit_addition.h"
using std::ostream, std::cout, std::endl;

// copy constructor
Number::Number(const Number& other) : head(nullptr), tail(nullptr) {
    Digit* marker = other.head;
    while (nullptr != marker) {
        insertFront(marker->value);
        marker = marker->next;
    }
}

// destructor
Number::~Number() {
    // initialize auxiliary pointer
    Digit* marker = nullptr;

    // iterate through list
    while (nullptr != head) {
        // set pointer to head node
        marker = head;

        // move head node to next node
        head = head->next;

        // disconect current node from rest of linked list
        marker->next = nullptr;
        if (nullptr != head) {
            head->prev   = nullptr;
        }

        // deallocate pointer
        delete marker;
        marker = nullptr;
    }
}

// copy assignment operator
Number& Number::operator=(const Number& other) {
    throw std::runtime_error("do not use operator= function");
    if (this == &other) { return *this; }
    return *this;
}

// insert front
void Number::insertFront(int value) {
    // create new node
    Digit* digit = new Digit(value);

    // case: list is empty => set tail node
    if (nullptr == tail) {
        tail = digit;
    }

    // case: list is non-empty => link head to new node
    else {
        head->prev = digit;
    }

    // link node to head and update head
    digit->next = head;
    head = digit;
}

// insert back
void Number::insertBack(int value) {
    // create new node
    Digit* digit = new Digit(value);

    // case: list is empty => set head node
    if (nullptr == head) {
        head = digit;
    }

    // case: list is non-empty => link tail to new node
    else {
        tail->next = digit;
    }

    // link node to tail and update tail
    digit->prev = tail;
    tail = digit;
}

// insertion operator
ostream& operator<<(ostream& out, const Number& number) {
    Digit* marker = number.getHead();
    while (nullptr != marker) {
        out << marker->value;
        marker = marker->next;
    }
    return out;
}

/*
TODO: Implement add function
*/

// add function
Number Number::add(const Number& rhs) {
  Digit* l = this->getTail();
  Digit* r = rhs.getTail();
  Number sum;
  int digitSum, lVal, rVal;
  bool ten = 0;
  while(l!=nullptr || r!=nullptr){
    if(l==nullptr){
      lVal = 0;
    }else{
      lVal = l->value;
    }
    if(r==nullptr){
      rVal = 0;
    }else{
      rVal = r->value;
    }
    digitSum = lVal + rVal;

    if(ten){
      digitSum+=ten;
      ten=0;
    }
    if(digitSum>9){
      digitSum-=10;
      ten = 1;
    }

    sum.insertFront(digitSum);

    if(l!=nullptr){
      l = l->prev;
    }
    if(r!=nullptr){
      r = r->prev;
    }
  }
  if(ten){
    sum.insertFront(1);
  }
  return sum;
}
