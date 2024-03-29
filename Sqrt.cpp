//Math, Binary Search

#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }

        int left = 1, right = x / 2;   // Binary search
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (mid <= x / mid) {
                left = mid + 1;
                result = mid;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;

    // Example usage
    int exampleX1 = 4;
    cout << "Square Root of " << exampleX1 << ": " << solution.mySqrt(exampleX1) << endl;

    int exampleX2 = 8;
    cout << "Square Root of " << exampleX2 << ": " << solution.my
