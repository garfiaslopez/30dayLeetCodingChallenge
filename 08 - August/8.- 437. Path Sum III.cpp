// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/path-sum-iii/
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
    
    void countPathsFromNode(TreeNode* node, int &paths, int currentSum, int targetSum) {
        
        if (node==NULL) return;
        
        int newSum = currentSum + node->val;
        if (newSum == targetSum) {
            paths += 1;
        }
        
        countPathsFromNode(node->left, paths, newSum, targetSum);
        countPathsFromNode(node->right, paths, newSum, targetSum);
    }
    
    void traverseTree(TreeNode* root, int &paths, int targetSum) {
        if (root == NULL) return;
        
        countPathsFromNode(root, paths, 0, targetSum);
        
        traverseTree(root->left, paths, targetSum);
        traverseTree(root->right, paths, targetSum);
    }
    
    int pathSum(TreeNode* root, int sum) {
        int allPaths = 0;
        traverseTree(root, allPaths, sum);
        return allPaths;
    }
};