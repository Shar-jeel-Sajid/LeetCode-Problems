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
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        if (list2->val < list1->val)
            return mergeTwoLists(list2, list1);
        ListNode* iter = list1;
        while (iter->next && iter->next->val <= list2->val)
            iter = iter->next;
        if (iter->next) {
            ListNode* tmp = iter->next;
            iter->next = list2;
            return mergeTwoLists(list1, tmp);
        }
        iter->next = list2;
        return list1;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode tmp(0, head);
        ListNode* slow = &tmp;
        ListNode* fast = head;
        while (true) {
            if (fast->next == NULL)
                return (slow);
            if (fast->next->next == NULL)
                return (slow->next);
            fast = fast->next->next;
            slow = slow->next;
        }
        return head;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *mid = middleNode(head), *tmp = mid->next;
        mid->next = NULL;
        head = sortList(head);
        tmp = sortList(tmp);
        head = mergeTwoLists(head, tmp);
        return head;
    }
};