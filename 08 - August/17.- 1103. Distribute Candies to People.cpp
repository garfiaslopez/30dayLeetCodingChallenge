// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/distribute-candies-to-people/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int actualCandies = candies;
        int giveCandies = 0;
        vector<int> distribution(num_people, 0);
                
        while(actualCandies > 0) {
            
            for (int i=0; i<num_people; i++) {
                giveCandies++;
                
                if (actualCandies > 0) {
                    
                    if (giveCandies > actualCandies) {
                        distribution[i] += actualCandies;
                    } else {
                        distribution[i] += giveCandies;
                    }
                    actualCandies -= giveCandies;
                    
                } else {
                    break;
                }
            }
            
        }
        
        return distribution;
    }
};