//Array , Hash Table , Greedy , Sorting , Counting

#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // set<int> unique (arr.begin(), arr.end());

        unordered_map<int,int> freqMap;
        
        for(int i =0; i < arr.size(); i++){ // to store elements and frequencies 
            freqMap[arr[i]]++;
        }

        vector<int> freqVec; // vec with frequencies

        for (auto& entry : freqMap) {
        freqVec.push_back(entry.second);  
        }
        sort(freqVec.begin(), freqVec.end());

        // while(k--){ // Remove the least frequent element until k becomes zero
        //     auto topPair = queue.top();
        //     int freq = topPair.first;
        //     int num = topPair.second;
        //     queue.pop();
        //     // Remove element from set
        //     unique.erase(num);
        // }

        int uniqueCount = freqVec.size();
        for (int i : freqVec){
            if( i <= k){
                k -= i; // Subtract the frequency from k
                uniqueCount--;  // Reduce unique count
            }
            else{
                break; // If k becomes negative, stop the loop
            }
        }
        return uniqueCount;
    }
};

// Count the frequency of each num 
// Sort the frequencies
// subtracting each frequency from k until k becomes negative
// Return the number of frequencies processed as the result


int main() {
    Solution solution;
    vector<int> arr1 = {5, 5, 4};
    int k1 = 1;
    cout << "Output for arr1: " << solution.findLeastNumOfUniqueInts(arr1, k1) << endl;

    vector<int> arr2 = {4, 3, 1, 1, 3, 3, 2};
    int k2 = 3;
    cout << "Output for arr2: " << solution.findLeastNumOfUniqueInts(arr2, k2) << endl;

    return 0;
}
