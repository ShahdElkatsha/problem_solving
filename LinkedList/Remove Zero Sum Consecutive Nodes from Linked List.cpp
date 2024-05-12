//Hash Table, Linked List
/*the problem:
Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.
After doing so, return the head of the final linked list.  You may return any such answer.
*/


#include <iostream>

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Your solution class
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode node = ListNode(0, head);
        ListNode* ptr = &node;
        int prefix = 1000000; // The min value for prefix >= -1e6, serves as base for calculating cumulative sum
        static ListNode* mp[2000001] = {nullptr}; // Store pointers to nodes based on their cumulative sum

        while (ptr != nullptr) {
            prefix += (ptr->val);
            mp[prefix] = ptr; // Stores the latest occurrence of each cumulative sum
            ptr = ptr->next;
        }

        prefix = 1000000, ptr = &node; // Reset
        while (ptr != nullptr) {
            prefix += (ptr->val);
            ptr->next = mp[prefix]->next; // Removes consecutive sequence of nodes whose sum = zero bypassing them.
            ptr = ptr->next;
        }
        return node.next;
    }
};

// Test the solution
int main() {
    // Create a sample linked list: 1 -> 2 -> -3 -> 3 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(-3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(1);

    // Create an instance of Solution
    Solution solution;

    // Call the removeZeroSumSublists function
    ListNode* result = solution.removeZeroSumSublists(head);

    // Print the result
    while (result != nullptr) {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;

    return 0;
}

