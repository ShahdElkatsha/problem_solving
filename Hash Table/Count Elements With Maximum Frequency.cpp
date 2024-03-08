//Array , Hash Table , Counting

/*
the problem:
You are given an array nums consisting of positive integers.
Return the total frequencies of elements in nums such that those elements all have the maximum frequency.
The frequency of an element is the number of occurrences of that element in the array.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> frequency;
        for (int num : nums) {
            frequency[num]++;
        }

        int maxFrequency = 0;
        for (const auto& num : frequency) {
            maxFrequency = max(maxFrequency , num.second);
        }

        int maxFreqElements = 0;
        for (const auto& num : frequency) {
            if(num.second == maxFrequency){
                maxFreqElements++;
            }
        }
        int totalSum = maxFrequency * maxFreqElements;

        return totalSum;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 2, 3, 1, 4};
    int result = solution.maxFrequencyElements(nums);
    cout << "Total sum of elements with maximum frequency: " << result << endl;
    return 0;
}
