//Math, Prefix Sum
/*the problem:
Given a positive integer n, find the pivot integer x such that:

The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.
 */

#include <iostream>
#include <cmath>

class Solution {
public:
    int pivotInteger(int n) {
        int sum = n * (n + 1) / 2;
        double a = sqrt(sum);

        if (a - ceil(a) == 0)
            return int(a);
        else
            return -1;
    }
};

int main() {
    // Test cases
    Solution solution;

    // Test case 1: n = 3
    int n1 = 3;
    std::cout << "For n = " << n1 << ", pivot integer is: " << solution.pivotInteger(n1) << std::endl;

    // Test case 2: n = 5
    int n2 = 5;
    std::cout << "For n = " << n2 << ", pivot integer is: " << solution.pivotInteger(n2) << std::endl;

    // Test case 3: n = 8
    int n3 = 8;
    std::cout << "For n = " << n3 << ", pivot integer is: " << solution.pivotInteger(n3) << std::endl;

    return 0;
}
