/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        // Agar list empty hai ya sirf ek node hai,
        // to duplicate hone ka chance hi nahi hai.
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Current pointer se puri linked list traverse karenge
        ListNode* curr = head;

        while (curr != NULL && curr->next != NULL) {

            // Agar current aur next node ki value same hai,
            // to duplicate node ko skip kar do.
            if (curr->val == curr->next->val) {
                curr->next = curr->next->next;
            }
            else {
                // Agar duplicate nahi mila,
                // to next node pe move kar jao.
                curr = curr->next;
            }
        }

        // Updated linked list return kar do.
        return head;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)