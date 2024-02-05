//Hash Table , Sliding Window

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> targetChars, windowIndx;

        for (char ch : t) {
            targetChars[ch]++;  // frequency of each char in t
        }

        int left = 0, right = 0; // Pointers for sliding window
        int minLength = INT_MAX; // mini length of window , INT_MAX : to reduce value
        int minLeft = 0; // Left pointer position for the minimum window

        int requiredChars = targetChars.size(); // Num of unique chars in t
        int formedChars = 0; // Num of unique chars formed in the window

        while (right < s.size()) {
            char currentChar = s[right];
            windowIndx[currentChar]++; // Update frequency of the current char in window

            // Check if the current char is in t
            if (targetChars.find(currentChar) != targetChars.end() && windowIndx[currentChar] == targetChars[currentChar]) {
                formedChars++;
            }

            // Try to minimize the window by moving the left pointer
            while (left <= right && formedChars == requiredChars) {
                if (right - left + 1 < minLength) { // Update minimum window information
                    minLength = right - left + 1;
                    minLeft = left;
                }

                // Move left pointer and update window frequency
                char leftChar = s[left];
                windowIndx[leftChar]--;

                // Check if the left char is in t
                if (targetChars.find(leftChar) != targetChars.end() && windowIndx[leftChar] < targetChars[leftChar]) {
                    formedChars--;
                }
                left++;
            }
            right++;
        }
        return minLength == INT_MAX ? "" : s.substr(minLeft, minLength);
    }
};

int main() {
    Solution solution;

    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    cout << "Test 1: " << solution.minWindow(s1, t1) << endl;

    string s2 = "a";
    string t2 = "a";
    cout << "Test 2: " << solution.minWindow(s2, t2) << endl;

    string s3 = "a";
    string t3 = "aa";
    cout << "Test 3: " << solution.minWindow(s3, t3) << endl;

    // Add more test cases as needed

    return 0;
}
