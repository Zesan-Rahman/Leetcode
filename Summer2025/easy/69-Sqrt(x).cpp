#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x == 1) return 1;
        long long higher = x/2;
        long long lower = x/2;
        while(lower * lower >= x) {
            lower /= 2;
        }
        higher = lower;
        while(higher * higher <= x) {
            higher *= 2;
        }
        cout << lower << " " << higher << endl;
        for(long long i = lower; i <= higher; i++) {
            if(i * i > x) {
                return i-1;
            }
        }
        return 1;
    }
};
