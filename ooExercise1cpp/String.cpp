/* Assignment: 1
Author: Omer Ziat, ID: 313199408
Author: Lee Tamar Zano, ID: 313612608
*/
#include <iostream>
#include "String.h"
using namespace std;

String::String() { null_idx = 0; }

String::String(char arr[]) {
	int i = 0;
	while (arr[i] > 0 && i < 9) {
		this->str[i] = arr[i];
		i++;
	}
	arr[i] = 0;
	this->null_idx = i;
}

String::~String() {}

void String::updateValue(char arr[]) {
	int i;
	for (i = 0; i < 9; i++) { this->str[i] = 0; }
	i = 0;
	while (arr[i] > 0 && i < 9) {
		this->str[i] = arr[i];
		i++;
	}
	if (i > 9) { this->str[9] = 0; this->null_idx = 9; }
	else { this->null_idx = i; for (i; i < 9; i++) { this->str[i] = 0; } }
}

bool String::setCharAt(char charecter, int idx) {
	if (idx >= 0 && idx < 9) {
		if (idx <= this->null_idx) {
			if (idx == this->null_idx) {
				str[this->null_idx] = charecter;
				str[this->null_idx + 1] = 0;
				return true;
			}
			else {
				str[idx] = charecter;
				return true;
			}
		}
		else { return false; }
	}
	else { return false; }
}

char String::getCharAt(int idx) {
	if (idx >= this->null_idx || idx < 0) {
		cout << "index out of range" << endl;
		return '-';
	}
	else { return this->str[idx]; }

}

void String::printValue() {
	int i = 0;
	while (this->str[i] > 0) {
		cout << this->str[i];
		i++;
	}
	cout << endl;
}

void String::printValue(bool b) {
	int i = 0;
	if (b == true) {
		while (this->str[i] > 0) {
			if ((int)this->str[i] < 97) { cout << this->str[i]; }
			else { cout << (char)(this->str[i] - 32); }
			i++;
		}
		cout << endl;
	}
	else {
		while (this->str[i] > 0) {
			if ((int)this->str[i] < 97) { cout << (char)(this->str[i] + 32); }
			else { cout << this->str[i]; }
			i++;
		}
		cout << endl;
	}
}

bool String::setCharsByUser() {
	int i = 0, j;
	char arr[9] = { 0 }, temp;
	cout << "Please enter the characters you want to update from the beginning of the string, and end with 0" << endl;
	while (true) {
		cin >> temp;
		if (temp == '0') { break; }
		if (i < null_idx) { arr[i] = temp; }
		i++;
	}
	if (i <= this->null_idx) {
		for (j = 0; j < i; j++) {
			this->str[j] = arr[j];
		}
		return true;
	}
	return false;
}
