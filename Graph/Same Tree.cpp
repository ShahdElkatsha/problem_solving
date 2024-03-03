//Tree , Depth-First Search, Breadth-First Search, Binary Tree
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q)
            return p == q;

        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    Solution solution;

   
    TreeNode* Tree1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* Tree2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));

    cout << "Are the trees the same? " << boolalpha << solution.isSameTree( Tree1, Tree2) << endl;

    // Clean up allocated memory
    delete Tree1;
    delete Tree2;

    return 0;
}
