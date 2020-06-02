// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;


/*
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

struct Cousin {
    int val;
    int parent;
    int depth;
};

class Solution {
public:
    
    void search(TreeNode* node, Cousin &x, Cousin &y, int depth, int parent ) {
        if (node == NULL) return;
        
        if (node->val == x.val) {
            x.parent = parent;
            x.depth = depth;
        }
        if (node->val == y.val) {
            y.parent = parent;
            y.depth = depth;
        }
        
        search(node->left, x, y, depth+1, node->val);
        search(node->right, x, y, depth+1, node->val);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        struct Cousin first;
        first.val = x;
        struct Cousin second;
        second.val = y;
        
        search(root, first, second, 0, -1);
        
        if (first.parent != second.parent && first.depth == second.depth) {
            return true;
        }
        return false;
    }
};