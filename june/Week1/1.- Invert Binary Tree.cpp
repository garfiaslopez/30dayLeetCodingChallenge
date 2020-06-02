// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    
    void swapNodes(TreeNode* node) {
        if (node == NULL) return;
        
        swapNodes(node->left);
        swapNodes(node->right);
        
        TreeNode* tmpR = node->right;
        TreeNode* tmpL = node->left;
        
        node->right = tmpL;
        node->left = tmpR;
    }
    
public:
    TreeNode* invertTree(TreeNode* root) {
        swapNodes(root);
        return root;
    }
};