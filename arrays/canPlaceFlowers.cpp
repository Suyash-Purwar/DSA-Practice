/*
 * @file 169. 605. Can Place Flowers (Leetcode Easy)
 * @brief You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots. Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.
 * @link https://leetcode.com/problems/can-place-flowers/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 21-07-2023
*/

#include<iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
	bool canPlaceFlowers1(vector<int>& flowerbed, int n) {
		if (!n) return true;
		if (flowerbed.size() == 1 && !flowerbed[0]) return true;

		for (int i = 1; i < flowerbed.size(); i++) {
			if (flowerbed[i] == !flowerbed[i-1]) continue;

			if (i == 1) n--;
			else if (i+1 == flowerbed.size()) n--;
			else if (!flowerbed[i+1]) {
				n--;
				flowerbed[i] = 1;
			}

			if (n == 0) return true;
		}

		return false;
	}
};

int main() {
	Solution sol;

	vector<int> i1 = {1, 0, 0, 0, 1};
	vector<int> i2 = {0, 1, 0, 0, 0, 0, 0, 0, 1};
	vector<int> i3 = {0, 0, 1, 0, 1};

	cout << sol.canPlaceFlowers2(i1, 1) << endl;
	// cout << sol.canPlaceFlowers2(i1, 2) << endl;
	// cout << sol.canPlaceFlowers2(i2, 1) << endl;
	// cout << sol.canPlaceFlowers2(i3, 1) << endl;
}