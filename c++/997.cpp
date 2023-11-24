#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> in(n,0);
        vector<int> out(n,0);

        for (int i=0;i<n;i++){
            if (in[i]==n-1 && out[i] == 0) {
                    return i+1;
                } 
        }
        return -1;
    }
};