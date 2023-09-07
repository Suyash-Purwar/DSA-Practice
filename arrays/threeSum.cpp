/**
 * @file 15. 3 Sum (Leetcode Easy)
 * @link https://leetcode.com/problems/3sum/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 07-09-2023
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using std::cout;
using std::vector;
using std::endl;
using std::set;
using std::sort;

class Util {
public:
	static void printArray(vector<int>& nums) {
		for (auto i: nums) {
			cout << i << " ";
		} cout << endl;
	}

	static void print2dArray(vector<vector<int>>& nums) {
		for (auto i: nums) {
			for (auto j: i) {
				cout << j << " ";
			} cout << endl;
		}
	}
};

class Solution {
public:
	// TC: O(n^3)
	// SC: O(n+m)
	vector<vector<int>> threeSum1(vector<int>& nums) {
		set<vector<int>> uniqueVec;
		int n = nums.size();

		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				for (int k = j+1; k < n; k++) {
					if (nums[i] + nums[j] + nums[k] == 0) {
						vector<int> temp = {nums[i], nums[j], nums[k]};
						sort(temp.begin(), temp.end());
						uniqueVec.insert(temp);
					}
				}
			}
		}

		vector<vector<int>> ans(uniqueVec.begin(), uniqueVec.end());
		return ans;
	}

	// TC: O(n^2*logm)
	// Why? Finding an element in the hashset taken logn, where n is the size of the hashset.
	// Size of the hashset varies, thus the total complexity is O(n^2*logm)
	// SC: O(n) + O(k)
	// O(n) is contributed by the hashset
	// O(k) is contributed by the no of unique triplets (because of additonal 'st' variable we are using)
	// Why the variable 'ans' wasn't accounted? Because it's a part of the answer
	// GIVES TLE
	vector<vector<int>> threeSum2(vector<int>& nums) {
		set<vector<int>> st;

		int n = nums.size();

		for (int i = 0; i < n; i++) {
			set<int> hashset;
			for (int j = i+1; j < n; j++) {
				int more = -(nums[i] + nums[j]);

				if (hashset.find(more) != hashset.end()) {
					vector<int> temp = {nums[i], nums[j], more};
					sort(temp.begin(), temp.end());
					st.insert(temp);
				}

				hashset.insert(nums[j]);
			}
		}

		vector<vector<int>> ans(st.begin(), st.end());
		return ans;
	}

	// TC: O(n^2)
	// SC: O(1)
	vector<vector<int>> threeSum3(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n-2; i++) {
            int low = i+1;
            int high = n-1;

            if (nums[i] > 0) break;

            if (i > 0 && nums[i] == nums[i-1]) continue;

            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                if (sum > 0) {
                    high--;
                } else if (sum < 0) {
                    low++;
                } else {
                    ans.push_back({nums[i], nums[low], nums[high]});
                    while (low < high && nums[low] == nums[low+1]) low++;
                    while (low < high && nums[high] == nums[high-1]) high--;
                    high--;
                    low++;
                }
            }
        }

        return ans;
	}
};

int main() {
	Solution sol;

	vector<int> i1 = {3, 1, 2, -2, 1, -4, 2};
	vector<int> i2 = {1, 0, -1, 2, -1, 4};
	vector<int> i3 = {-1, 0, 1, 2, -1, -4};
	vector<int> i4 = {0, 0, 0, 0};
	vector<int> i5 = {-2, 0, 0, 2, 2};

	// vector<vector<int>> ans1 = sol.threeSum1(i1);
	// vector<vector<int>> ans2 = sol.threeSum1(i2);
	// vector<vector<int>> ans5 = sol.threeSum1(i3);

	// Util::print2dArray(ans1);
	// Util::print2dArray(ans2);
	// Util::print2dArray(ans5);

	// cout << endl << endl;

	vector<vector<int>> ans3 = sol.threeSum2(i1);
	vector<vector<int>> ans4 = sol.threeSum2(i2);
	vector<vector<int>> ans6 = sol.threeSum2(i3);

	Util::print2dArray(ans3);
	Util::print2dArray(ans4);
	Util::print2dArray(ans6);

	cout << endl << endl;

	// vector<vector<int>> ans7 = sol.threeSum3(i1);
	// vector<vector<int>> ans8 = sol.threeSum3(i2);
	// vector<vector<int>> ans9 = sol.threeSum3(i3);
	vector<vector<int>> ans10 = sol.threeSum3(i4);
	vector<vector<int>> ans11 = sol.threeSum3(i5);

	// Util::print2dArray(ans7);
	// Util::print2dArray(ans8);
	// Util::print2dArray(ans9);
	Util::print2dArray(ans10);
	Util::print2dArray(ans11);
}