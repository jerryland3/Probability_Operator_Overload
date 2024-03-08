#include <iostream>
#include "Probability.h"

using namespace std;

int main() {
	// Test case 1: Create a Probability object with default probability
	Probability p1;
	cout << "Default probability value: " << p1 << endl;

	// Test case 2: Create a Probability object with a specific probability value
	Probability p2(0.4);
	cout << "Probability value for p2: " << p2 << endl;

	// Test case 3: Set a new probability value for p1 and verify it
	p1.setProbability(0.6);
	cout << "Updated probability value for p1: " << p1 << endl;

	// Test case 4: Perform logical AND operation between p1 and p2
	Probability p3 = p1 & p2;
	cout << "Probability value after logical AND operation: " << p3 << endl;

	// Test case 5: Perform logical AND operation between p2 and p1 (commutative test)
	Probability p4 = p2 & p1;
	cout << "Probability value after commutative logical AND operation: " << p4 << endl;

	// Test case 6: Perform logical OR operation between p1 and p2
	Probability p5 = p1 | p2;
	cout << "Probability value after logical OR operation: " << p5 << endl;

	// Test case 7: Perform logical OR operation between p2 and p1 (commutative test)
	Probability p6 = p2 | p1;
	cout << "Probability value after commutative logical OR operation: " << p6 << endl;

	// Test case 8: Perform logical XOR operation between p1 and p2
	Probability p7 = p1 ^ p2;
	cout << "Probability value after logical XOR operation: " << p7 << endl;

	// Test case 9: Perform logical XOR operation between p2 and p1 (commutative test)
	Probability p8 = p2 ^ p1;
	cout << "Probability value after commutative logical XOR operation: " << p8 << endl;

	// Test case 9: Perform logical subtraction operation between p1 and p2
	Probability p9 = p1 - p2;
	cout << "Probability value after logical subtraction operation: " << p9 << endl;

	// Test case 10: Perform logical NOT operation on p1
	Probability p10 = ~p1;
	cout << "Probability value after logical NOT operation on p1: " << p10 << endl;

	p2 - p1;

	return 0;
}