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
    bool isPalindrome(ListNode* head) {
        vector<int> nums;
        ListNode* iter = head;
        while(iter) {
            nums.push_back(iter->val);
            iter = iter->next;
        }
        int n = nums.size();
        for(int i = 0;i < n/2;i++)
            if(nums[i] != nums[n-i-1])
                return false;
        return true;
    }
};