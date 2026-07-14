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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Dummy node banaya taaki head handle karna easy ho jaye.
        ListNode* dummy = new ListNode(-1);

        // Tail hamesha merged list ke last node ko point karega.
        ListNode* tail = dummy;

        // Jab tak dono lists me elements bache hain.
        while (list1 != NULL && list2 != NULL) {

            // Agar list1 ka element chota hai.
            if (list1->val <= list2->val) {

                // Use merged list me add kar do.
                tail->next = list1;

                // list1 ko next node par le jao.
                list1 = list1->next;
            }
            else {

                // Warna list2 ka element add karo.
                tail->next = list2;

                // list2 ko next node par le jao.
                list2 = list2->next;
            }

            // Tail ko bhi ek step aage badha do.
            tail = tail->next;
        }

        // Agar list1 me abhi bhi nodes bache hain,
        // to unhe directly attach kar do.
        if (list1 != NULL) {
            tail->next = list1;
        }

        // Agar list2 me nodes bache hain,
        // to unhe directly attach kar do.
        if (list2 != NULL) {
            tail->next = list2;
        }

        // Dummy ke baad se actual merged list start hoti hai.
        return dummy->next;
    }
};