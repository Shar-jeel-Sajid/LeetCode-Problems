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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* back = list1,*front;
        for(int i = 0;i < a - 1;i++)
            back = back->next;
        front = back;
        for(int i = 0;i < 2 + b - a;i++)
            front = front->next;
        back->next = list2;
        while(back->next)
            back = back->next;
        back->next = front;
        return list1;
    }
};