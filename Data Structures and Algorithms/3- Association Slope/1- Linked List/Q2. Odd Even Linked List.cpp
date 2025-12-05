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
    ListNode* oddEvenList(ListNode* head) {
        if (!head)return NULL;
        vector<int>odd, even;
        int curPos = 0;
        while (head) {
            if (curPos++ & 1 ^ 1)odd.push_back(head->val);
            else even.push_back(head->val);
            head = head->next;
        }
        ListNode* use = new ListNode();
        ListNode* ans = use;
        for (int i = 0; i < odd.size(); i++) {
            use->val = odd[i];
            if (even.size())use->next = new ListNode();
            use = use->next;
        }
        for (int i = 0; i < even.size(); i++) {
            use->val = even[i];
            if (i + 1 < even.size())use->next = new ListNode();
            use = use->next;
        }
        return ans;
    }
};