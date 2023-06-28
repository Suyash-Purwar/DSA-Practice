#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::swap;

class Solution {
public:
	// Good
	// TC: O(2n)
	// SC: O(1)
	void sortColors1(vector<int>& nums) {
		int count_0 = 0, count_1 = 0, count_2 = 0;
		for (int n: nums) {
			switch (n) {
			case 0:
				count_0++;
				break;
			case 1:
				count_1++;
				break;
			case 2:
				count_2++;
				break;
			}
		}
		for (int i = 0; i < nums.size(); i++) {
			if (count_0) {
				nums[i] = 0;
				count_0--;
			}
			else if (count_1) {
				nums[i] = 1;
				count_1--;
			} else {
				nums[i] = 2;
				count_2--;
			}
		}
	}

	// Optimal
	// TC: O(n)
	// SC: O(1)
	void sortColors2(vector<int>& nums) {
		int low = 0;
		int high = nums.size() - 1;
		int mid = 0;

		while (mid <= high) {
			if (nums[mid] == 0) {
				swap(nums[mid], nums[low]);
				low++;
				mid++;
			} else if (nums[mid] == 1) {
				mid++;
			} else if (nums[mid] == 2) {
				swap(nums[mid], nums[high]);
				high--;
			}
		}

		for (int i: nums) cout << i << " ";
		cout << endl;
	}
};

int main() {
	Solution sol;
	vector<int> i1 = {2, 0, 1, 1, 2, 0, 0, 1, 2, 1, 2, 0};
	sol.sortColors2(i1);
}
