#pragma once
#include <iostream>
/**
 * @brief Represents the probability of independent events.
 */
class Probability {
	friend Probability& operator&=(Probability& lhs, const Probability& rhs);
	friend Probability& operator|=(Probability& lhs, const Probability& rhs);
	friend Probability& operator^=(Probability& lhs, const Probability& rhs);
	friend Probability& operator-=(Probability& lhs, const Probability& rhs);
	friend std::ostream& operator<<(std::ostream& os, const Probability& probability);

public:
	/**
	 * @brief Constructs a Probability object with a given probability value.
	 * @param probabilityValue The probability value (default is 0).
	 */
	Probability(double probabilityValue = 0);

	/**
	 * @brief Sets the probability value of the object.
	 * @param probabilityValue The new probability value.
	 */
	void setProbability(double probabilityValue);

	/**
	 * @brief Gets the probability value of the object.
	 * @return The probability value.
	 */
	double getProbability() const;

	/**
	 * @brief Performs a logical AND operation between two Probability objects.
	 * @param other The other Probability object.
	 * @return The result of the logical AND operation.
	 */
	const Probability operator&(const Probability& other);

	/**
	 * @brief Performs a logical OR operation between two Probability objects.
	 * @param other The other Probability object.
	 * @return The result of the logical OR operation.
	 */
	const Probability operator|(const Probability& other);

	/**
	 * @brief Performs a logical XOR operation between two Probability objects.
	 * @param other The other Probability object.
	 * @return The result of the logical XOR operation.
	 */
	const Probability operator^(const Probability& other);

	/**
	 * @brief Performs a logical subtraction operation between two Probability objects.
	 * @param other The other Probability object.
	 * @return The result of the logical subtraction operation.
	 */
	const Probability operator-(const Probability& other);

	/**
	 * @brief Performs a logical NOT operation on a Probability object.
	 * @return The result of the logical NOT operation.
	 */
	const Probability operator~() const;

private:
	double value; ///< The probability value.
};
