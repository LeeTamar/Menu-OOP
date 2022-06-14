/* Assignment: 1
Author: Omer Ziat, ID: 313199408
Author: Lee Tamar Zano, ID: 313612608
*/
#pragma once
class TwoDigits {
	char uni, doz;
public:
	TwoDigits();
	TwoDigits(char i, char j);
	TwoDigits(int i);
	~TwoDigits();
	void printValue();
	int value();
	void update(int i);
};