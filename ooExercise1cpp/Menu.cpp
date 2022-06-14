/* Assignment: 1
Author: Omer Ziat, ID: 313199408
Author: Lee Tamar Zano, ID: 313612608
*/
#include <iostream>
#include "Menu.h"
#include "TwoDigits.h"
#include "Fraction.h"
#include "String.h"
using namespace std;

Menu::Menu() {};

Menu::~Menu() {}

void Menu::mainMenu() {
	int serial;
	while (true) {
        cout << "----------------------------------------" << endl
		cout << "Please enter a serial number between 1-4" << endl;
		cout << "(1)TowDigit Menu" << endl << "(2)Fraction Menu" << endl;
		cout << "(3)String Menu" << endl << "(4)Exit the program" << endl;
		cin >> serial;
		// if the user enter a number out of range
		while (serial < 1 || serial > 4) {
			cout << "Note, the serial number must be between 1-4, please enter again" << endl;
			cin >> serial;
			continue;
		}
        // according to the user's choice, move to the appropriate menu
		if (serial == 1) { this->twoDigitsMenu(); }
		if (serial == 2) { this->fractionMenu(); }
		if (serial == 3) { this->stringMenu(); }
		if (serial == 4) { cout << "Goodbye" << endl; exit(0); }
	}
}

void Menu::twoDigitsMenu() {
	char doz, uni;
	int twodigint;
	//create Towdigit object from two characters: twodig1
	cout << "Please enter two numbers, the first for the tens digit and the second for the unity digit" << endl;
	cin >> doz;
	cin >> uni;
	//check if the user enter a number in the correct range
	while ((doz < 48 || doz > 57) || (uni < 48 || uni > 57)) {  //out of range
		cout << "Note, the numbers must be between 0-9, please enter again" << endl;
		cin >> doz;
		cin >> uni;
	}
	TwoDigits twodig1(doz, uni);
	//create Towdigit object from integer: twodig2
	cout << "Please enter a number, between 0-99" << endl;
	cin >> twodigint;
	//check if the user enter a number in the correct range
	while (twodigint < 0 || twodigint > 99) {  //out of range
		cout << "Note, two number must be between 0-99, please enter again" << endl;
		cin >> twodigint;
	}
	TwoDigits twodig2(twodigint);
	//two digits menu
	int serial, numtoupdate;
	while (true) {
		cout << "Please enter a serial number between 1-4" << endl;
		cout << "(1)Update the first object" << endl << "(2)Sum of the objects" << endl;
		cout << "(3)Print the objects" << endl << "(4)Exit the program" << endl;
		cin >> serial;
		// if the user enter a number out of range
		while (serial < 1 || serial > 4) {
			cout << "Note, the serial number must be between 1-4, please enter again" << endl;
			cin >> serial;
			continue;
		}
		if (serial == 1) {
			cout << "Please enter the new number you want, note, the number must be between 0-99" << endl;
			cin >> numtoupdate;
			//check if the user enter a number in the correct range
			while (numtoupdate < 0 || numtoupdate > 99) {	//out of range
				cout << "Note, two digit number must be between 0-99, please enter again" << endl;
				cin >> numtoupdate;
			}
			twodig1.update(numtoupdate);
		}
		if (serial == 2) {
			int a, b;
			// Displays a fraction as a float
			a = twodig1.value();
			b = twodig2.value();
			// Add zero befor a number with 0 in the tens digit
			if (a < 10) { cout << "The sum of 0" << a; }
			else { cout << "The sum of " << a; }
			// Add zero befor a number with 0 in the tens digit
			if (b < 10) { cout << "+0" << b; }
			else { cout << "+" << b; }
			// sum the objects
			cout << " is: " << (a + b) << endl;
		}
		if (serial == 3) {
			int a, b;
			// Displays a fraction as a float
			a = twodig1.value();
			b = twodig2.value();
			// print the objects
			if (a < 10) { cout << "First two digit number: 0"; twodig1.printValue(); }
			else { cout << "First two digit number:	"; twodig1.printValue(); }
			if (b < 10) { cout << "Second two digit number: 0"; twodig2.printValue(); }
			else { cout << "Second two digit number: "; twodig2.printValue(); }
		}
		if (serial == 4) { return; } //return to the main menu
	}
}

