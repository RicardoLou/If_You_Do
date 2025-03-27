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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* aa = new ListNode();
        ListNode* next = aa;
        while (head->next != nullptr) {
            while (head->val == 0) {
                head = head->next;
            }
            next->val += head->val;
            head = head->next;
            if (head->val == 0 && head->next != nullptr) {
                next->next = new ListNode();
                next = next->next;
            }
        }

        return aa;

    }
};