//Two Pointers , String

/*
The problem:
Given a string s consisting only of characters 'a', 'b', and 'c'. You are asked to apply the following algorithm on the string any number of times:

Pick a non-empty prefix from the string s where all the characters in the prefix are equal.
Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
The prefix and the suffix should not intersect at any index.
The characters from the prefix and suffix must be the same.
Delete both the prefix and the suffix.
Return the minimum length of s after performing the above operation any number of times (possibly zero times).
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right && s[left] == s[right]) {
            char ch = s[left];

            while(left <= right && s[left] == ch){
                left++;
            }
            while(right >= left && s[right] == ch){
                right--;
            }
        }
        return right - left + 1;
    }
};

int main() {
    Solution solution;
    
    // Example usage
    string s1 = "ca";
    cout << "Minimum length for \"" << s1 << "\": " << solution.minimumLength(s1) << endl;
    
    string s2 = "cabaabac";
    cout << "Minimum length for \"" << s2 << "\": " << solution.minimumLength(s2) << endl;
    
    string s3 = "aabccabba";
    cout << "Minimum length for \"" << s3 << "\": " << solution.minimumLength(s3) << endl;

    return 0;
}
