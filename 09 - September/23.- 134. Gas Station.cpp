// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/gas-station/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int currentTank = 0; 
        int startIndex = 0;
        int n = gas.size();
        int costOfAllTrip = 0;
        
        for (int i=0; i<n; i++) {
            
            costOfAllTrip += gas[i] - cost[i];
            currentTank += gas[i] - cost[i];
            
            if (currentTank < 0) {
                startIndex = i+1;
                currentTank = 0;
            }
            
        }
        return costOfAllTrip < 0 ? -1 : startIndex;
    }
};


/*
class Solution {
public:
    
    bool canTravel(vector<int>& gas, vector<int>& cost, int startIndex) {
        int travelIndex = startIndex;
        int n = cost.size();
        
        int currentTank = gas[startIndex];
        int lastTravelCost = cost[startIndex];
        
        for (int i=1; i<n; i++) {
            int checkIndex = (startIndex + i) % n;
            if (currentTank - lastTravelCost <= 0) {
                return false;
            }
            currentTank += (gas[checkIndex] - lastTravelCost);
            lastTravelCost = cost[checkIndex];
        }

        return true;
    }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i = 0; i<cost.size(); i++) {
            if (canTravel(gas,cost,i)) {
                return i;
            }
        }
        return -1;
    }
};
*/