#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// brute way
/*
class Solution {
public:
    vector<int> output;
    void search(vector<int>& lgnums, vector<int>& stnums) {
            for (int i=0; i<stnums.size(); i++) {
                for (int j=0; j<lgnums.size(); j++) {
                    if (stnums[i] == lgnums[j]) {
                        output.push_back(stnums[i]);
                        lgnums.erase(lgnums.begin()+j);
                        break;
                    }
                }
            }
    }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size()>=nums2.size()) {
            search(nums1,nums2);
        }
        else {
            search(nums2,nums1);
        }
        return output;
    }
};
*/

// using unorder map
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i=0; i<nums1.size(); i++) {
            mp[nums1[i]]++;
        }
        /*
        unordered_map<int, int>:: iterator p;
        for (p=mp.begin(); p!=mp.end(); p++) {
            cout << "(" << p->first << "," << p->second << ")\n";
        } 
        */
        for (int i=0; i<nums2.size(); i++) {
            if (mp[nums2[i]] != 0) {
                mp[nums2[i]]--;
                ans.push_back(nums2[i]);
            }
        }
        return ans;
    }
};

int main() {
    /*
    vector<int> nums1= {1,2,2,1};
    vector<int> nums2= {2,2};
    vector<int> output;
    */
    
    vector<int> nums1= {4,9,5};
    vector<int> nums2= {9,4,9,8,4};
    vector<int> output;
    
    Solution obj1;
    output = obj1.intersect(nums1, nums2);

    for (int i: output)
        cout << i << ' ';
    cout << endl;

    return 0;
} 
