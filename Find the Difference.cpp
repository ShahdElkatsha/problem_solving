//Hash Table, String, Bit Manipulation, Sorting

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {

        // if(s == "") return t[0];
        // return t[s.length()];

        char result = 0; //ASCII

        for(int i=0;i<s.length();i++){
            result ^=s [i]; //XOR
        }

        for(int i=0;i<t.length();i++){
            result ^= t[i];
        }

        return result;
    }
};

int main() {
    Solution solution;

    string originalString = "abcd";
    string modifiedString = "abcde";

    char addedChar = solution.findTheDifference(originalString, modifiedString);

    cout << "The added char is: " << addedChar << endl;

    return 0;
}
