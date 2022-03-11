#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomeNote, string magazine) {
        unordered_map<char,int> map;
        for (int i=0; i<magazine.length(); i++) {
            map[magazine[i]]++;
        }
        /*
        unordered_map<char,int>::iterator itr;
        for (itr=map.begin(); itr!=map.end(); itr++) {
            cout << itr->first << "," << itr->second << endl;
        }
        */
        for (int i=0; i<ransomeNote.length(); i++) {
            if (map.find(ransomeNote[i])!=map.end()) {
                map[ransomeNote[i]]--;
            }
            else {
                return false;
            }
            if (map[ransomeNote[i]]<0)
                return false;
        }
        return true;
    }
};

int main() {
    string ransomeNote("aa");
    string magazine("aab");
    
    Solution obj1;
    cout << obj1.canConstruct(ransomeNote, magazine) << endl;
    
    return 0;
} 
