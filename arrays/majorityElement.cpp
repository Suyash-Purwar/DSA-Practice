#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::sort;

class Solution {
public:
	// TC: O(nlogn + n)
	// SC: O(1)
	int majorityElement1(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int cnt = 1;
		int prev = nums[0];
		int n = nums.size();

		for (int i = 1; i < n; i++) {
			if (nums[i] != prev) {
				if (cnt > n/2) return prev;
				prev = nums[i];
				cnt = 1;
			} else {
				cnt++;				
			}
		}

		return (cnt > n/2 ? nums[n-1] : -1);
	}

	// TC: O(nlogn)
	// SC: O(1)
	// Approach: It is given that there is always a number which is appearing more than n/2 times. It is obvious that after sorting the array the middle element will be the majority element.
	int majorityElement2(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		return nums[nums.size()/2];
	}

	// TC: O(n + n/2)
	// SC: O(n/2)
	int majorityElement3(vector<int>& nums) {
		unordered_map<int, int> freq;
		int n = nums.size();

		// O(n)
		for (int i = 0; i < n; i++) {
			if (!freq.count(nums[i])) freq[nums[i]] = 1;
			else freq[nums[i]]++;
		}

		// O(n/2)
		for (auto record: freq) {
			if (record.second > n/2) {
				return record.first;
			}
		}

		return -1;
	}

	// TC: O(2n)
	// SC: O(1)
	int majorityElement4(vector<int>& nums) {
		int vote = 0, el, count = 0;
		int n = nums.size();

		for (int i = 0; i < n; i++) {
			if (vote == 0) {
				vote = 1;
				el = nums[i];
			} else if (nums[i] == el) {
				vote++;
			} else {
				vote--;
			};
		}

		for (int i: nums) {
			if (i == el) count++;
		}

		if (count > n/2) return el;

		return -1;
	}
};

int main() {
	Solution sol;

	vector<int> i1 = {2, 2, 1, 2, 1, 1, 1};
	vector<int> i2 = {3, 2, 3};

	cout << sol.majorityElement2(i1) << endl;
	cout << sol.majorityElement2(i2) << endl;
}