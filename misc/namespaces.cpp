#include <iostream>

using namespace std;

namespace ns1 {
	string name = "Suyash";
}

namespace ns2 {
	string name = "Shubham";
}

int main() {
	cout << ns1::name << endl;
	cout << ns2::name << endl;
}