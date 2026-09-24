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
    ListNode* reverseList(ListNode* head) {

        // prev = jo part already reverse ho chuka hai
        ListNode* prev = NULL;

        // curr = jis node par abhi hum kaam kar rahe hain
        ListNode* curr = head;

        while (curr != NULL) {

            // Sabse pehle next node ko save kar lo
            // Kyuki curr->next ko change karne ke baad
            // humein aage wali list ka connection lose nahi karna
            ListNode* next = curr->next;

            // Current node ka arrow reverse kar do
            // Pehle: curr -> next
            // Ab:    curr -> prev
            curr->next = prev;

            // Ab current node reverse ho chuka hai
            // Isliye prev ko current par le aao
            prev = curr;

            // Ab next node par move karo
            curr = next;
        }

        // Jab curr == NULL ho gaya,
        // poori linked list reverse ho chuki hai
        // prev ab new head ko point kar raha hai
        return prev;
    }
};