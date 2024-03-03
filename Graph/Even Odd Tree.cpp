//Tree , Breadth-First Search , Binary Tree

#include <iostream>
#include <queue>
#include <limits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {

        if (!root) return true;

        queue<TreeNode*> tree;  // queue for level-order traversal
        tree.push(root);
        int level = 0;

        while (!tree.empty()){
            int levelSize = tree.size();
            // Initialize previous value based on the level's parity
            int prevVal = level % 2 == 0 ? numeric_limits<int>::min() : numeric_limits<int>::max();

            // over nodes at current level
            for (int i = 0; i < levelSize; ++i){
                TreeNode* node = tree.front();
                tree.pop();

                // Check current node's value to Even-Odd properties
                if ( (level % 2 == 0 && (node->val % 2 == 0 || node->val <= prevVal)) || (level % 2 != 0 && (node->val % 2 != 0 || node->val >= prevVal)) ){
                    return false;
                }

                // Update previous value for next iteration
                prevVal = node->val;

                if (node->left) {
                    tree.push(node->left);    // Enqueue left child if exists
                } 
                if (node->right) {
                    tree.push(node->right);    // Enqueue right child if exists
                }
            }
            ++level;
        }
        return true;
    }
};


int main() {
    // Example 1
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(10);
    root1->right = new TreeNode(4);
    root1->left->left = new TreeNode(3);
    root1->left->right = nullptr;
    root1->right->left = new TreeNode(7);
    root1->right->right = new TreeNode(9);
    root1->left->left->left = new TreeNode(12);
    root1->left->left->right = new TreeNode(8);
    root1->right->left->left = new TreeNode(6);
    root1->right->left->right = new TreeNode(2);

    cout << "Example 1: " << (isEvenOddTree(root1) ? "true" : "false") << endl;

    // Example 2
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(4);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(3);
    root2->right->left = nullptr;
    root2->right->right = new TreeNode(7);

    cout << "Example 2: " << (isEvenOddTree(root2) ? "true" : "false") << endl;

    return 0;
}
