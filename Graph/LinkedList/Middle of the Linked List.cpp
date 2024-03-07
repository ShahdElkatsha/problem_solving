//Linked List , Two Pointers
/*
the problem:
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.
*/

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
    ListNode* middleNode(ListNode* head) {
        ListNode *oneStep = head; // oneStep pointer moves one step at a time
        ListNode *twoStep = head; // twoStep pointer moves two steps at a time

        while (twoStep != NULL) {
            twoStep = twoStep->next; // Move the hare pointer two steps forward

            if (twoStep != NULL) { // Check if the hare pointer is not NULL (to avoid accessing next of NULL)
                twoStep = twoStep->next;
                oneStep = oneStep->next;
            }
        }
        return oneStep;
    }
};

// Utility function to create a linked list (for testing)
ListNode* createLinkedList(int arr[], int n) {
    ListNode *head = NULL;
    ListNode *tail = NULL;

    for (int i = 0; i < n; i++) {
        ListNode *newNode = new ListNode(arr[i]);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// Utility function to print a linked list (for testing)
void printLinkedList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Solution solution;

    // Create a linked list for testing
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    ListNode *head = createLinkedList(arr, n);

    cout << "Original Linked List: ";
    printLinkedList(head);

    // Find the middle node of the linked list
    ListNode *middle = solution.middleNode(head);

    cout << "Middle Node
