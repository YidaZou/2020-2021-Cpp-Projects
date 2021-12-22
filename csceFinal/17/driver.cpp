#include <iostream>
#include "multi_digit_addition.h"
using std::cout, std::endl;

int main() {
	// example testing code here
    Number left = Number();
    left.insertBack(1);
    left.insertBack(2);
    left.insertBack(3);    // left: 123

    Number right = Number();
    right.insertBack(4);
    right.insertBack(5);
    right.insertBack(6);   // right: 456

    cout << left.add(right) << endl; // output: 579

    Number l1 = Number();
    l1.insertBack(1);
    l1.insertBack(2);
    l1.insertBack(3);    // left: 123

    Number r1 = Number();
    r1.insertBack(4);
    r1.insertBack(5); // right: 45

    cout << l1.add(r1) << endl; // output: 168

    Number l2 = Number();
    l2.insertBack(3);    // left: 3

    Number r2 = Number();
    r2.insertBack(5);
    r2.insertBack(9);   // right: 59

    cout << l2.add(r2) << endl; // output: 62

    Number l3 = Number();
    l3.insertBack(9);    // left: 99
    l3.insertBack(9);
    Number r3 = Number();
    r3.insertBack(9);
    r3.insertBack(9);   // right: 99

    cout << l3.add(r3) << endl; // output: 198

    Number l4 = Number();
    l4.insertBack(9);    // left: 9999
    l4.insertBack(9);
    l4.insertBack(9);
    l4.insertBack(9);
    Number r4 = Number();
    r4.insertBack(9);
    r4.insertBack(9);   // right: 99

    cout << l4.add(r4) << endl; // output: 10098

    Number l5 = Number();
    l5.insertBack(9);    // left: 9

    Number r5 = Number();
    r5.insertBack(9);
    r5.insertBack(9);
    r5.insertBack(9);
    r5.insertBack(1);   // right: 9991

    cout << l5.add(r5) << endl; // output: 10000
    return 0;
}
