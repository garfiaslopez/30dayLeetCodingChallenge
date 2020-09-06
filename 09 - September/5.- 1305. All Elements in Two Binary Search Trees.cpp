// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
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
    
    void inOrder(TreeNode* node, vector<int> &answer) {
        if (node == NULL) return;
        
        inOrder(node->left, answer);
        answer.push_back(node->val);
        inOrder(node->right, answer);
    }
    
    void mergeSortedArrs(vector<int> &first, vector<int> &second, vector<int> &answer) {
        int firstPointer = 0;
        int secondPointer = 0;
        
        while (firstPointer < first.size() || secondPointer < second.size()) {
            
            if (firstPointer < first.size() && secondPointer < second.size()) { // two pointers are valid
                
                if (first[firstPointer] < second[secondPointer]) {
                    answer.push_back(first[firstPointer]);
                    firstPointer++;
                } else if (first[firstPointer] > second[secondPointer]) {
                    answer.push_back(second[secondPointer]);
                    secondPointer++;
                } else {
                    answer.push_back(first[firstPointer]);
                    firstPointer++;
                    answer.push_back(second[secondPointer]);
                    secondPointer++;
                }
                
            } else if (firstPointer < first.size() && secondPointer >= second.size()) { // first is valid, second is invalid
                answer.push_back(first[firstPointer]);
                firstPointer++;
            } else if (firstPointer >= first.size() && secondPointer < second.size()) { // second is valid, first is invalid
                answer.push_back(second[secondPointer]);
                secondPointer++;
            }

        }
        
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> firstArr;
        vector<int> secondArr;
        
        inOrder(root1, firstArr);
        inOrder(root2, secondArr);
        
        int mergeSize = firstArr.size() + secondArr.size();
        vector<int> answer(mergeSize);
        // manually implement merge
        // mergeSortedArrs(firstArr, secondArr, answer);
        
        // STL MERGE 
        merge(firstArr.begin(), firstArr.end(), secondArr.begin(), secondArr.end(), answer.begin());
        
        return answer;
    }
};