#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //这里用或者是因为有一个为空的话，后面的return就无法进行下去了
        if(p == nullptr || q == nullptr)
            return p == q;
        return p -> val == q -> val && isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr)
            return false;
        return isSameTree(root, subRoot) || isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
    }
};