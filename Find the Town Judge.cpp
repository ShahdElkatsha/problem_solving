//Array , Hash Table , Graph

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
    vector<int> trusts(n + 1, 0); 
    vector<int> trusted_by(n + 1, 0); 

    for (const auto& pair : trust) {
        int a = pair[0];
        int b = pair[1];
        trusts[a]++;
        trusted_by[b]++;
    }
    
    for (int i = 1; i <= n; ++i) {
        if (trusts[i] == 0 && trusted_by[i] == n - 1) {
            return i; // Person i trusts nobody 
        }
    }
    return -1; // No town judge
    }
};

int main() {
    int n; // Number of people in the town
    cout << "Enter the number of people (n): ";
    cin >> n;

    vector<vector<int>> trust; // Vector to store trust relationships
    int a, b;

    cout << "Enter trust relationships (person trusting, person trusted):\n";
    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0) {
            break; // End of input when both values are 0
        }
        trust.push_back({a, b});
    }

    Solution solution;
    int judge = solution.findJudge(n, trust);

    if (judge != -1) {
        cout << "The judge is: " << judge << endl;
    } else {
        cout << "No judge exists in this town." << endl;
    }

    return 0;
}

    return -1; // No town judge
    }
};
