// Array, Hash Table, Divide and Conquer, Sorting, Counting

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> frequencyOfNums;
        int n = nums.size();
        int maxNum = 0;
        int maxFreq = 0;

        for (int i : nums) {
            frequencyOfNums[i]++;
        }

        for (const auto& x : frequencyOfNums) {
            if (x.second >= maxFreq) {
                maxFreq = x.second;
                maxNum = x.first;
            }
        }

        return maxNum;
    }
};

int main() {
    Solution solution;

    // Example usage
    vector<int> exampleNums = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    cout << "Majority Element: " << solution.majorityElement(exampleNums) << endl;

    return 0;
}
