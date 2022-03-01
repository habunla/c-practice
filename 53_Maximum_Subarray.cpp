#include <stdlib.h>
#include <iostream>
#include <vector>
#include<climits>

using namespace std;

// kadane's algo
/*
class Solution {
public:
    int findmax(vector<int>& nums) {
        int temp;
        temp = nums[0];
        for (int i=1; i<nums.size(); i++) {
            if (temp < nums[i]) {
                temp = nums[i];
            }
        }
        return temp;        
    }
    
    int maxSubArray(vector<int>& nums) {
        int max_so_far = INT_MIN;
        int max_ending_here = 0;

        for (int i=0; i<nums.size(); i++) {
            max_ending_here += nums[i];
            if (max_ending_here < 0) {
                max_ending_here = 0;
            }
            if (max_so_far < max_ending_here) {
                max_so_far = max_ending_here;
            }
            if (max_so_far == 0) {
                max_so_far = findmax(nums);
            }
        }
        return max_so_far;
    }
};
*/

// kumar algo
class Solution {
 public:
     int maxSubArray(vector<int>& nums) {
         int max_current = nums[0];
         int max_so_far = nums[0];

         for (int i=1; i<nums.size(); i++) {
            max_current = max(nums[i], max_current+nums[i]);
            max_so_far = max(max_current, max_so_far);
         }
         return max_so_far;
     }
 };

int main() {
    // vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums = {5,4,-1,7,8};
    // vector<int> nums = {1};
    // vector<int> nums = {-6, -3, -8, -1, 0, 0};
    
    Solution obj1;
    cout << obj1.maxSubArray(nums) << endl;

    return 0;
}
