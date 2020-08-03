// Cpp_dec2hex(or*!).cpp.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;

char to_letter(const int num);
int from_letter(const char str);
string to_base(long num, const unsigned int base);
long from_base(const string s, const unsigned int base);

void main() {
	const static unsigned int base = 36;
	long dec_num = 0;
	string hex_num = "";

	cout << hex_num; // ?

	cout << "Wellcome to 'dec2hex(or*!)' application :)" << endl << "please input dec number (int): ";
	cin >> (long)dec_num;
	cout << dec_num;
	cout << "\t is your dec number." << endl;
	
	// converting your dec to hex(or*):
	hex_num = to_base(dec_num, base);
	cout << hex_num;
	cout << "\t is your hex(or*!) num." << endl;
	
	// converting it back:
	cout << endl << "now lets roll it back to dec:" << endl;
	dec_num = from_base(hex_num, base);
	cout << dec_num;
	cout << "\t is your dec num." << endl;
}

char to_letter(const int n) {
	if (n <= 9)
		return char(n + '0');
	else
		return char(n - 10 + 'a');
}

int from_letter(const char c) {
	if (c >= '0' && c <= '9')
		return (c - '0');
	else
		return (c - 'a' + 10);
}

string to_base(long num, const  unsigned int base) {
	string str = "";
	while (num)	{
		str += to_letter(num % base);
		num /= base;
	}
	return str;
}

long from_base(const string str, const unsigned int base) {
	long num = 0;
	for (int i = str.length() - 1; i >= 0; i--) {
		num *= base;
		num += from_letter(str[i]);
	}
	return num;
}
