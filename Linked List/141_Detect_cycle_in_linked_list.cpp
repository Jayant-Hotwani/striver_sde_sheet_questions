/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
// Time Complexity: O(n)
// Space Complexity: O(1)
// Detect cycle in linked list
// Approach: Using Floyd's Cycle Detection Algorithm (Tortoise and Hare Algorithm)
// Note: If there is a cycle, the fast and slow pointers will eventually meet.

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {

        if (head == NULL)
            return false;
        if (head->next == NULL)
        {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = head; // Creating a cycle for testing
    bool result = sol.hasCycle(head);
    std::cout << (result ? "Cycle detected" : "No cycle") << std::endl;
    return 0;
}