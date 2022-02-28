/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

// brute method
/*
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for (int i=0;i<nums.size(); i++) {
            for (int j=i+1; j<nums.size(); j++) {
                if (nums[i] == nums[j]) return true;
            }            
        }
    return false;
    }
};
*/

// set method in c++ 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> my_set;
        for (int i=0; i<nums.size(); i++) {
            // The pair::second element in the pair is set to true if a new element was inserted or false if an equivalent element already existed.
            if (my_set.insert(nums[i]).second == false) return true;
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1,2,3,4,1};

    Solution obj1;
    cout << obj1.containsDuplicate(nums) << endl;
}
