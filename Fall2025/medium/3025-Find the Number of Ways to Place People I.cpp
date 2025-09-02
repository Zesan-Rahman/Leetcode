#include <vector>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            for(int j = 0; j < points.size(); j++) {
                if(j == i) continue;
                if(points[j][0] <= x && points[j][1] >= y) {
                    int lx = points[j][0];
                    int uy = points[j][1];
                    bool valid = true;
                    for(int k = 0; k < points.size(); k++) {
                        if(k == i || k == j) continue;
                        if(points[k][0] >= lx && points[k][0] <= x) {
                            if(points[k][1] >= y && points[k][1] <= uy) valid = false;
                        }
                    }
                    if(valid) ans++;
                }
            }
        }
        return ans;
    }
};
