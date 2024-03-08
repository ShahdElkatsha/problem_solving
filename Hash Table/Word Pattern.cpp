//Hash Table, String
#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWordMap;
        unordered_map<string, char> wordToCharMap;

        stringstream ss(s);
        string word;
        int i = 0;

        while (ss >> word) {
            if (i >= pattern.length() || 
                (charToWordMap.count(pattern[i]) && charToWordMap[pattern[i]] != word) || 
                (wordToCharMap.count(word) && wordToCharMap[word] != pattern[i])) {
                return false;
            }

            charToWordMap[pattern[i]] = word;
            wordToCharMap[word] = pattern[i];

            i++;
        }

        return i == pattern.length() && ss.eof();
    }
};

int main() {
    Solution solution;

    // Example usage
    string pattern1 = "abba";
    string s1 = "dog cat cat dog";
    cout << "Pattern 1: " << boolalpha << solution.wordPattern(pattern1, s1) << endl;

    string pattern2 = "abba";
    string s2 = "dog cat cat fish";
    cout << "Pattern 2: " << boolalpha << solution.wordPattern(pattern2, s2) << endl;

    string pattern3 = "aaaa";
    string s3 = "dog cat cat dog";
    cout << "Pattern 3: " << boolalpha << solution.wordPattern(pattern3, s3) << endl;

    return 0;
}
