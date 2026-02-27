#include <iostream>

// Definition for a singly-linked list node.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* partition(ListNode* head, int x) {
    // Pointers for the "before" list (< x)
    ListNode* before_head = nullptr;
    ListNode* before_tail = nullptr;

    // Pointers for the "after" list (>= x)
    ListNode* after_head = nullptr;
    ListNode* after_tail = nullptr;

    ListNode* current = head;
    while (current != nullptr) {
        if (current->val < x) {
            if (before_head == nullptr) {
                before_head = current;
                before_tail = current;
            } else {
                before_tail->next = current;
                before_tail = before_tail->next;
            }
        } else {
            if (after_head == nullptr) {
                after_head = current;
                after_tail = current;
            } else {
                after_tail->next = current;
                after_tail = after_tail->next;
            }
        }
        current = current->next;
    }

    // Crucial step: Terminate both sub-lists
    if (before_tail != nullptr) {
        before_tail->next = nullptr;
    }
    if (after_tail != nullptr) {
        after_tail->next = nullptr;
    }


    // Merge the two lists
    if (before_head == nullptr) {
        // If the "before" list is empty, the "after" list is the new head
        return after_head;
    } else {
        // Append the "after" list to the end of the "before" list
        before_tail->next = after_head;
        return before_head;
    }
}

// Helper function to print the list (for testing)
void printList(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val << " -> ";
        node = node->next;
    }
    std::cout << "NULL" << std::endl;
}

// Example usage:
int main() {
    // Create list: 1 -> 4 -> 3 -> 2 -> 5 -> 2, x = 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    std::cout << "Original list: ";
    printList(head);

    ListNode* partitioned_head = partition(head, 3);

    std::cout << "Partitioned list around 3: ";
    printList(partitioned_head);

    // Expected Output: 1 -> 2 -> 2 -> 4 -> 3 -> 5 -> NULL

    // Clean up memory (omitted for brevity in this example, but essential in C++)
    return 0;
}