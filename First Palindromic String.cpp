//Array , Two Pointers , String

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {

        for(int i=0 ; i<words.size() ; i++){

            string word = words[i];
            int left = 0;
            int right = word.length() -1;
            bool palindrome = true;

            for(int z=0 ; z<word.length() ; z++){

                if(word[left++] != word[right--]){
                    palindrome = false;
                }
            }
            if(palindrome == true){
                return words[i];
            }

        }

        return "";
        
    }
};

int main() {
    Solution solution;
    vector<string> words = {"hello", "world", "level", "radar", "civic"};
    
    string first_palindrome = solution.firstPalindrome(words);
    
    if (first_palindrome != "")
        cout << "First palindrome word: " << first_palindrome << endl;
    else
        cout << "No palindrome word found." << endl;
    
    return 0;
}
