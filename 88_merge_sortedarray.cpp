#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

// unaccepted answer
/*
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        int i=0;
        int j=0;
        for (; i<m; ) {
            if ((nums1[i] <= nums2[j]) || (j==n)) {
                temp.push_back(nums1[i]);
                i+=1;
            }
            else {
                temp.push_back(nums2[j]);
                j+=1;
            }
        }

        for (;j<n; j++) {
            temp.push_back(nums2[j]);
        }

        nums1 = temp;
    }
};
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int target=m+n-1;

        while(j>=0 && i>=0) {
            if (nums2[j]>=nums1[i]) {
                nums1[target] = nums2[j];
                j--;
                target--;
            }
            else {
                nums1[target] = nums1[i];
                i--;
                target--;
            }
        }

        for ( ;j>=0; j--) {
            nums1[j] = nums2[j];
        }

    }
};

int main() {
    vector<int> nums1= {1,2,3,0,0,0};
    int m =3;
    vector<int> nums2= {2,5,6};
    int n =3;
    
    /*
    vector<int> nums1= {1};
    int m =1;
    vector<int> nums2= {3};
    int n =0;
    */
    
    /*
    vector<int> nums1= {0};
    int m=0;
    vector<int> nums2= {1};
    int n=1;
    */

    Solution obj1;
    obj1.merge(nums1, m, nums2, n);

    for (int i: nums1)
        cout << i << ' ';
    cout << endl;

    return 0;
} 
