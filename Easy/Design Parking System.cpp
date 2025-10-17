#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/design-parking-system/
// Difficulty : Easy 

/* SIMULATION */
class ParkingSystem {
public:
    int parkSpace[3] = {0};

    ParkingSystem(int big, int medium, int small) {
        parkSpace[0] = big;
        parkSpace[1] = medium;
        parkSpace[2] = small;
    }
    
    bool addCar(int carType) {
        return parkSpace[carType-1] ? parkSpace[carType-1]-- : false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */