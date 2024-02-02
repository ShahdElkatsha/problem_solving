//Enumeration

#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;

        for(int i = 1; i <= 9; ++i) {
            int num = i;
            for(int z = i + 1; z <= 9; ++z) {
                num = num * 10 + z;

                if (num >= low && num <= high && (num % 10 != 0))
                    res.push_back(num);
                else if (num > high)
                    break;
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution solution;

    // Ex 1
    int low1 = 100, high1 = 300;
    vector<int> result1 = solution.sequentialDigits(low1, high1);
    cout << "Output (Example 1): ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Ex 2
    int low2 = 1000, high2 = 13000;
    vector<int> result2 = solution.sequentialDigits(low2, high2);
    cout << "Output (Example 2): ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
