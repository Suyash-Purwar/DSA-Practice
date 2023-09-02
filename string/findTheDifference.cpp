/**
 * @file 389. Find the Difference (Leetcode Easy)
 * @link https://leetcode.com/problems/find-the-difference/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 02-09-2023
*/	

#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Solution {
public:
	char findTheDifference(string s, string t) {
		char ans = 0;

		for (int i = 0; i < s.length(); i++) {
			ans = ans ^ s[i];
		}

		for (int j = 0; j < t.length(); j++) {
			ans = ans ^ t[j];
		}

		return ans;
	}
};

int main() {
	Solution sol;

	cout << sol.findTheDifference("abd", "bdea") << endl;
}