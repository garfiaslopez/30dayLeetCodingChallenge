// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/island-perimeter/
//
// © Jose Garfias Lopez
//


class Solution {
public:
    vector<int> fil = {-1, 0, 1, 0};
    vector<int> col = { 0, 1, 0,-1};
    
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.size() <= 0) return 0;
        
        int perimeter = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) { // cell is land
                    for (int p=0; p<4; p++) {
                        
                        int newFil = i + fil[p];
                        int newCol = j + col[p];
                        bool insideBounds = (newFil >= 0 && newFil < m) && (newCol >= 0 && newCol < n);
                                                
                        if (!insideBounds || (insideBounds && (grid[newFil][newCol] == 0))) {
                            perimeter++;
                        }
                    }                    
                }
            }
        }
        
        return perimeter;
    }
};