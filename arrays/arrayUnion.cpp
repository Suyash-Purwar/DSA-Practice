#include <iostream>
#include <set>
#include <unordered_map>

using std::endl;
using std::cout;
using std::set;
using std::unordered_map;
using std::max;

class Solution {
public:
	// Method 1 (Good)
	// TC = O(max(n, m)2(m+n))
	// SC = O(m+n)
	// Complexity of insert() is 0(n)
	int doUnion1(int a[], int n, int b[], int m) {
		int i = 0;
		set<int> ans;
		while (i < max(n, m)) {
			if (i < n) ans.insert(a[i]);
			if (i < m) ans.insert(b[i]);
			i++;
		}
		return ans.size();
	}

	// Method 2
	// TC of access time in unordered map is O(1)
	// TC: max(n, m)
	// SC: max(n + m)
	int doUnion2(int a[], int n, int b[], int m) {
		unordered_map<int, int> count;
		int i = 0;
		while (i < max(n, m)) {
			if (i < n && !count[a[i]]) count[a[i]] = 1;
			if (i < m && !count[b[i]]) count[b[i]] = 1;
			i++;
		}
		return count.size();
	}
};

int main() {
	Solution sol;
	int a[5] = {4, 2, 1, 1, 0};
	int b[3] = {1, 0, 5};

	cout << sol.doUnion1(a, 5, b, 3) << endl;
	cout << sol.doUnion2(a, 5, b, 3) << endl;
}