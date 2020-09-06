// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
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
    
    void levelOrder(TreeNode* root, vector<vector<int>> & response) {
        if (root == NULL) return;
        
        queue<pair<TreeNode*, int>> toVisit; // (NODE,HEIGHT)
        toVisit.push(make_pair(root, 0));
        
        while(!toVisit.empty()) {
            pair<TreeNode*,int> node = toVisit.front();
            toVisit.pop();
            
            if (node.first != NULL) {
                if (node.second < response.size()) {
                    // push in existing level
                    response[node.second].push_back(node.first->val);
                } else {
                    // create new level
                    response.push_back({node.first->val});
                }
                
                toVisit.push(make_pair(node.first->left, node.second + 1));
                toVisit.push(make_pair(node.first->right, node.second + 1));
            }
        }
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> treeArray;
        
        levelOrder(root, treeArray);
        reverse(treeArray.begin(), treeArray.end());
        return treeArray;
    }
};
