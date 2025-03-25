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
        vector<int> rightSideView(TreeNode* root) {
            vector<int> l;
            queue<TreeNode *> queue;
    
            if(!root) return l;
            queue.push(root);
            
            while(!queue.empty())
            {
                int n=queue.size();
                TreeNode *rightView = nullptr;
                while(n-- > 0)
                {
                    rightView = queue.front();
                    queue.pop();
                    if(rightView->left)queue.push(rightView->left);
                    if(rightView->right)queue.push(rightView->right);
                }
                l.push_back(rightView->val);
            }
            return l;
        }
    };