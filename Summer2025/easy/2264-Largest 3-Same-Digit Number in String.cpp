#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string largestGoodInteger(string num) {
		string ans = "";
		for(int i = 0; i + 2 < num.length(); i++) {
			string sub = num.substr(i, 3);
			if(sub[0] == sub[1] && sub[0] == sub[2] && sub[1] == sub[2]){
				if(ans == "" || stoi(ans) < stoi(sub)) ans = sub;
			}
		}
		return ans;
	}
};
