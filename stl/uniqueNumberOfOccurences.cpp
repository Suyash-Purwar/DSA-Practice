/**
 * @file 1207. Unique Number of Occurrences
 * @brief Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.
 * @link https://leetcode.com/problems/unique-number-of-occurrences/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 24-06-2023
*/


#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::set;

class Solution {
public:
	bool uniqueOccurences(vector<int>& arr) {
		unordered_map<int, int> occurences;
		set<int> uniques;
		for (int num: arr) {
			occurences.count(num) ? occurences[num] += 1 : occurences[num] = 1;
		}
		for (auto kv: occurences) {
			uniques.insert(kv.second);
		}
		return (occurences.size() == uniques.size());
	}
};

int main() {
	Solution sol;
	vector<int> v1 = {-3,0,1,-3,1,1,1,-3,10,0};
	vector<int> v2 = {1, 2};
	vector<int> v3 = {1,2,2,1,1,3};
	cout << sol.uniqueOccurences(v3);
}