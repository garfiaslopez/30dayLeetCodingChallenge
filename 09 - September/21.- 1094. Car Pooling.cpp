// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/car-pooling/
//
// © Jose Garfias Lopez
//

struct event {
    int type; // 0 dropoff, 1 pickup
    int people;
    int position;
};

class Solution {
public:
    
    static bool comp(event a, event b) {
        if (a.position == b.position) {
            return a.type < b.type;
        }
        return a.position < b.position;
    }
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int currentCapacity = 0;
        vector<event> events;
        
        // change data received
        for (vector<int> trip: trips) {
            event pickup;
            event dropoff;
            
            pickup.type = 1;
            pickup.people = trip[0];
            pickup.position = trip[1];
            
            dropoff.type = 0;
            dropoff.people = trip[0];
            dropoff.position = trip[2];
            
            events.push_back(pickup);
            events.push_back(dropoff);
        }
        
        sort(events.begin(), events.end(), comp);
        
        for (event e: events) {
            //cout<<"event: "<< e.type<<" - pos:"<<e.position<< " peo:"<< e.people<<endl;
            if (e.type == 1) { // pickup
                currentCapacity += e.people;
            } else {
                currentCapacity -= e.people;
            }
            
            if (currentCapacity > capacity) {
                return false;
            }
        }
        
        return true;
    }
};
