#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int counter = 0;
        int n = s.length();

        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1 && isspace(s[i])) {  // space before
                n--;  // reduce length
            } else if (i != n - 1 && isspace(s[i])) {  // space after
                return counter;
            } else {
                counter++;
            }
        }
        return counter;
    }
};

int main() {
    Solution solution;

    // Example usage
    string exampleString1 = "Hello World";
    cout << "Length of last word: " << solution.lengthOfLastWord(exampleString1) << endl;

    string exampleString2 = "   OpenAI   ";
    cout << "Length of last word: " << solution.lengthOfLastWord(exampleString2) << endl;

    string exampleString3 = "NoSpaceAfter";
    cout << "Length of last word: " << solution.lengthOfLastWord(exampleString3) << endl;

    return 0;
}
