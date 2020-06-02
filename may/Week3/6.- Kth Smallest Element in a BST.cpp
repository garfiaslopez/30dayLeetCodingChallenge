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
public:
    int kElement = 0;
    int found = 0;
    
    void inOrderTraversal(TreeNode* node, int k) {
        if (node == NULL) return; 

        inOrderTraversal(node->left,k); 
        
        kElement++;
        if (kElement == k) {
            found = node->val;
        }

        inOrderTraversal(node->right,k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        inOrderTraversal(root, k);
        return found;
    }
};