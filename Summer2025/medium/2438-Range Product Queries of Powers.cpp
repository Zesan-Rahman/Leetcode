#include <vector>
#include <bitset>
#include <math.h>
using namespace std;

class Solution {
public:
	vector<int> productQueries(int n, vector<vector<int>>& queries) {
		vector<int> powers;
		bitset<32>bn(n);
		for(int i = bn.size() - 1; i >= 0; i--) {
			if(bn[i] == 1) {
				powers.push_back(pow(2,i));
			}
		}
		vector<int> answers;
		for(int i = 0; i < queries.size(); i++) {
			int start = powers.size() - 1 - queries[i][0];
			int end = powers.size() - 1 - queries[i][1];
			long long ans = 1;
			for(int j = start; j >= end; j--) {
				ans *= powers[j];
				ans %= (int) (pow(10, 9) + 7);
			}
			answers.push_back((int) (ans));
		}
		return answers;
	}
};

