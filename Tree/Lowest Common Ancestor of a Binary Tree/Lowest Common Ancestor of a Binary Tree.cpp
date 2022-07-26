/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    bool sign_p = false,sign_q = false;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val == p->val || root->val == q->val) return root;
        pre(root->left,p,q);
        if(sign_p && sign_q) return ans;
        if(sign_p || sign_q) return root;
        pre(root->right,p,q);
        return ans;
    }
    void pre(TreeNode* node,TreeNode* p,TreeNode* q)
    {
        if(node == NULL) return;
        //cout << node->val << endl;
        pre(node->left,p,q);
        if(sign_p && sign_q) return;
        if(sign_p || sign_q)
        {
            pre(node->right,p,q);
            if(node->val == p->val) sign_p = true;
            if(node->val == q->val) sign_q = true;
            if(sign_p && sign_q)
            {
                ans = node;
                return;
            }
            return;
        }
        pre(node->right,p,q);
        if(sign_p && sign_q) return;
        if(node->val == p->val) sign_p = true;
        if(node->val == q->val) sign_q = true;
        if(sign_p && sign_q)    ans = node;
        return ;
    }
};
