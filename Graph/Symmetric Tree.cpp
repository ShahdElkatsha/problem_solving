//Tree, Depth-First Search, Breadth-First Search, Binary Tree
#include <iostream>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool check(TreeNode* left, TreeNode* right) {
        if (!left && !right)
            return true;
        if (!left || !right)
            return false;
        return (left->val == right->val && check(left->left, right->right) && check(left->right, right->left));
    }

    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};

int main() {
    Solution solution;

    // Example usage
    TreeNode* T1 = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(4), new TreeNode(3)));
    TreeNode* T2 = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(3)), new TreeNode(2, nullptr, new TreeNode(3)));

    cout << "Is the tree symmetric? " << boolalpha << solution.isSymmetric(T1) << endl;
    cout << "Is the tree symmetric? " << boolalpha << solution.isSymmetric(T2) << endl;


    return 0;
}
