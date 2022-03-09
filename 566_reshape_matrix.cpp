#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if ((mat.size()*mat[0].size())!=(r*c)) {
            return mat;
        }
        int row=0 ,col=0;
        vector<vector<int>> ans(r, vector<int>(c,0));

        for (int i=0; i<mat.size(); i++) {
            for (int j=0; j<mat[0].size(); j++) {
                ans[row][col] = mat[i][j];
                col ++;
                if (col == c) {
                    row++;
                    col=0;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> mat {
        {1,2},
        {3,4}
    };

    /*
    for (int i=0; i<mat.size(); i++) {
        for (int j=0; j<mat[i].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    */

    vector<vector<int>> ans;
    Solution obj1;
    ans = obj1.matrixReshape(mat,1,4);

    for (int i=0; i<ans.size(); i++) {
        for (int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;;
    }

    
    return 0;
} 
