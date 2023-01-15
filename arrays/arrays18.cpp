#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class Solution {
  public:
  int searchInsert(vector<int>& nums, int target) {
    int size = nums.size();
    int res;
    for (int i = 0; i < size; i++) {
      if (nums[i] >= target) {
        cout << i << " " << "\n";
        res = i;
        break;
      } else if (i == size - 1) {
        res = i + 1;
      }
    }
    return res;
  }
};

int main() {
  vector<int> a1 = {1, 3, 5, 6};

  Solution sol;
  cout << sol.searchInsert(a1, 5);
  return 0;
}