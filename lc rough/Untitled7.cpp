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
    bool isBST(TreeNode* root, int minV = INT_MIN, int maxV = INT_MAX){
        static bool mn = false;
        static bool mx = false;
        
        if(root==NULL){
            return true;
        }
        
        if(root->val == INT_MIN){
            if(root->left != NULL){
                return false;
            }
            if(root->right != NULL){
                if(root->right->val == INT_MIN){
                    return false;
                }
            }
            
        }
        if(root->val == INT_MAX){
            if(root->right != NULL){
                return false;
            }
            if(root->left != NULL){
                if(root->left->val == INT_MAX){
                    return false;
                }
            }
            
        }
        
        
        if(root->val >= minV && root->val <= maxV && isBST(root->left, minV, root->val) && isBST(root->right,                root->val, maxV)){
            
            if(root->val == INT_MIN &&  minV == INT_MIN && maxV == INT_MAX && !mn){
                mn = true;
                return true;
            }
            
            if(root->val == INT_MAX && maxV == INT_MAX &&  minV == INT_MIN && !mx){
                mx = true;
                return true;
            }
            
            if(root->val == INT_MIN && minV == INT_MIN && !mn){
                mn = true;
                return true;
            }
                   
            
            if(root->val == INT_MAX && maxV == INT_MAX && !mx){
                mx = true;
                return true;
            }
            
            if(root->val > minV && root->val < maxV){
                return true;		    
            }
        }
        
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return isBST(root);
    }
}; 

//	2147483647
