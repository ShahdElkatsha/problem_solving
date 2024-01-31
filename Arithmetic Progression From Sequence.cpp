#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int commonDiff = arr[1] - arr[0];

        for (int i = 1; i < arr.size() - 1; ++i) {
            if (arr[i + 1] - arr[i] != commonDiff) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
 
    vector<int> Arr = {5, 3, 1, 7, 9};  
    bool result = solution.canMakeArithmeticProgression(Arr);

    cout << "Can make arithmetic progression: " << boolalpha << result << endl;

    return 0;
}
