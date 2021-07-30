/*
 * problem:
 Given a fixed length array arr of integers, duplicate each occurrence of zero, 
 shifting the remaining elements to the right.
 Note that elements beyond the length of the original array are not written.
 Do the above modifications to the input array in place, do not return anything from your function.
 Example 1:
 Input: [1,0,2,3,0,4,5,0]
 Output: null
 Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
*/
#include <stdio.h>

void duplicateZeros(int* arr, int arrSize) {
    int tempArray[arrSize];
    int index = 0;
    
    // duplicate array
    for (int i=0; i<arrSize; i++) {
        tempArray[i] = arr[i];
    }

    for (int i=0; i<arrSize; i++) {
        if (tempArray[i]==0) {
            index ++;
            
            // if else statement shorcut. only need true part
            ((i+index)<arrSize) && (arr[i+index] = 0);
            
            for (int j=index+1; (j+i)<arrSize; j++) {
                arr[i+j] = tempArray[j+i-index];
            }
        }
    }
}

int main() {
    int Input[] = {1,0,2,3,0,4,5,0};
    // int Input[] = {1,2,3};
    // int Input[] = {1,0,0,0,0,4,5,0};
    size_t input_len = sizeof(Input)/sizeof(Input[0]);

    duplicateZeros(Input, input_len);
    
    for (int i=0; i<input_len; i++) {
        printf("element in input array %d = %d\n", i, Input[i]);
    }
    
    return 0;
}
