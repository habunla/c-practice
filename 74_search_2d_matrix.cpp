#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

// can't pass
/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[i].size(); j++) {
                if (target==matrix[i][j]) {
                    return true;
                }
                else if (target>matrix[i][j] and target<matrix[i][j+1]) {
                    return false;
                }
            }
        }
        return false;
    }
};
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0, j=matrix[0].size()-1;
        while (i<matrix.size() and j>=0) {
            if (target > matrix[i][j]) {
                i++;
            }
            else if (matrix[i][j] == target) {
                return true;
            }
            else {
                j--;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> input={
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };

    bool ans;
    Solution obj1;
    ans = obj1.searchMatrix(input, 20);
    cout << "ans= " << ans << endl;
    
    return 0;
} 
