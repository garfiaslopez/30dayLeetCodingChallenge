// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    TreeNode *getNewNode(int val) {
        TreeNode *newNode = new TreeNode;
        newNode->val = val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    
    int construct_BST(vector<int> &preorder, int n, int pos, TreeNode*curr, int left, int right) {
        if (pos == n || preorder[pos] < left || preorder[pos] > right) {
            return pos; // Edge bounds case
        }
        
        if (preorder[pos] < curr->val) { // insert in left subtree
            curr->left = getNewNode(preorder[pos]);
            pos += 1;
            pos = construct_BST(preorder,n,pos,curr->left,left,curr->val-1);
        }
        if (pos == n || preorder[pos] < left || preorder[pos] > right) return pos;
            
        curr->right = getNewNode(preorder[pos]);
        pos += 1;
        pos = construct_BST(preorder,n,pos,curr->right,curr->val+1,right);
        return pos;
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if (n==0) return NULL;
        
        TreeNode *root = getNewNode(preorder[0]);
        construct_BST(preorder,n,1,root,INT_MIN,INT_MAX);
        return root;
    }
};