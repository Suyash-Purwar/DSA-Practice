/**
 * @file 118. Pascal's Triangle I (Leetcode Easy) & Pascal's Triangle II (Leetcode Easy)
 * @link https://leetcode.com/problems/pascals-triangle & https://leetcode.com/problems/pascals-triangle-ii/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 04-09-2023
*/  


/**
 * This question can be framed in three different ways:
 * 
 * 1. Given the Rth row and Cth column, print the element at that position in the pascals triangle
 * 2. Given the Nth row, print all the elements in that row.
 * 3. Given the number of row, return an array of Pascal's Triangle upto that row.
 * 
 * The most bruteforce solution is by running a nested loop and doing it in time complexity of O(n^2).
 * Function 'generate1()' does it this way. It creates the pascals triangle upto the row number provided.
 * It's a solution to the 3rd variation mentioned above. Based on this we can any Rth and Cth element which solves the 1st variation.
 * Similarly, the 2nd variation can only be solved this way.
 * THIS IS AN EXTREME BRUTFORCE SOLUTION
 * 
 * There exists a formula to solve this question and we will be approaching the 1st variation first.
 * To find the element at Rth row and Cth column, use the formula --> (r-1)C(c-1).
 * To solve the formula with bruteforce approach, TC: O(r) + O(c) + O(r-c). (nCr ko compute karne ke liye 3 baar factorial karna padta hai isliye)
 * But there's a shortcut to it too, which gives a TC: O(c) only. Below is the formula
 * ====> nCr = (n-0)*(n-1)*(n-2)*...*(n-c+1) / (c-0)*(c-1)*(c-2)*...*(c-c+1)
 * where n is row number and r is column number
 * Now, here's the example. Suppose we want to find the element at 8th row and 4th column. Here's how we will do it.
 * 8C4 = (8-0)*(8-1)*(8-2)*(8-3) / (4-0)*(4-1)*(4-2)*(4-3) = 70
 * This solves the 1st variation of the problem with TC of O(c) where c is the column.
 * Function 'generate2()' solves the 1st variation with this approach.
 * 
 * This approach can be extended to solve the 2nd variation as well with a TC: O(n*c) where n is row number and c is column number.
 * Function generate3() does this only with TC: O(n*c). It could be optimized to TC of O(n).
 * Finding the elements for Nth row requires us to compute (n-1)C(r-1) for each element but instead of doing it for every element
 * we can multiply the result of previous element with some more other value to get next element.
 * Function generate4() is the optimal solution of 2nd variation with TC: O(n)
 * 
 * Now this approach can again be extended to solve 3rd variation with optimal complexity
 * We can compute elements for every row with this method.
 * Time complexity for computing a row is O(n)
 * For n rows, time coplexity will be around O(n^2)
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

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
	// TC: O(n^2)
	// SC: O(1)
	// Solves the 3rd variation with extreme bruteforce
	vector<vector<int>> generate1(int numRows) {
		vector<vector<int>> ans = {{1}};

		for (int i = 1; i < numRows; i++) {
			vector<int> temp;

			for (int j = 0; j < i+1; j++) {
				if (j - 1 < 0) {
					temp.push_back(ans[i-1][0]);
				} else if (j > ans[i-1].size()-1) {
					temp.push_back(ans[i-1][i-1]);
				} else {
					temp.push_back(ans[i-1][j-1] + ans[i-1][j]);
				}
			}

			ans.push_back(temp);
		}

		return ans;
	}

	// Solves the 1st variation optimally
	int generate2(int row, int col) {
		int ans = 1;
		row--, col--;

		for (int i = 0; i < col; i++) {
			ans = ans * (row - i);
			ans = ans / (i + 1);
		}

		return ans;
	}

	// Solves the 2nd variation by extending the generate2() functionality
	// TC: O(n*c)
	// SC: O(1)
	vector<int> generate3(int row) {
		vector<int> ans_row;
		row--;

		for (int i = 0; i <= row; i++) {
			int ans = 1;
			for (int j = 0; j < i; j++) {
				ans = ans * (row - j);
				ans = ans / (j + 1);
			}

			ans_row.push_back(ans);
		}

		return ans_row;
	}

	// Solves the 2nd variation optimally
	// TC: O(n)
	vector<int> generate4(int row) {
		vector<int> ans = {1};
		int temp = 1;

		for (int i = 1; i < row; i++) {
			temp *= (row - i);
			temp /= i;

			ans.push_back(temp);
		}

		return ans;
	}

	// Solves the 3rd variation optimally
	// TC: O(n^2)
	vector<vector<int>> generate5(int row) {
		vector<vector<int>> ans;
		for (int i = 1; i <= row; i++) {
			vector<int> temp = {1};
			int ele = 1;

			for (int j = 1; j < i; j++) {
				ele *= (i - j);
				ele /= j;

				temp.push_back(ele);
			}

			ans.push_back(temp);
		}

		return ans;
	}
};

int main() {
	Solution sol;

	vector<vector<int>> ans1 = sol.generate1(8);
	Util::print2dArray(ans1);

	cout << sol.generate2(8, 4) << endl;

	vector<int> ans3 = sol.generate3(5);
	Util::printArray(ans3);

	vector<int> ans4 = sol.generate4(2);
	Util::printArray(ans4);

	vector<vector<int>> ans5 = sol.generate5(5);
	Util::print2dArray(ans5);
}