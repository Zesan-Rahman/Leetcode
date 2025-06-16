#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        vector<int> number;
        while (num >= 1) {
            number.push_back(num % 10);
            num /= 10;
        }
        //Best digit to minimize will always be the first digit
        int minDigit = number[number.size() - 1];
        int maxDigit = 9;
        int counter = number.size() - 1;
        while (counter >= 0) {
            //Get the highest valued digit that isn't a 9 so we can turn it into a 9 later
            if (number[counter] != 9) {
                maxDigit = number[counter];
                break;
            }
            counter--;
        }
        int max = 0;
        int min = 0;
        //Now counter will be used to track the decimal value
        counter = 1;
        for (int i = 0; i < number.size(); i++) {
            if(number[i] == maxDigit) {
                max += 9 * counter;
            }
            else {
                max += number[i] * counter;
            }

            if(number[i] == minDigit) {
                min += 0 * counter;//Does nothing but helps me see us replacing the digit with 0
            }
            else {
                min += number[i] * counter;
            }
            counter *= 10;
        }
        return max - min;
    }
};