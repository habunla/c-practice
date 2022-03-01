#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// brute way
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sol(2);
        for (int i=0; i<nums.size(); i++) {
            for (int j=i+1; j<nums.size(); j++) {
                if ((nums[i]+nums[j]) == target) {
                    sol[0] =i;
                    sol[1] =j;
                }
                return sol;
            }
        };
        sol[0] =0;
        sol[1] =0;
        return sol;
    }
};
*/

// using hash table
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int value;
        unordered_map<int, int> umap;
        vector<int> sol;

        for (int i=0; i<nums.size(); i++) {
            value = target-nums[i];
            if (umap.find(value) == umap.end()) {
                umap.insert({nums[i], i});
            }
            else {
                sol.push_back(umap.find(value)->second);
                sol.push_back(i);
            }
        }
        return sol;
    }
};

int main() {
    vector<int> nums= {2,7,11,15};

    Solution obj1;
    for (int i: obj1.twoSum(nums, 9))
        cout << i << " ";
    cout << endl;

    return 0;
} 
