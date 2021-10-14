
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
    ListNode* merge2Lists(ListNode* a, ListNode* b) {
        ListNode* head = new ListNode();
if(!a) return b;
if(!b) return a;
        auto pr = head;
        auto pa = a;
        auto pb = b;
        for( ; pa && pb; ) {
            if ( pa->val <= pb->val ) {
                pr->next = pa;
                pa = pa->next;
            }
            else {
                pr->next = pb;
                pb = pb->next;
            }
            pr = pr->next;
            pr->next = nullptr;
        }
        auto px = (pa) ? pa : pb;
        for( ; px; ) {
            pr->next = px;
            px = px->next;
            pr = pr->next;
            pr->next = nullptr;
        }
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res;
        std::size_t const count = lists.size();
        if ( count <= 2 ) {
            if ( 1 == count ) return lists[0];
            return merge2Lists(lists[0],lists[1]);
        }
        else if ( count > 2 ) {
            std::size_t const middle = count / 2;
            std::vector<ListNode*> listleft(lists.begin(), lists.begin() + middle);
            std::vector<ListNode*> listright(lists.begin() + middle, lists.end());
            ListNode* left = mergeKLists(listleft);
            ListNode* right = mergeKLists(listright);
            ListNode* res = merge2Lists(left,right);
            return res;
        }
        
    }
};

