// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
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
    
    int binaryStringToInt(string stringNumber) {
        int n = stringNumber.length();
        int intNumber = 0;
        for (int i=0; i<n; i++) {
            if (stringNumber[i] == '1') {
                int exp = n - i - 1;
                intNumber += pow(2, exp);
            }
        }
        return intNumber;
    }
    
    int traverseAndSum(TreeNode* node, string number) {
        if (node == NULL) return 0;
        
        bool isLeaf = node->right == NULL && node->left == NULL;
        string actualNumber = number + to_string(node->val);
        if (isLeaf) {
            return binaryStringToInt(actualNumber);
        }
        
        int sumRight = traverseAndSum(node->right, actualNumber);
        int sumLeft = traverseAndSum(node->left, actualNumber);
        
        return sumRight + sumLeft;
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int sum = traverseAndSum(root, "");
        return sum;
    }
};