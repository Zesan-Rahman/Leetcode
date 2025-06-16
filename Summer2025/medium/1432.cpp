#include <vector>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        vector<int> number;
        /*
        There are 2 cases where you replace the minimum digit with 1
        1) All digits are the same
        2) The leading digit is being replaced
        */
        bool replaceMinWithOne = true;
        while (num >= 1) {
            number.push_back(num % 10);
            //If there ever is a different digit, all digits are not the same and therefore, case 1 isn't met
            if(num % 10 != number[0]) {
                replaceMinWithOne = false;
            }
            num /= 10;
        }
        int minDigit = 0;
        int maxDigit = 9;
        if(replaceMinWithOne) {
            minDigit = number[0];
            maxDigit = number[0];
        }
        else {
            bool minDigitFound = false;
            bool maxDigitFound = false;
            //Case 2: Test if the leading digit is being replaced
            //Note that a leading digit of 1 can never be replaced bc no leading 0s
            if(number[number.size() - 1] > 1) {
                minDigit = number[number.size() - 1];
                minDigitFound = true;
                replaceMinWithOne = true;
            }
            int counter = number.size() - 1;
            while (counter >= 0 && (!minDigitFound || !maxDigitFound)) {
                if(!maxDigitFound && number[counter] < 9) {
                    maxDigit = number[counter];
                    maxDigitFound = true;
                }
                //If min digit not found, then we know leading digit is 1 and therefore, minDigit must be > 1
                if(!minDigitFound && number[counter] > 1) {
                    minDigit = number[counter];
                    minDigitFound = true;
                }
                counter--;
            }
            
        }
        int max = 0;
        int min = 0;
        //Now counter will be used to track the decimal value
        int counter = 1;
        for (int i = 0; i < number.size(); i++) {
            if(number[i] == maxDigit) {
                max += 9 * counter;
            }
            else {
                max += number[i] * counter;
            }

            if(number[i] == minDigit) {
                if(replaceMinWithOne) {
                    min += 1 * counter;
                }
                else {
                    min += 0 * counter;//Does nothing but helps me see us replacing the digit with 0
                }
            }
            else {
                min += number[i] * counter;
            }
            counter *= 10;
        }
        return max - min;
    }
};

int main() {
    Solution sol;
    sol.maxDiff(1101057);
}