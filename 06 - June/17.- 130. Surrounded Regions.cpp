// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/surrounded-regions/
//
// © Jose Garfias Lopez
//


class Solution {
public:
    
    vector<int> fil = {-1, 0, 1, 0 };
    vector<int> col = { 0, 1, 0, -1};
    
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return;
        int maxFil = board.size();
        int maxCol = board[0].size();
        
        for (int i=0; i<maxFil; i++) {
            for (int j=0; j<maxCol; j++) {
                if (board[i][j] == 'O') {
                    //cout<<"found at: "<<i<<","<<j<<endl;
                    // start DFS
                    set<pair<int,int>> region;
                    stack<pair<int,int>> toVisit;
                    bool touchedBorder = false;
                    
                    region.insert(make_pair(i,j));
                    toVisit.push(make_pair(i,j));
                    
                    while(!toVisit.empty()) {
                        pair<int,int> pos = toVisit.top();
                        toVisit.pop();
                        
                        bool inBorder = (pos.first==0||pos.first==maxFil-1) || 
                                        (pos.second==0||pos.second==maxCol-1);
                        
                        if (inBorder) { 
                            touchedBorder = true; 
                        }
                        
                        for (int m=0; m<4; m++) {
                            int f = pos.first + fil[m];   // newPosition
                            int c = pos.second + col[m];
                            
                            //cout<<"search in: "<<f<<","<<c<<endl;

                            bool prevSeen = region.find(make_pair(f,c)) != region.end();
                            bool isValidPos = (((f>=0) && (f<maxFil)) && ((c>=0) && (c<maxCol)));
                            
                            //cout<<"prevSeen: "<<prevSeen<<", isValidPos"<<isValidPos<<endl;
                            if (isValidPos && !prevSeen && board[f][c] == 'O') {
                                //cout<<"insert new: "<<f<<","<<c<<endl;
                                region.insert(make_pair(f,c));
                                toVisit.push(make_pair(f,c));
                            }
                            
                        }
                    }
                    
                    if (!touchedBorder) {
                        //cout<<"no touched border"<<endl;
                        for (auto pos: region) {
                            //cout<<pos.first<<","<<pos.second<<endl;
                            board[pos.first][pos.second] = 'X';
                        }
                    } else {
                        //cout<<"touched border"<<endl;
                        for (auto pos: region) {
                            //cout<<pos.first<<","<<pos.second<<endl;
                            board[pos.first][pos.second] = 'I';
                        }
                        
                    }
                    
                }
            }
        }
        
        for (int i=0; i<maxFil; i++) {
            for (int j=0; j<maxCol; j++) {
                if (board[i][j] == 'I') { 
                    board[i][j] = 'O';
                }
            }
        }
        
    }
};

