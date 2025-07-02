#include <string>
#include <vector>
#include<limits.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        string number;
        bool nonZero = false;
        bool negative = false;
        //Delete all leading whitespace and end at first char
        for(char c: s) {
            //Nondigit characters
            if(c < '0' || c > '9') {
                //If the character is a sign, it is only valid at the start of the number
                if(c == '-' || c == '+') {
                    if(number.length() == 0) {
                        number.push_back(c);
                    }
                    else break;
                }
                //If it's whitespace after a number has been found, break
                else if(c == ' ' && number.length() > 0) {
                    break;
                }
                //If we reach any char that isn't a leading whitespace, break
                else if(c != ' ') break;
            }
            else {
                number.push_back(c);
                if(c != '0') {
                    nonZero = true;
                }
            }
        }
        //Check for negative sign
        if(number[0] == '-') {
            negative = true;
        }

        //If our number only has 0s, then we return 0
        if(!nonZero) return 0;
        //Otherwise, delete leading 0s
        else {
            int counter = 0;
            //Our number may have a sign at the beginning so allow signs to pass
            while(number[counter] == '0' || number[counter] == '+' || number[counter] == '-') {
                counter++;
            }
            number = number.substr(counter);
        }
        //Array of digits so adding to result is easy
        vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        long result = 0;
        long power = 1;
        //Read the number from ones digit to wherever it ends
        for(int i = number.length() - 1; i >= 0; i--) {
            if(number[i] == '-' || number[i] == '+') {
                break;
            }
            result += digits[number[i] - '0'] * power;
            //If the result or power ever becomes too big, we round
            if(result > INT_MAX || power > INT_MAX) {
                if(negative) return INT_MIN;
                return INT_MAX;
            }
            power *= 10;
        }
        if(negative) {
            result *= -1;
        }
        return result;
    }
};