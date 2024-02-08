//Two Pointers , String

#include <iostream>
#include <string>
#include <cctype>

class Solution {
public:

    // string removeNonAlphanumeric( string str){
    //     string result;
    //     for( char ch : str){
    //         if (isalnum(ch)) result += ch;
    //     }
    //     return result;
    // }

    bool isPalindrome(string s) {

        string str;
        for (char ch : s) {
            ch = tolower(ch);
            if (isalnum(ch))
                str += ch;
        }
        // str = removeNonAlphanumeric( str );

        int left = 0;
        int right = str.length() -1;
        bool res = true;
        while(left < right){
            
            if(str[left] == str[right]){
                left++;
                right--;
            }else{
                res = false;
                break;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.isPalindrome("A man, a plan, a canal: Panama") << endl; // Output: true
    cout << sol.isPalindrome("race a car") << endl; // Output: false
    return 0;
}
