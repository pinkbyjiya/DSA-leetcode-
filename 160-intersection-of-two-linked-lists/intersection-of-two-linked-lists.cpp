/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    // Ye function linked list ki length return karega
    int getLength(ListNode* head)
    {
        ListNode* temp = head;   // Traversal ke liye temp pointer
        int count = 0;

        // Jab tak valid node hai tab tak traverse karo
        while(temp != NULL)
        {
            count++;              // Current node count karo
            temp = temp->next;    // Next node pe jao
        }

        return count;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // Dono linked lists ki length nikal lo
        int lenA = getLength(headA);
        int lenB = getLength(headB);

        // Traversal ke liye temporary pointers
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        // Length ka difference nikal lo
        int diff = abs(lenA - lenB);

        // Agar A badi hai to A ko diff steps aage le jao
        if(lenA > lenB)
        {
            for(int i = 0; i < diff; i++)
            {
                tempA = tempA->next;
            }
        }

        // Agar B badi hai to B ko diff steps aage le jao
        else
        {
            for(int i = 0; i < diff; i++)
            {
                tempB = tempB->next;
            }
        }

        // Ab dono pointers ko ek saath move karo
        while(tempA != tempB)
        {
            tempA = tempA->next;
            tempB = tempB->next;
        }

        // Agar intersection hoga to wahi node return hogi,
        // warna dono NULL ho jayenge aur NULL return hoga.
        return tempA;
    }
};