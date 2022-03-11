#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <climits>

using namespace std;

// usnig map:faster 43.47% sol
/*
class Solution {
public:
    int firstUniqChar(string s) {
        char* array;
        array = &s[0];
        map<char, pair<int, int>> mapfreq;
        for (int i=0; i<s.length(); i++) {
            if (mapfreq.find(array[i]) == mapfreq.end()) {
                mapfreq.insert({array[i], {1,i}});
            }
            else {
                mapfreq[array[i]].first ++;
            }
        }
        map<char, pair<int, int>>::iterator itr;
        int index=INT_MAX;
        for (itr=mapfreq.begin(); itr!=mapfreq.end(); itr++) {
            // cout << "first " <<itr->first << ", second "<<itr->second.first << "," << itr->second.second << endl;
            if (itr->second.first == 1) {
                index = min(itr->second.second,index);
            }
        }
        
        if (index>s.length()) index=-1;
        return index;
    }
};
*/

// using hash table
class Solution {
public:
    int firstUniqChar(string n) {
        unordered_map<char, int> my_map;
        for (int i=0; i<n.length(); i++) {
            my_map[n[i]]++;
        }
        for (int i=0; i<n.length(); i++) {
            // cout << my_map[n[i]] << endl; //string every character freq
            if (my_map[n[i]]==1)
                return i;
        }
        return -1;
    }
};

int main() {
    // string input("leetcode");
    string input("loveleetcode");
    // string input("aabb");
    Solution obj1;
    cout << obj1.firstUniqChar(input) << endl;
    
    return 0;
} 
