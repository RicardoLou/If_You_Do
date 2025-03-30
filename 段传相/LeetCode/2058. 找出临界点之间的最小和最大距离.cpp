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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minD = -1, maxD = -1, len = 0, n = -1, f = 0;
        while (head->next->next != 0) {
            int a = head->val, b = head->next->val, c = head->next->next->val;
            len++;
            if (b > a && b > c || b < a && b < c) {
                if (f == 0) {
                    f = len;
                }
                if (minD == -1 && n > 0 || minD > len - n) {
                    minD = len - n;
                }
                n = len;
            }
            if (minD != -1) {
                maxD = n - f;
            }
            head = head->next;
        }

        return { minD,maxD };
    }
};