//Two Pointers, String, Dynamic Programming

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int counter = 0;
        int i = 0;

        // for(int i=0;i<s.length();i++){
        for (int z = 0; z < t.length(); z++) {
            if (s[i] == t[z]) {
                counter++;
                i++;
            }
        }
      //}
        return (s.length() == counter);
    }
};

int main() {
    Solution solution;


    string subsequence = "abc";
    string fullString = "ahbgdc";

    bool isSubseq = solution.isSubsequence(subsequence, fullString);

    cout << boolalpha << isSubseq << endl;

    return 0;
}