void Menu::fractionMenu() {
	int up, down, serial, newup, newdown;
	float anothernum, flofrac1, sum;
	cout << "Please enter two numbers, the first for the numerator and the second for the denominator" << endl;
	cin >> up;
	cin >> down;
	Fraction frac1(up, down);
	while (true) {
		cout << "Please enter a serial number between 1-5" << endl;
		cout << "(1)Update the numerator" << endl << "(2)Update the denominator" << endl;
		cout << "(3)Print the object" << endl << "(4)Sum with an additional number" << endl << "(5)Exit the program" << endl;
		cin >> serial;
		while (serial < 1 || serial > 5) {
			cout << "Note, the serial number must be between 1-5, please enter again" << endl;
			cin >> serial;
			continue;
		}
		if (serial == 1) {
			cout << "please enter a number to Update the numerator" << endl;
			cin >> newup;
			up = newup;
			frac1.updateNumerator(newup);
		}
		if (serial == 2) {
			cout << "please enter a number to Update the denominator" << endl;
			cin >> newdown;
			down = newdown;
			frac1.updateDenominator(newdown);
		}
		if (serial == 3) { frac1.printValue(); }
		if (serial == 4) {
			cout << "Please enter another float number to add to your fraction num" << endl;
			cin >> anothernum;
			flofrac1 = frac1.value();
			cout << "The sum of ";
			if (down < 0) { cout << (-1) * up << "/" << (-1) * down; }
			else { cout << up << "/" << down; }
			sum = flofrac1 + anothernum;
			if (sum - int(sum) == 0) { cout << " and " << flofrac1 << " is: " << sum << ".0" << endl; }
			else { cout << " and " << flofrac1 << " is: " << sum << endl; }
		}
		if (serial == 5) { return; }
	}
}

void Menu::stringMenu() {
	String str;
	bool b;
	int serial, idx, i;
	char character, temp, arr[10];
	while (true) {
		cout << "Please enter a serial number between 1-8" << endl;
		cout << "(1)Update string" << endl << "(2)Update string char by char" << endl;
		cout << "(3)Update a single char from the string" << endl << "(4)Get a single char from the string" << endl;
		cout << "(5)Print string" << endl << "(6)Print string (lowercase)" << endl;
		cout << "(7)Print string (uppercase)" << endl << "(8)Exit the program" << endl;
		cin >> serial;
		while (serial < 1 || serial > 8) {
			cout << "Note, the serial number must be between 1-8, please enter again" << endl;
			cin >> serial;
			continue;
		}
		if (serial == 1) {
			cout << "Enter a string" << endl;
			i = 0;
			while (cin.get() != '\n') {}
			while (true) {
				cin.get(temp);
				if (temp == '\n') { break; }
				if (i < 10) { arr[i] = temp; }
				i++;
			}
			if (i > 9) { arr[9] = 0; }
			else { for (i; i < 9; i++) { arr[i] = 0; } }
			str.updateValue(arr);
		}
		if (serial == 2) {
			if (str.setCharsByUser()) { cout << "Update successfully" << endl; }
			else { cout << "Update failed" << endl; }
		}
		if (serial == 3) {
			cout << "Enter an index (0-9)" << endl;
			cin >> idx;
			cout << "Enter a char" << endl;
			cin >> character;
			b = str.setCharAt(character, idx);
			if (!b) { cout << "Invalid index"; }
		}
		if (serial == 4) {
			cout << "Enter an index (0-9)" << endl;
			cin >> idx;
			character = str.getCharAt(idx);
			cout << "The value in index " << idx << " is: " << character << endl;
		}
		if (serial == 5) { str.printValue(); }
		if (serial == 6) { str.printValue(false); }
		if (serial == 7) { str.printValue(true); }
		if (serial == 8) { return; }
	}
}