//Array, Hash Table, Sliding Window

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

        for (int i : arr) {
            countMap[i]++;
        }

        for (const auto& x : countMap) {
            int count = x.second;

            if (uniqueCount.count(count) > 0) {
                return false;
            }

            uniqueCount.insert(count);
        }

        return true;
    }
};

int main() {
    Solution solution;

    // Example usage
    vector<int> exampleArr1 = {1, 2, 2, 1, 1, 3};
    cout << solution.uniqueOccurrences(exampleArr1) << endl;

    vector<int> exampleArr2 = {1, 2, 2, 3, 3, 3};
    cout << solution.uniqueOccurrences(exampleArr2) << endl;

    vector<int> exampleArr3 = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    cout << solution.uniqueOccurrences(exampleArr3) << endl;

    return 0;
}
