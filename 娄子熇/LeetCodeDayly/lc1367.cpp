#include<bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
    bool flag = false;
    bool dfs(ListNode* head, TreeNode* root) {
        if (head == nullptr) return true;
        if (root == nullptr) return false;
        if (root -> val == head -> val) return dfs(head -> next, root -> left) || dfs(head -> next, root -> right);
        return false;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr) return false;
        flag |= dfs(head, root);
        flag |= isSubPath(head, root -> left);
        flag |= isSubPath(head, root -> right);
        return flag;
    }
};