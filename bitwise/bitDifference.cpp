/**
 * @name 2220. Minimum Bit Flips to Convert Number (Leetcode Easy)
 * @brief A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.
 * @link https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 14-06-23
 */


#include <iostream>

using namespace std;

class Solution {
public:
	int minBitFlips(int a, int b) {
		int n = a ^ b;
		int count = 0;
		for (int i = 0; i < 32; i++) {
			if (n & 1) count++;
			n = n >> 1;
		}
		return count;
	}
};

int main() {
	Solution sol;
	cout << sol.minBitFlips(0, 0);
	return 0;
}