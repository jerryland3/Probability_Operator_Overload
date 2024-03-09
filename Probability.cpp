/**
 * @file Probability.h
 * @brief Definition of the Probability class and related non-member and member functions for overloading operators.
 *
 * This file contains the definition of the Probability class, which represents the probability of independent events,
 * along with the declaration of related non-member and member functions for overloading logical operations on Probability objects.
 * This class only works for independent events and non-mutually exclusive events.
 *
 * @date 3/8/2024
 * @version New
 * @author Jerry Wang
 */

#include <iostream>
#include "Probability.h"

using namespace std;

/**
 * @brief Constructor initializes the Probability object with a given probability value.
 * @param probabilityValue The probability value to initialize the object with.
 */
Probability::Probability(double probabilityValue)
{
	setProbability(probabilityValue);
}

/**
 * @brief Set the probability value of the object.
 * @param probabilityValue The new probability value.
 */
void Probability::setProbability(double probabilityValue)
{
	if (probabilityValue < 0 || probabilityValue > 1)
	{
		throw std::invalid_argument("Probability value must be between 0 and 1");
	}
	else {
		this->value = probabilityValue;
	}
}

/**
 * @brief Get the probability value of the object.
 * @return The probability value.
 */
double Probability::getProbability() const {
	return this->value;
}

/**
 * @brief Overloaded logical AND operator for two Probability objects.
 * @param other The other Probability object.
 * @return The result of the logical AND operation.
 */
const Probability Probability::operator&(const Probability& other)
{
	Probability temp(this->value);
	return temp &= other;
}

/**
 * @brief Overloaded logical OR operator for two Probability objects.
 * @param other The other Probability object.
 * @return The result of the logical OR operation.
 */
const Probability Probability::operator|(const Probability& other)
{
	Probability temp(this->value);
	return temp |= other;
}

/**
 * @brief Overloaded logical XOR operator for two Probability objects.
 * @param other The other Probability object.
 * @return The result of the logical XOR operation.
 */
const Probability Probability::operator^(const Probability& other)
{
	Probability temp(this->value);
	return temp ^= other;
}

/**
 * @brief Overloaded logical subtraction operator for two Probability objects.
 * @param other The other Probability object.
 * @return The result of the logical subtraction operation.
 */
const Probability Probability::operator-(const Probability& other)
{
	Probability temp(this->value);
	return temp -= other;
}

/**
 * @brief Overloaded unary logical NOT operator for a Probability object.
 * @return The result of the logical NOT operation.
 */
const Probability Probability::operator~() const
{
	return Probability(1 - this->value);
}

////////////////////////// non-member functions ////////////////////////////

/**
 * @brief Compound assignment operator for logical AND with another Probability object.
 * @param lhs The left-hand side Probability object.
 * @param rhs The right-hand side Probability object.
 * @return The result of the compound assignment.
 */
Probability& operator&=(Probability& lhs, const Probability& rhs)
{
	double value = lhs.getProbability() * rhs.getProbability();
	lhs.setProbability(value);
	return lhs;
}

/**
 * @brief Compound assignment operator for logical OR with another Probability object.
 * @param lhs The left-hand side Probability object.
 * @param rhs The right-hand side Probability object.
 * @return The result of the compound assignment.
 */
Probability& operator|=(Probability& lhs, const Probability& rhs)
{
	double value = lhs.getProbability() + rhs.getProbability() - (lhs & rhs).getProbability();
	lhs.setProbability(value);
	return lhs;
}

/**
 * @brief Compound assignment operator for logical XOR with another Probability object.
 * @param lhs The left-hand side Probability object.
 * @param rhs The right-hand side Probability object.
 * @return The result of the compound assignment.
 */
Probability& operator^=(Probability& lhs, const Probability& rhs)
{
	double value = lhs.getProbability() + rhs.getProbability() - 2 * (lhs & rhs).getProbability();
	lhs.setProbability(value);
	return lhs;
}

/**
 * @brief Compound assignment operator for logical subtraction with another Probability object.
 * @param lhs The left-hand side Probability object.
 * @param rhs The right-hand side Probability object.
 * @return The result of the compound assignment.
 */
Probability& operator-=(Probability& lhs, const Probability& rhs)
{
	lhs &= ~rhs;
	return lhs;
}

/**
 * @brief Overloaded stream insertion operator for Probability objects.
 * * @param output The output stream.
 * * @param probability The Probability object to insert into the stream.
 * * @return The output stream.
 * */
ostream& operator<<(ostream& output, const Probability& probability)
{
	output << probability.getProbability();
	return output;
}