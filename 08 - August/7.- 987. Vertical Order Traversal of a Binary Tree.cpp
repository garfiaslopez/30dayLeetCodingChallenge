// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
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

/*
class Solution {
public:
    
    void foundMinMaxDistance(TreeNode* node, int &minD, int &maxD, int pos) {
        if (node == NULL) return;
        
        if (pos < minD) {
            minD = pos;
        } else if (pos > maxD) {
            maxD = pos;
        }
        
        foundMinMaxDistance(node->left, minD, maxD, pos - 1);
        foundMinMaxDistance(node->right, minD, maxD, pos + 1);
    }
    
    void getVerticalVals(TreeNode* node, vector<int> &verticalVals, int vertical, int pos) {
        if (node == NULL) return;
        
        if (pos == vertical) {
            verticalVals.push_back(node->val);
        }
        
        getVerticalVals(node->right, verticalVals, vertical, pos + 1);
        getVerticalVals(node->left, verticalVals, vertical, pos - 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int minD, maxD;
        foundMinMaxDistance(root, minD, maxD, 0);
        
        vector<vector<int>> response;
        for (int i=minD; i<=maxD; i++) {
            vector<int> verticalVals;
            getVerticalVals(root, verticalVals, i, 0);
            response.push_back(verticalVals);
        }
        
        return response;
    }
};

*/


class Solution {
    void dfs(TreeNode* node, int r, int c, unordered_map<int, vector<pair<int, int>>>& cache, int& minC, int& maxC){
        if(node == nullptr) return;
        if(cache.count(c)) cache[c].push_back({r, node->val});
        else cache.insert({c, {{r, node->val}}});
        minC = min(minC, c);
        maxC = max(maxC, c);
        dfs(node->left, r+1, c-1, cache, minC, maxC);
        dfs(node->right, r+1, c+1, cache, minC, maxC);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;
        
        unordered_map<int, vector<pair<int, int>>> cache;
        int minC = 0, maxC = 0;
        dfs(root, 0, 0, cache, minC, maxC);
        
        for(int c = minC; c < maxC+1; ++c){
            sort(cache[c].begin(), cache[c].end(), [](pair<int, int>& p1, pair<int, int>& p2){
                return (p1.first < p2.first) || ((p1.first == p2.first) && (p1.second < p2.second));
            });
            vector<int> col;
            for(pair<int, int>& p: cache[c])
                col.push_back(p.second);
            result.push_back(col);
        }
        return result;
    }
};

