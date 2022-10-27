/**
 * @file Plus One (Leetcode Easy)
 * @brief You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
 * @link https://leetcode.com/problems/plus-one/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 27-10-2022
*/
#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Solution {
    public:
    vector<int> plusOne(vector<int> &digits) {
        int lastDigit;
        int carry = 0;
        vector<int> newDigits;

        for (int i = digits.size()-1; i >= 0; i--) {
            if (i != digits.size()-1) {
                if (digits[i] + carry == 10) {
                    newDigits.insert(newDigits.begin(), 0);
                    if (i == 0) newDigits.insert(newDigits.begin(), 1);
                } else {
                    newDigits.insert(newDigits.begin(), digits[i] + carry);
                    carry = 0;
                }
            } else {
                lastDigit = digits[digits.size()-1] + 1;
                if (lastDigit == 10) {
                    carry = 1;
                    newDigits.push_back(0);
                    if (i == 0) newDigits.insert(newDigits.begin(), 1);
                } else {
                    carry = 0;
                    newDigits.push_back(lastDigit);
                }
            }
        }

        return newDigits;
    }
};

int main() {
    Solution sol;
    vector<int> d1 = {9};
    vector<int> d2 = {9, 9};
    vector<int> d3 = {9, 8, 9};
    vector<int> d4 = {1, 2, 3};
    vector<int> d5 = {9, 8, 9, 9};
    vector<int> d6 = {4, 3, 2, 1};

    vector<int> res = sol.plusOne(d6);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}