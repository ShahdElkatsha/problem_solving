//Array & Hash Table
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> countMap;
        unordered_set<int> uniqueCount;

        for (int i : arr) {  //count occurance
            countMap[i]++;
        }

        for (const auto& x : countMap) {
            int count = x.second;  //give current key value

            if (uniqueCount.count(count) > 0) {  //if count unique
                return false;
            }

            uniqueCount.insert(count);  //insert count into set
        }

        return true;
    }
};

int main() {
    Solution solution;

    vector<int> Arr1 = {1, 2, 2, 1, 1, 3};
    cout << "Ex 1: " << solution.uniqueOccurrences(Arr1) << endl;

    vector<int> Arr2 = {1, 2, 2, 3, 3, 3};
    cout << "Ex 2: " << solution.uniqueOccurrences(Arr2) << endl;

    vector<int> Arr3 = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    cout << "Ex 3: " << solution.uniqueOccurrences(Arr3) << endl;

    return 0;
}
