//String  , Dynamic Programming(not required)

#include <iostream>

class Solution {
public:
    int countSubstrings(string s) {
        int size = s.length();
        int res = 0 ;
        
        bool palindrome = true;
        for(int i = 0; i < size; i++){
            for(int z = i; z < size; z++){
                palindrome = true; // Reset palindrome for each new substring
                int left = i , right = z;
                while( left < right){
                    if(s[left++] != s[right--]){
                        palindrome = false;
                        break;
                    }
                }
                if(palindrome == true){
                    res++;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    string s = "abcba"; // Test string
    int count = solution.countSubstrings(s); // Call the function
    cout << "Number of palindromic substrings: " << count << endl; // Output the result
    return 0;
}
