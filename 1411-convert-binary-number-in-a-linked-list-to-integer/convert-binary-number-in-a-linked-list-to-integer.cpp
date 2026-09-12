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
    int getDecimalValue(ListNode* head) {
        
        int ans = 0;

        while (head != nullptr) {
            
            // Abhi tak jo binary number bana hai,
            // usko 1 bit left shift karne ke liye ×2
            ans = ans * 2;

            // Current node ki value (0 ya 1) add kar do
            ans = ans + head->val;

            // Next node par move karo
            head = head->next;
        }

        return ans;
    }
};