/**
 * @file 2418. Sort the People (Leetcode Easy)
 * @link https://leetcode.com/problems/sort-the-people
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 31-08-2023
*/	

#include <vector>
#include <iostream>
#include <string>
#include <map>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

class Solution {
public:
	vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
		map<int, string> dict;
		int n = names.size();

		for (int i = 0; i < n; i++) {
			dict[heights[i]] = names[i];

			cout << heights[i] << names[i] << endl;
		}

		int i = 0;
		for (auto rit = dict.rbegin(); rit != dict.rend(); rit++) {
			names[i] = rit->second;
			i++;
		}

		return names;
	}
};

int main() {
	Solution sol;

	vector<string> names = {"Mary","John","Emma"};
	vector<int> heights = {180,165,170};

	vector<string> opt = sol.sortPeople(names, heights);

	for (auto name: opt) {
		cout << name << " ";
	} cout << endl;
}