
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool
hasCycle(struct ListNode* head)
{
    struct ListNode* slow;
    struct ListNode* fast;
    for( slow=fast=head; slow && fast; ) {
        for( int x=0; x<2; x++ ) {
            if( fast->next ) {
                fast = fast->next;
                if( fast == slow ) {
                    // found loop
                    return 1;
                }
            }
        }
        if( slow->next ) {
            slow = slow->next;
        }
    }
    return 0;
}

