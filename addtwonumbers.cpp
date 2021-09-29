
// Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/

// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

/* example
    Input: l1 = [2,4,3], l2 = [5,6,4]
        (2) -> (4) -> (3)
        (5) -> (6) -> (4)
    Output: [7,0,8]
        (7) -> (8) -> (8)
    Explanation: 342 + 465 = 807
*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* phead = new ListNode(0); // dummy head, will discard
        int v1, v2, value, carry = 0;
        ListNode* pnode = phead;
        for( auto p1 = l1, p2 = l2; p1 || p2; ) {
            // extract value from each list node(s)
            v1 = (p1) ? p1->val : 0;
            v2 = (p2) ? p2->val : 0;
            // sum of digits, plus prior carry
            value = v1 + v2 + carry;
            // calculate carry out
            carry = value / 10;
            // new node for current digit, append to list
            pnode->next = new ListNode(value % 10);
            pnode = pnode->next;
            // index list pointers to list next node(s)/digit(s)
            if( p1 ) { p1 = p1->next; }
            if( p2 ) { p2 = p2->next; }
        }
        if( carry > 0 ) {
            pnode->next = new ListNode(carry);
        }
        pnode = phead->next; // step past dummy head
        delete phead; // delete dummy head
        return pnode;
    }
};

