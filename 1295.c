/*
 *Find Numbers with Even Number of Digits
 *Given an array nums of integers, return how many of them contain an even number of digits. 

 Example 1:
 
 Input: nums = [12,345,2,6,7896]
 Output: 2
 Explanation: 
 12 contains 2 digits (even number of digits). 
 345 contains 3 digits (odd number of digits). 
 2 contains 1 digit (odd number of digits). 
 6 contains 1 digit (odd number of digits). 
 7896 contains 4 digits (even number of digits). 
 Therefore only 12 and 7896 contain an even number of digits.
 Example 2:
 
 Input: nums = [555,901,482,1771]
 Output: 1 
 Explanation: 
 Only 1771 contains an even number of digits.
*/
#include <stdio.h>

int findNumbers(int* nums, int numsSize) {
    // in int array, every element at least has 1 digit
    // iteration starts from 1
    int element=0, Output=0, iteration=1;
    
    for (int i=0 ; i < numsSize; i++) {
        element = nums[i];
        while ((element/10)>0) {
            element = element/10;
            iteration ++;
        }
        if (iteration % 2 == 0) {
            Output ++;
        }
        iteration = 1;
    }

    return Output;

}

int main() {
    int nums[] = {12,345,2,6,7896};
    int result = 0;

    result = findNumbers(nums, 5);
    printf("Output: %d\n",result);
    for (int i=0; i<5;i++) {
        printf("final nums[%d] = %d\n",i,nums[i]);
    }

    return 0;
}
