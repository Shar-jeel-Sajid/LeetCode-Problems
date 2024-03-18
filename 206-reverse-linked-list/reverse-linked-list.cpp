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
    ListNode* reverseList(ListNode* head, bool isHead = true) {
        if(!head || !head->next)
            return head;
        ListNode* tmp = reverseList(head->next,false);
        head->next->next = head;
        if(isHead)
            head->next = NULL;
        return tmp;
    }
};