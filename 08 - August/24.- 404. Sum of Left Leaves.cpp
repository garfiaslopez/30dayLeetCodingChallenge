// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/sum-of-left-leaves/
//
// © Jose Garfias Lopez
//

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
    
    int sumLeft(TreeNode* node, bool isLeft) {
        
        if (node == NULL) return 0;
        
        int leftSum = sumLeft(node->left, true);
        int rightSum = sumLeft(node->right, false);
        bool isLeaf = node->left == NULL && node->right == NULL;
        
        if (isLeft && isLeaf) {
            return leftSum + rightSum + node->val;
        }
        return leftSum + rightSum;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return sumLeft(root, false);
    }
};