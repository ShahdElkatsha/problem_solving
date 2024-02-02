//Array , Greedy , Sorting

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {

    vector<vector<int>> res;
    int size = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 2; i < size; i+=3) {
        if(nums[i] - nums[i-2] > k) return {};
        res.push_back({nums[i-2],nums[i-1], nums[i]});
    }     

    return res;

        // vector<vector<int>> res;
        // sort(nums.begin(),nums.end());
        // int size = nums.size();

        // for(int i = 0; i < size; i+=3){
        //     vector<int>Arr;     // smail arrs(3)
        //     Arr.push_back(nums[i]);  // store begin of each small arr

        //     for(int z=i+1; z<min(i+3,size) ; ++z){  //sore other nums of each small arr
        //         if(nums[z] - Arr.back() <=k){
        //             Arr.push_back(nums[z]);
        //         }
               
        //         else {
        //         // If  difference  not satisfied, clear Arr and break
        //             Arr.clear();
        //             break;
        //         }
        //     }

        //     if (Arr.size() == 3) {
        //         res.push_back(Arr);
        //     }else{
        //         res.clear();
        //     }
        // }

        // return res;
    }
};

int main() {
    Solution solution;

    // Example
    vector<int> nums = {17, 15, 20, 16, 15, 10, 20, 19, 17};
    int k = 2;

    vector<vector<int>> result = solution.divideArray(nums, k);

    if (result.empty()) {
        cout << "Unable to satisfy conditions." << endl;
    } else {
        cout << "Output: " << endl;
        for (const vector<int>& arr : result) {
            cout << "[ ";
            for (int num : arr) {
                cout << num << " ";
            }
            cout << "]" << endl;
        }
    }

    return 0;
}
