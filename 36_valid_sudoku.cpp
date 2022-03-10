#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int which_grid(int row, int col) {
        return row/3*3+col/3;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> hori(9);
        vector<set<char>> vert(9);
        vector<set<char>> grid(9);
        int gridnum;
        
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                gridnum = which_grid(i,j);
                if (board[i][j] == '.')
                    continue;
                if (hori[i].find(board[i][j]) != hori[i].end())
                    return false;
                if (vert[j].find(board[i][j]) != vert[j].end())
                    return false;
                if (grid[gridnum].find(board[i][j]) != grid[gridnum].end())
                    return false;

                hori[i].insert(board[i][j]);
                vert[j].insert(board[i][j]);
                grid[gridnum].insert(board[i][j]);
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> input={
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'5', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'6', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'8', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'9', '.', '.', '.', '.', '.', '.', '.', '.'}
    };

    vector<vector<char>> sudoku4 ={
        {'.', '8', '7', '6', '5', '4', '3', '2', '1'},
        {'2', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'3', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'4', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'5', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'6', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'8', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'9', '.', '.', '.', '.', '.', '.', '.', '.'}
    }; 
    
    bool ans;
    Solution obj1;
    ans = obj1.isValidSudoku(sudoku4);
    cout << "ans= " << ans << endl;
    
    return 0;
} 
