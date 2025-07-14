#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int pCounter = 0;
        int tCounter = 0;
        int ans = 0;
        while (pCounter < players.size() && tCounter < trainers.size()) {
            bool trainerEligible = players[pCounter] <= trainers[tCounter];
            if(trainerEligible) {
                tCounter++;
                pCounter++;
                ans++;
            }
            else {
                tCounter++;
            }
        }
        return ans;
    }
};