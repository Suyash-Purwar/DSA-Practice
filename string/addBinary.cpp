/**
 * @file 67. Add Binary (Leetcode Easy)
 * @link https://leetcode.com/problems/add-binary (Leetcode Easy)
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 02-09-2023
*/	

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution {
public:
	string addBinary(string a, string b) {
		int d1, d2, carry = 0;
		int i = a.length(), j = b.length();
		string ans = "";

		while (i >= 0 || j >= 0) {
			(0 > i) ? d1 = 0 : d1 = a[i] - '0';
			(0 > j) ? d2 = 0 : d2 = b[j] - '0';

			int sum = d1 + d2 + carry;

			switch (sum) {
			case 0:
				carry = 0;
				ans = "0" + ans;
				break;
			case 1:
				carry = 0;
				ans = "1" + ans;
				break;
			case 2:
				carry = 1;
				ans = "0" + ans;
				break;
			case 3:
				carry = 1;
				ans = "1" + ans;
				break;
			}

			i--;
			j--;
		}

		if (carry) ans = "1" + ans;

		return ans;
	}
};

int main() {
	Solution sol;

	string a1 = "1010";
	string a2 = "1011";

	cout << sol.addBinary(a1, a2) << endl;
}