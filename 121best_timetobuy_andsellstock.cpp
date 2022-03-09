#include <stdio.h>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// brute way - no pass
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int temp;

        for (int i=0; i<prices.size(); i++) {
            for (int j=i+1; j<prices.size(); j++) {
                temp = prices[j]-prices[i];
                if (temp>ans) {
                    ans = temp;
                }
            }
        }

        return ans;
    }
};
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int currentprofit = 0;
        int least_cost = INT_MAX;

        for (int i=0; i<prices.size(); i++) {
            if (prices[i]<least_cost) {
                least_cost = prices[i];
            }
            currentprofit = prices[i] - least_cost;
            if (currentprofit > maxprofit) {
                maxprofit = currentprofit;
            }
        }
        return maxprofit;
    }
};

int main() {
    int ans;

    // vector<int> prices= {7,1,5,3,6,4};
    vector<int> prices= {7,6,4,3,1};
    
    Solution obj1;
    ans = obj1.maxProfit(prices);

    cout << "max profit is: " << ans << endl;

    return 0;
} 
