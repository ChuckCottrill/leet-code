
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

class Solution {
public:
    bool
    hasCycle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        for( ; fast && fast->next; ) {
            slow = slow->next;
            fast = fast->next->next;
            if( fast == slow ) {
                return true;
            }
        }
        return 0;
    }
};

