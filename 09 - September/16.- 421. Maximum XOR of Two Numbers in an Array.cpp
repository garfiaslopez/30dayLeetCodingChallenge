// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
//
// © Jose Garfias Lopez
//

/*  Quadratic solution 

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxRes = 0;
        int n = nums.size();
        for (int i=0; i<n; i++) {
           for(int j=i+1; j<n; j++) {
              int a = nums[i];
              int b = nums[j];
              
              maxRes = max(maxRes, a^b);
           }
        }
        
        return maxRes;
        
    }
};

*/

class trienode{
public:
trienode* left;
trienode* right;
};

class Solution {
public:
trienode* insert(int n,trienode* head)
{
    trienode* curr=head;
    
    for(int i=31;i>=0;i--)
    {
        int bit=(n>>i)&1;
        
        if(bit==0)
        {
            if(!curr->left)
            {
                curr->left=new trienode();
            }
            curr=curr->left;
        }
        else
        {
            if(!curr->right)
            {
                curr->right=new trienode();
            }
            curr=curr->right;
        }
        
    }
    
    return head;
}

int maxxor(trienode* head,vector<int> nums)
{
    int maxans=INT_MIN;
    
    for(int i=0;i<nums.size();i++)
    {
        trienode* curr=head;
        int value=nums[i];
        int currxor=0;
        
        for(int j=31;j>=0;j--)
        {
            int bit=(value>>j)&1;
            
            if(bit==0)
            {
                if(curr->right)
                {
                    currxor+=pow(2,j);
                    curr=curr->right;
                }
                else
                {
                    curr=curr->left;
                }
            }
            
            else
            {
                if(curr->left)
                {
                    currxor+=pow(2,j);
                    curr=curr->left;
                }
                else
                {
                    curr=curr->right;
                }
            }
            
            
        }
        
        maxans=max(maxans,currxor);
        
    }
    
    return maxans;
    
}

int findMaximumXOR(vector<int>& nums) {
    
    trienode* head=new trienode();
    
    for(int i=0;i<nums.size();i++)
    {
        head=insert(nums[i],head);
    }
    
    return maxxor(head,nums);
    
}

};