// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/h-index/
//
// © Jose Garfias Lopez
//



// SORTING IN DESC
class Solution {
public:
    
    static bool comp (int a, int b) {
        return a>b;
    }
    
    int hIndex(vector<int>& citations) {
        
        vector<int> sorted(citations.begin(), citations.end());
        sort(sorted.begin(), sorted.end(), comp);
        
        int hIndex = 0;
        for (int i=1; i<=sorted.size(); i++) {
            //cout<<sorted[i-1]<<" - "<< i<<endl;
            if (sorted[i-1] == i) return i;
            if (!(sorted[i-1] >= i)) {
                break;
            }
            hIndex = i;
        }
        
        return hIndex;
    }
};


/*
// SORTING IN ASC
class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> sorted(citations.begin(), citations.end());
        sort(sorted.begin(), sorted.end());
        
        int hIndex = 0;
        for (int i=sorted.size(); i>=1; i--) {
            //cout<<sorted[i-1]<<" - "<< i<<endl;
            int invertedI = 1 + sorted.size() - i;
            if (!(sorted[i-1] >= invertedI)) {
                break;
            }
            hIndex = invertedI;
        }
        
        return hIndex;
    }
};
*/

/*

// BINARY IN DESC ORDER
class Solution {
public:
    
    static bool comp (int a, int b) {
        return a>b;
    }
    
    int hIndex(vector<int>& citations) {
        
        vector<int> sorted(citations.begin(), citations.end());
        sort(sorted.begin(), sorted.end(), comp);
 
        // binary search 
        int left = 0;
        int right = citations.size()-1;

        while(left<=right) {
            int mid = left + (right - left) / 2 ;
            int i = mid+1;
            
            if (citations[mid] == i) {
                return mid+1;
            } else if (citations[mid] > i) {
                left = mid + 1;
            } else if (citations[mid] < i) {
                right = mid - 1;
            }
        }

        return citations.size() - right;
    }
};
*/

