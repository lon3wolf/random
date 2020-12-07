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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        std::stack<TreeNode*> stk;
        vector<int> v;
        TreeNode* cur = root;
        while(cur != NULL || !stk.empty())
        {
            while (cur != NULL)
            {
                stk.push(cur);
                cur = cur->left;
            }
            
            cur = stk.top();
            stk.pop();

            v.push_back(cur->val);
            cur = cur->right;
        }
        
        return v;
    }
};