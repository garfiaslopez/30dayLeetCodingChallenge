// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/robot-bounded-in-circle/
//
// © Jose Garfias Lopez
//

/*
    0 - north
    1 - left
    2 - south
    3 - rigth

*/

class Robot {
    int posX = 0;
    int posY = 0;
    int dir = 0;

public:
    Robot() {
        
    }
    void goFront() {
        switch(dir) {
            case 0:
                posY++;
            break;
            case 1:
                posX--;
            break;
            case 2:
                posY--;
            break;
            case 3:
                posX++;
            break;
        }
    }
    void goLeft() {
        switch(dir) {
            case 0:
                dir = 1;
            break;
            case 1:
                dir = 2;
            break;
            case 2:
                dir = 3;
            break;
            case 3:
                dir = 0;
            break;
        }
    }
    void goRight() {
        switch(dir) {
            case 0:
                dir = 3;
            break;
            case 1:
                dir = 0;
            break;
            case 2:
                dir = 1;
            break;
            case 3:
                dir = 2;
            break;
        }
    }
    
    bool isInOrigin() {
        return dir == 0 && posX == 0 && posY == 0;
    }
    
    void run(string commands) {
        for (char c : commands) {
            switch(c) {
                case 'G':
                    goFront();
                break;
                case 'L':
                    goLeft();
                break;
                case 'R':
                    goRight();
                break;
            }
            //debug();
        }
    }
    
    void debug() {
        cout<<posX<<","<<posY<<" - "<<dir<<endl;
    }
};

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int bounded = false;
        int iterations = 4;
        
        Robot* r = new Robot();
        while(iterations--) {
            r->run(instructions);
            //cout<<"----------NEXT ITERATION_________"<<endl;
            if (r->isInOrigin()) {
                bounded = true;
                break;
            }
        }
        
        return bounded;
    }
};