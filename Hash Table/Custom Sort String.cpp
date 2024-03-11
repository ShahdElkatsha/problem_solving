//Hash Table , String , Sorting
/*
the problem:
You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.
Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.
Return any permutation of s that satisfies this property.
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {

        unordered_map<char, int> charIndex;// store index of each character in order string
        for (int i = 0; i < order.length(); ++i) {
            charIndex[order[i]] = i;
        }

        sort(s.begin() , s.end() , [&](char a,char b) {   // Sort s based on order string
            
            if (charIndex.find(a) == charIndex.end() && charIndex.find(b) == charIndex.end()) {
                return a < b;   // If both chars are not in the order string, sort them normally
            }
            else if (charIndex.find(a) == charIndex.end()){
                return false;   // If only char 'a' is not in the order string, place 'b' first
            }
            else if (charIndex.find(b) == charIndex.end()){
                return true;   
            }
            else {
                return charIndex[a] < charIndex[b]; // compare the indices of 'a' and 'b' in the order string
            }

        });
        return s;
    }
};


int main() {
    Solution solution;

    // Test case
    string order = "cba";
    string s = "abcd";
    string result = solution.customSortString(order, s);
    cout << "Output: " << result << endl;

    return 0;
}
