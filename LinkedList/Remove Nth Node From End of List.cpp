//Linked List , Two Pointers

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* curr = head;
        
        // Calculate length of linked list
        while(curr != nullptr){
            length++;
            curr = curr->next;
        }
        // Find position to remove
        int remo = length - n - 1;
        int i = 0;
        curr = head;

        // If head needs to be removed (first element)
        if(remo == -1){
            head = head->next;
            delete curr;
            return head;
        }

        // Traverse to node before the  one to be removed
        while (i < remo) {
            curr = curr->next;
            i++;
        }

        // Remove the nth node from the end
        ListNode* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;

        return head;
    }
};

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int n = 2;
    cout << "Original List: ";
    printList(head);
    head = solution.removeNthFromEnd(head, n);
    cout << "List after removing " << n << "th node from the end: ";
    printList(head);
    return 0;
}
