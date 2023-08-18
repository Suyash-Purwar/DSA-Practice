/**
 * @file 2125. Number of Laser Beams in a Bank (Leetcode Medium)
 * @link https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 19-08-2023
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
	// TC: O(nm + n)
	// SC: O(n)
	int numberOfBeams1(vector<string>& nums) {
		int beams = 0;
		vector<int> devices(nums.size(), 0);

		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < nums[0].length(); j++) {
				if (nums[i][j] == '1') devices[i]++;
			}
		}

		int prev = devices[0];
		for (int i = 1; i < devices.size(); i++) {
			if (devices[i] == 0) continue;
			beams += prev * devices[i];
			prev = devices[i];
		}

		return beams;
	}

	// TC: O(nm)
	// SC: O(1)
	int numberOfBeams2(vector<string>& nums) {
		int beams = 0; int prev = 0; int devices = 0;

		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < nums[0].length(); j++) {
				if (nums[i][j] == '1') devices++;
			}

			if (i != 0 && devices != 0) {
				beams += prev * devices;
			}


			if (devices) prev = devices;

			devices = 0;
		}

		return beams;
	}
};

int main() {
	Solution sol;

	vector<string> i1 = {"011001","000000","010100","001000"};
	vector<string> i2 = {"000", "010"};
	vector<string> i3 = {"1000", "0011", "0000", "1111", "0100"};

	cout << sol.numberOfBeams2(i2);
}