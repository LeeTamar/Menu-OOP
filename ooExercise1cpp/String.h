/* Assignment: 1
Author: Omer Ziat, ID: 313199408
Author: Lee Tamar Zano, ID: 313612608
*/
#pragma once
class String {
	int null_idx;
	char str[10] = { 0 };
public:
	String();
	String(char arr[]);
	~String();
	void updateValue(char arr[]);
	bool setCharAt(char charecter, int idx);
	char getCharAt(int idx);
	void printValue();
	void printValue(bool b);
	bool setCharsByUser();
};