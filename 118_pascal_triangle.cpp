#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows, vector<int>(numRows,0));
        for (int i=0; i<numRows; i++) {
            ans[i].resize(i+1);
            for (int j=0; j<ans[i].size(); j++) {
                if (j==0) {
                    ans[i][j]=1;
                }
                else if (j==i) {
                    ans[i][j]=1;
                }
                else {
                    ans[i][j]= ans[i-1][j-1]+ans[i-1][j]; 
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> ans;
    Solution obj1;
    ans = obj1.generate(5);

    for (int i=0; i<ans.size(); i++) {
        for (int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
} 
