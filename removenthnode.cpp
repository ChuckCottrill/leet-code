

// leetcode
// Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
Follow up: Could you do this in one pass?
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
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    // std::cout << "this:" << this->val << std::endl;
    int Val() { return this->val; }
    ListNode* Next(ListNode* p) { return(p->next); }
    void ListPrint() {
        ListNode* p = this;
        // std::cout << "this:" << this << std::endl;
        // std::cout << "this->val:" << this->val << std::endl;
        std::cout << "[p:" << p->val; // << ",->" << p->next;
if( p ) p = p->next;
        // for( ; p != nullptr; ) {
        for( ; p; ) {
            std::cout << ",p:" << p->val;
            p = p->next;
        }
        std::cout << "]" << p->val;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* tailp = head; // pointer to node to remove
        ListNode* leadp = head; // last node
        ListNode* found = NULL;

        if( !head ) { return head; }
        if( n < 1 ) { return head; }

        // advance leadp (n) nodes ahead along linked list
        for( int idx = 1; idx < n; ++idx ) {
            if( NULL == leadp->next ) {
                found = head;
                break;
            }
            leadp = leadp->next;
        }

// HERE

        for( ; leadp->next != NULL; ) {
            // find last node
            if( NULL == leadp->next ) {
                // remove node found = tailp->next
                found = tailp->next;
                break;
            }
            // move leadp, tailp in lockstep
            leadp = leadp->next;
            tailp = tailp->next;
        }
        if( NULL != found ) {
            // remove found->next node
            tailp->next = found->next;
        }

        return head;
    }
};

int
main() {
    Solution sol;
    // ListNode* list = new ListNode(1);
    ListNode* list = new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5)))));
std::cout << "list:" << list->Val() << std::endl;
// list->ListPrint();
    ListNode* p = list;
/*
std::cout << "p:" << p->Val() << std::endl;
    p->next = new ListNode(2); p = p->next;
std::cout << "p:" << p->Val() << std::endl;
list->ListPrint();
    p->next = new ListNode(3); p = p->next;
std::cout << "p:" << p->Val() << std::endl;
list->ListPrint();
    p->next = new ListNode(4); p = p->next;
std::cout << "p:" << p->Val() << std::endl;
list->ListPrint();
    p->next = new ListNode(5);
std::cout << "p:" << p->Val() << std::endl;
*/

    list->ListPrint();
    ListNode* mod = sol.removeNthFromEnd(list, 2);
    mod->ListPrint();
}

