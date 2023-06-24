#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
	int a = 6;
	auto b = a;
	// Infers the type of variable b from variable a
	// auto is a move towards a weakly typed language approach
	cout << b << endl;

	auto str = "Suyash";
	// We can't do this as the type of variable str was inferred
	// to be string and storing int into a string type of variable
	// is a violoation.
	// str = 2;
	cout << str << endl;

	float f1 = 4.23;
	auto f1_pointer = &f1;

	cout << f1_pointer << endl;

	return 0;
}