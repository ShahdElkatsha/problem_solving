//Array , Hash Table , String , Sorting

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Create a hashmap to store groups of anagrams
        unordered_map<string, vector<string>> anagramGroups;

        // Iterate through each string in the input array
        for (const string& str : strs) {
            // Create a key by sorting the characters of the string
            string key = str;
            sort(key.begin(), key.end());

            // Add the string to the corresponding group based on the key
            anagramGroups[key].push_back(str);
        }

        // Convert the hashmap to a vector of vectors for the result
        vector<vector<string>> result;
        for (const auto& entry : anagramGroups) {
            result.push_back(entry.second); // Add the group to the result
        }

        return result;
    }
};

int main() {
    // Test cases
    vector<vector<string>> testCases = {
        {"eat", "tea", "tan", "ate", "nat", "bat"},
        {""},
        {"a"}
    };

    Solution solution;

    // Process each test case
    for (const auto& testCase : testCases) {
        cout << "Input: [";
        for (const string& str : testCase) {
            cout << "\"" << str << "\", ";
        }
        cout << "]" << endl;

        // Get the result from the solution
        vector<vector<string>> result = solution.groupAnagrams(testCase);

        // Print the result
        cout << "Output:" << endl;
        for (const vector<string>& group : result) {
            cout << "[";
            for (const string& str : group) {
                cout << "\"" << str << "\", ";
            }
            cout << "]" << endl;
        }

        cout << "----------------------" << endl;
    }

    return 0;
}
