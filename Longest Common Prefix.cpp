//String ,Trie

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) 
            return "";

        for (int i = 0; i < strs[0].size(); ++i) {  // Loop chars word1
            char ch = strs[0][i];
            for (int z = 1; z < strs.size(); ++z) {  // Loop remaining words
                if (i == strs[z].size() || strs[z][i] != ch)
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};

int main() {
    Solution solution;

    // Example usage
    vector<string> exampleStrs1 = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << solution.longestCommonPrefix(exampleStrs1) << endl;

    vector<string> exampleStrs2 = {"dog", "racecar", "car"};
    cout << "Longest Common Prefix: " << solution.longestCommonPrefix(exampleStrs2) << endl;

    return 0;
}
