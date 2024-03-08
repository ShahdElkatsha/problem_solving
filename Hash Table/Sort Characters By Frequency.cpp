//Hash Table , String , Sorting , Heap (Priority Queue) , Bucket Sort , Counting

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char , int> freq;
        vector<pair<int,char>> vec;

        // Count the frequency of each character
        for(int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
        }

        // Convert the frequency map to a vector of pairs
        for(auto x : freq) {
            vec.push_back({x.second , x.first});
        }

        // Sort the vector in descending order based on frequency
        sort(vec.begin(), vec.end(), greater<pair<int, char>>());

        // Construct the result string
        string res;
        for(auto i : vec) {
            for(int z = 0; z < i.first; z++) {
                res += i.second;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;

    // Test cases
    string s1 = "tree";
    string s2 = "cccaaa";
    string s3 = "Aabb";

    cout << "Output for s1: " << solution.frequencySort(s1) << endl;
    cout << "Output for s2: " << solution.frequencySort(s2) << endl;
    cout << "Output for s3: " << solution.frequencySort(s3) << endl;

    return 0;
}
