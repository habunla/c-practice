/*
 * Given a binary array nums, return the maximum number of consecutive 1's in the array
 * Example 1:
 * Input: nums = [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
 * Example 2:
 * Input: nums = [1,0,1,1,0,1]
 * Output: 2
*/
#include <stdio.h>

int findMaxConsecutiveOnes(int* nums, int numsSize){
    int Output=0, consec=0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            consec ++;
            if (Output < consec) {
                Output = consec;
            }
        }
        else {
            consec = 0;
        }
    }
    
    return Output;
}

int main() {
    int nums[] = {1,1,0,0,0,1};
    int Output = 0;
    
    Output = findMaxConsecutiveOnes(nums, 6);
    printf("Output = %d\n",Output);

    return 0;
}
