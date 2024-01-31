#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;

        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            for (int z = 0; z < word.length(); z++) {
                if (word[z] == x) {
                    res.push_back(i);
                    break;
                }
            }
        }

        return res;
    }
};

int main() {
    Solution solution;

    vector<string> Words = {"apple", "banana", "grape", "orange", "kiwi"};
    char targetChar = 'a';
    vector<int> result = solution.findWordsContaining( Words, targetChar);

   
    cout << "Indices of words containing '" << targetChar << "': ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
