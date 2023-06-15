/**
 * @name Find position of set bit
 * @brief Given a number N having only one ‘1’ and all other ’0’s in its binary representation, find position of the only set bit. If there are 0 or more than 1 set bit the answer should be -1. Position of  set bit '1' should be counted starting with 1 from LSB side in binary representation of the number.
 * @link https://practice.geeksforgeeks.org/problems/find-position-of-set-bit3706/1 (Easy)
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 15-06-23
 */

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
	// Implementation 1
	int findPosition1(int n) {
		int position = -1; int isFound = false;
		int nOfShifts = 1;
		while (n != 0) {
			if (n & 1) {
				if (isFound) return -1;
				position = nOfShifts;
				isFound = true;
			}
			nOfShifts++;
			n = n >> 1;
		}
		return position;
	}

	// Implementation 2
	int findPosition2(int n) {
		if (n <= 0) return -1;
		double power = log2(n) + 1;
		return (ceil(power) == floor(power) ? power : -1);
	}
};

int main() {
	Solution sol;
	cout << sol.findPosition1(25) << endl;
	cout << sol.findPosition2(8) << endl;
}