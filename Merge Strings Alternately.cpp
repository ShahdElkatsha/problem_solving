//Two Pointers , String
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        string result = "";
        int i = 0, j = 0;

        while (i < m || j < n) {
            if (i < m) {
                result.push_back(word1[i++]);
            }
            if (j < n) {
                result.push_back(word2[j++]);
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    string exampleWord1 = "abc";
    string exampleWord2 = "12345";
    string mergedResult = solution.mergeAlternately(exampleWord1, exampleWord2);

    cout << "Merged Result: " << mergedResult << endl;

    return 0;
}
