// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int maximum = -1000;
public:
    
    int h(TreeNode* root) {
        if (root == NULL) return 0;
        
        int hRight = h(root->right);
        int hLeft  = h(root->left);
        
        int diameter = hRight + hLeft + 1;
        if (diameter > maximum) {
            maximum = diameter;
        }
        
        return max(hRight, hLeft) + 1; // incrementing to count height
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int heightOfTree = h(root);
        if (heightOfTree > 0) {
            return maximum -1; // minus one for the edges.
        }
        return 0;
    }
};