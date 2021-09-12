// 134. Gas Station

// There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

// Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique

#include "define.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        for (int i = 0; i < size; ) {
            if (gas[i] < cost[i]) {
                ++i;
                continue;
            }
            int j = 0, cur = i;
            int leftgas = 0;
            for (; j < size; ++j) {
                leftgas += gas[cur];
                if (leftgas < cost[cur]) {
                    if (cur <= i) {
                        return -1;
                    }
                    i = cur;
                    break;
                }
                leftgas -= cost[cur];
                cur = (++cur) % size;
            }
            if (j == size) {
                return i;
            }
        }
        return -1;
    }
};

int main(int argc, char** argv) {
    vector<int> gas{2,3,4}, cost{3,4,3};
    Solution s;
    cout << s.canCompleteCircuit(gas, cost) << endl;
    return 0;
}
