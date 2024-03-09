/*
 * File: TestProbability.cpp
 * @brief Contain main() function for testing Probability class.
 *
 * @date: 3/8/2024
 * @version: New
 * @author: Jerry Wang
 */
#include <iostream>
#include "Probability.h"

using namespace std;

/**
 * @brief Test the probability value against an expected value and print the result.
 *
 * @param actualValue The actual probability value to test.
 * @param expectedValue The expected probability value.
 * @param testNumber The number identifying the test case.
 */
void testProbability(double actualValue, double expectedValue, char testNumber) {
	actualValue = std::round(actualValue * 1000) / 1000; // round to 3 decimal places to avoid floating point errors
	if (actualValue == expectedValue) {
		cout << "Test " << testNumber << " passed" << endl;
	}
	else {
		cout << "Test " << testNumber << " failed" << endl;
	}
}

int main() {
	Probability pA(0.6);
	cout << "Probability value for p1: " << pA << endl;
	Probability pB(0.4);
	cout << "Probability value for p2: " << pB << endl;

	/////////// Test set 1: Testing valid probability values //////////

	// Test case 1: Perform logical AND operation between pA and pB
	Probability p1 = pA & pB;
	testProbability(p1.getProbability(), 0.24, '1');

	// test case 2: Test commutative property of logical AND operation
	Probability p2 = pB & pA;
	testProbability(p2.getProbability(), 0.24, '2');

	// Test case 3: Perform logical OR operation between pA and pB
	Probability p3 = pA | pB;
	testProbability(p3.getProbability(), 0.76, '3');

	// test case 4: Test commutative property of logical OR operation
	Probability p4 = pB | pA;
	testProbability(p4.getProbability(), 0.76, '4');

	// Test case 5: Perform logical XOR operation between pA and pB
	Probability p5 = pA ^ pB;
	testProbability(p5.getProbability(), 0.52, '5');

	// Test case 6: test commutative property of logical XOR operation
	Probability p6 = pB ^ pA;
	testProbability(p6.getProbability(), 0.52, '6');

	// Test case 7: Perform subtraction operation between pA and pB
	Probability p7 = pA - pB;
	testProbability(p7.getProbability(), 0.36, '7');

	// Test case 8: Perform subtraction operation between pA and pB
	Probability p8 = pB - pA;
	testProbability(p8.getProbability(), 0.16, '8');

	// Test case 9: Perform negation operation on pA
	Probability p9 = ~pA;
	testProbability(p9.getProbability(), 0.4, '9');

	// test case 10-13: Test compound assignment operators
	Probability p10 = pA;
	p10 &= pB;
	testProbability(p10.getProbability(), 0.24, '10');

	Probability p11 = pA;
	p11 |= pB;
	testProbability(p11.getProbability(), 0.76, '11');

	Probability p12 = pA;
	p12 ^= pB;
	testProbability(p12.getProbability(), 0.52, '12');

	Probability p13 = pA;
	p13 -= pB;
	testProbability(p13.getProbability(), 0.36, '13');

	/////////// Test set 2: Testing invalid probability values //////////
	try {
		Probability p10(1.1);
	}
	catch (const std::invalid_argument& e) {
		cout << "Test 10 passed" << endl;
	}

	try {
		Probability p11(-0.1);
	}
	catch (const std::invalid_argument& e) {
		cout << "Test 11 passed" << endl;
	}

	try {
		Probability p12(10000000000000000000);
	}
	catch (const std::invalid_argument& e) {
		cout << "Test 12 passed" << endl;
	}

	return 0;
}