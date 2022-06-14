/* Assignment: 1
Author: Omer Ziat, ID: 313199408
Author: Lee Tamar Zano, ID: 313612608
*/
#include <iostream>
#include "Fraction.h"
using namespace std;

Fraction::Fraction() { up = 0; down = 1; }

Fraction::Fraction(int i, int j) {
	if (!j) { up = 0; down = 1; }
	else { up = i; down = j; }
}

Fraction::~Fraction() {}

float Fraction::value() {
	return float(float(this->up) / float(this->down));
}

void Fraction::updateNumerator(int i) { this->up = i; }

void Fraction::updateDenominator(int j) {
	if (!j) { up = 0; down = 1; }
	else { this->down = j; }
	if ((this->down) < 0) {
		this->down = this->down * (-1);
		this->up = this->up * (-1);
	}
}

void Fraction::printValue() {
	if (this->down < 0) {
		cout << (-1) * this->up << "/" << (-1) * this->down << endl;
	}
	else {
		cout << this->up << "/" << this->down << endl;
	}
}