/* Assignment: 1
Author: Omer Ziat, ID: 313199408
Author: Lee Tamar Zano, ID: 313612608
*/
#pragma once
class Fraction {
	int up, down;
public:
	Fraction();
	Fraction(int i, int j);
	~Fraction();
	float value();
	void updateNumerator(int i);
	void updateDenominator(int j);
	void printValue();
};