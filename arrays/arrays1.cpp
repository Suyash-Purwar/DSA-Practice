/**
 * @name Palindromic Substring (Leetcode Medium)
 * @brief Given a string s, return the number of palindromic substrings in it. A string is a palindrome when it reads the same backward as forward. A substring is a contiguous sequence of characters within the string.
 * @link https://leetcode.com/problems/palindromic-substrings/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 27-02-2022
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        int printPalindromeSubsequence(string str) {
            int lengthOfString = str.size();
            string seq1 = "", seq2 = "";
            int count = 0;

            for (int i = 0; i < lengthOfString; i++) {
                seq1 = seq2 = "";
                for (int j = i; j < lengthOfString; j++) {
                    seq1 += str[j];
                    if (i == j) {
                        seq2 = seq1;
                        count++;
                    } else {
                        seq2 = str[j] + seq2;
                        if (seq1 == seq2) count++;
                    }
                }
            }

            return count;
        }
};

int main() {
    string str;
    cin >> str;
    Solution sol;
    cout << sol.printPalindromeSubsequence(str);
    return 0;
}