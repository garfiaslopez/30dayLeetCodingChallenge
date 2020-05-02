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

    bool pathExists(TreeNode *node, vector<int> &arr, int position) {
        if (node == NULL) return false;
        
        bool isLeftValid = pathExists(node->left, arr, position + 1);
        bool isRightValid = pathExists(node->right, arr, position + 1);

        bool positionInArray = position <= arr.size() - 1;
        bool isLeaf = node->left == NULL && node->right == NULL;
        bool isSameValue = positionInArray && arr[position] == node->val;
       
        if (isLeaf && position == arr.size() - 1 && isSameValue) return true;
        if (!positionInArray) return false;
        if (!isSameValue) return false;
       
        return isLeftValid || isRightValid;
    }

    bool isValidSequence(TreeNode *root, vector<int> &arr) {
        if (arr.size() == 0) return false;
        if (arr[0] != root->val) return false;

        return pathExists(root, arr, 0);
    }
};