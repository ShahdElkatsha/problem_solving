//Array, Two Pointers, Binary Search

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int low = 0;
        int high = numbers.size() - 1;

        while(low <= high){
            if( numbers[low] + numbers[high] == target){
                return {low+1 , high+1} ;   // '+1' for 1-based indexing
            }
            else if(numbers[low] + numbers[high] < target){
                low++;
            }
            else{
                high--;
            }
        }
        return {};
    //     vector<int> res;
    //     for(int i = 0; i < numbers.size() - 1; ++i){
    //         for(int z = i + 1; z < numbers.size(); ++z){
    //             if(numbers[i] + numbers[z] == target ){
    //                 res.push_back(i + 1);  // Adjusted to 1-based indexing
    //                 res.push_back(z + 1);  // Adjusted to 1-based indexing
    //                 return res;
    //             }
    //         }
    //     }
    //     return res;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> numbers1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = solution.twoSum(numbers1, target1);
    cout << "Test Case 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> numbers2 = {2, 3, 4};
    int target2 = 6;
    vector<int> result2 = solution.twoSum(numbers2, target2);
    cout << "Test Case 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 3
    vector<int> numbers3 = {-1, 0};
    int target3 = -1;
    vector<int> result3 = solution.twoSum(numbers3, target3);
    cout << "Test Case 3: ";
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
