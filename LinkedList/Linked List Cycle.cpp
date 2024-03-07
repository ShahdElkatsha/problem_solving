//Hash Table , Linked List , Two Pointers

/*
The problem:
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
 */

#include <iostream>
#include <unordered_set>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> visited;

    // Traverse the linked list
    while (head != NULL) {
        // Check if the current node has been visited before
        if (visited.find(head) != visited.end()) {
            // If the node is found in the set, it means there is a cycle
            return true;
        }
        // Add the current node to the set of visited nodes
        visited.insert(head);
        // Move to the next node
        head = head->next;
    }

    // If we reach the end of the list without finding any cycles, return false
    return false;
}

// Utility function to create a linked list with cycle at a specific position (for testing)
ListNode* createLinkedListWithCycle(int arr[], int n, int pos) {
    ListNode *head = NULL;
    ListNode *tail = NULL;
    ListNode *cycleNode = NULL;

    for (int i = 0; i < n; i++) {
        ListNode *newNode = new ListNode(arr[i]);
        if (i == pos) {
            cycleNode = newNode; // Store the node where the cycle begins
        }
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Create cycle by linking tail to cycleNode
    tail->next = cycleNode;

    return head;
}

int main() {
    // Example usage
    int arr[] = {3, 2, 0, -4};
    int pos = 1; // Cycle at index 1
    ListNode *head = createLinkedListWithCycle(arr, sizeof(arr) / sizeof(arr[0]), pos);

    if (hasCycle(head)) {
        cout << "The linked list has a cycle." << endl;
    } else {
        cout << "The linked list does not have a cycle." << endl;
    }

    return 0;
}
