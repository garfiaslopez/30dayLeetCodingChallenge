// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/sum-root-to-leaf-numbers/
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
    
    void find(TreeNode* node, string path, int &sum) {
        if (node == NULL) return;
        
        find(node->left, path + to_string(node->val), sum);
        find(node->right, path + to_string(node->val), sum);
        
        bool isLeaf = node->left == NULL && node->right == NULL;
        
        if (isLeaf) {
            sum += stoi(path+to_string(node->val));
        }
        return;
    }
    
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        find(root, "", sum);
        return sum;
    }
};