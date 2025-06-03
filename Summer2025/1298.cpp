#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
            if(initialBoxes.size() == 0) return 0;
            int candyCount = 0;
            //-1 means not visited, 0 means visited but locked, 1 means visited and unlocked
            vector<int> visited(status.size(), -1);
            //Don't want to modify status
            vector<int> unlockable = status;
            for (size_t i = 0; i < initialBoxes.size(); i++) {
                int rootBox = initialBoxes[i];
                if(visited[rootBox] != 1) {
                    queue<int> q;
                    q.push(rootBox);
                    while(!q.empty()) {
                        int currentBox = q.front();
                        q.pop();
                        if(visited[currentBox] != 1) {
                            if(!unlockable[currentBox]) {
                                visited[currentBox] = 0;
                            }
                            else{ 
                                visited[currentBox] = 1;
                                candyCount += openBox(candies, keys, unlockable, containedBoxes, visited, q, currentBox);
                            }
                        }
                    }
                }
            }
            return candyCount;
    }

    int openBox(vector<int>& candies, vector<vector<int>>& keys, vector<int>& unlockable, vector<vector<int>>& containedBoxes,
    vector<int>& visited, queue<int>& q, int currentBox) 
    {
        for(int k = 0; k < keys[currentBox].size(); k++) {
            //Key also functions as box number
            int key = keys[currentBox][k];
            unlockable[key] = 1;
            if(visited[key] == 0){
                q.push(key);
            }
        }
        for (int j = 0; j < containedBoxes[currentBox].size(); j++) {
            if(visited[containedBoxes[currentBox][j]] == -1) {
                q.push(containedBoxes[currentBox][j]);
            }   
        }
        return candies[currentBox];;
    }
};