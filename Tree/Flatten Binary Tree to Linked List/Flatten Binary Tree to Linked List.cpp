/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* use;
    int cnt =0;
    void flatten(TreeNode* root) {
        //deep copy the root
        //assign the val;
        if(root == NULL) return;
        TreeNode* ans = new TreeNode(root->val);
        cnt++;
        ans->left = dc(root->left);
        ans->right = dc(root->right);
        cnt--;
        use = root;
        pre_order(ans);
    }
    TreeNode* dc(TreeNode* node)
    {
        if(node==NULL) return NULL;
        cnt++;
        TreeNode* newnode = new TreeNode(node->val);
        newnode->left = dc(node->left);
        newnode->right = dc(node->right);
        return newnode;
    }
    void pre_order(TreeNode* root)
    {
        if(root==NULL) return;
        cnt--;
        use->val = root->val;
        if(cnt>=0)
        {
            use->left = NULL;
            use->right = new TreeNode();
            use = use->right;
            pre_order(root->left);
            pre_order(root->right);
        }
        
    }
};
