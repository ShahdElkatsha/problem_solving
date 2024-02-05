#include <iostream>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        for (int i = 0; i < s.length(); i++) {
            bool unique = true;
            for (int z = 0; z < s.length(); z++) {
                if (s[i] == s[z] && i != z) {
                    unique = false;
                    break;
                }
            }
            if (unique == true)
                return i;
        }
        return -1;
    }
};

int main() {
    Solution solution;

    // Ex 1
    string s1 = "leetcode";
    cout << "Example 1: " << solution.firstUniqChar(s1) << endl;

    // Ex 2
    string s2 = "loveleetcode";
    cout << "Example 2: " << solution.firstUniqChar(s2) << endl;

    // Ex 3
    string s3 = "aabb";
    cout << "Example 3: " << solution.firstUniqChar(s3) << endl;

    return 0;
}
