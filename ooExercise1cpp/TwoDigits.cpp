/* Assignment: 1
Author: Omer Ziat, ID: 313199408
Author: Lee Tamar Zano, ID: 313612608
*/
#include <iostream>
#include "TwoDigits.h"
using namespace std;

TwoDigits::TwoDigits() { doz = 48; uni = 48; }

TwoDigits::TwoDigits(char i, char j) { this->doz = i; this->uni = j; }

TwoDigits::TwoDigits(int i) {
	this->doz = (i / 10) + 48;
	this->uni = (i % 10) + 48;
}

TwoDigits::~TwoDigits() {}

int TwoDigits::value() { return 10 * (this->doz - 48) + (this->uni - 48); }

void TwoDigits::update(int i) {
	this->doz = (i / 10) + 48;
	this->uni = (i % 10) + 48;
}

void TwoDigits::printValue() {
	if (this->doz == '0') { cout << this->uni << endl; }
	else { cout << this->doz << this->uni << endl; }
}
