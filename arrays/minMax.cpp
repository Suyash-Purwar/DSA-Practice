#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
	void minMax(int arr[], int size) {
		int max = INT_MIN;
		int min = INT_MAX;
		for (int i = 0; i < size; i++) {
			if (arr[i] > max) max = arr[i];
			if (arr[i] < min) min = arr[i];
		}
		cout << "Maximum: " << max << endl;
		cout << "Minimum: " << min << endl;
	}
};

int main() {
	int arr[4] = {3, 4, -6, 2};
	int arr2[] = {3};

	Solution sol;
	sol.minMax(arr, 4);
	sol.minMax(arr2, 1);

	return 0;
}