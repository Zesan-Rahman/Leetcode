#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
	//Checks if the target can be formed given the digits
	bool canFormNum(long long target, unordered_map<int, int>& digits) {
		unordered_map<int, int> targetDigits;
		while(target >= 1) {
			targetDigits[target % 10]++;
			target /= 10;
		}
		for(auto i: targetDigits) {
			if(i.second != digits[i.first]) return false;
		}
		return true;
	}
	bool reorderedPowerOf2(int n) {
		if(n == 1) return true;
		int numDigits = 0;
		unordered_map<int, int> digits;
		while(n >= 1) {
			numDigits++;
			digits[n % 10]++;
			n /= 10;
		}
		vector<long long> validNums;
		long long power = 10;
		long long possibleNum = 2;
		int possibleNumDigits = 1;
		while(possibleNumDigits <= numDigits) {
			if(possibleNumDigits == numDigits) {
				validNums.push_back(possibleNum);
			}
			possibleNum *= 2;
			if(possibleNum >= power) {
				possibleNumDigits++;
				power *= 10;
			}
		}
		for(int i = 0; i < validNums.size(); i++) {
			if(canFormNum(validNums[i], digits)) return true;
		}
		return false;
	}
};

