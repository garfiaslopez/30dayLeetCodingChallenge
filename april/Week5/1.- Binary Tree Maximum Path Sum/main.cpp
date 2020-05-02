// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

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
    int findMaxPathSum(TreeNode* node, int &result) {
        if (node == NULL) return 0;
        
        int sumRight = findMaxPathSum(node->right, result);
        int sumLeft = findMaxPathSum(node->left, result);
        
        int inPathSum = max(max(sumRight + node->val, sumLeft + node->val), node->val);
        int inRootSum = max(inPathSum, sumRight + sumLeft + node->val);
        
        result = max(result, inRootSum);
        return inPathSum;
    }
    
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        findMaxPathSum(root, result);
        return result;
    }
};