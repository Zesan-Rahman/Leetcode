#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRowZero = false;
        bool firstColZero = false;
        for (unsigned char i = 0; i < matrix.size(); i++) {
                for (int k = 0; k < matrix[i].size(); k++) {
                    if (matrix[i][k] == 0) {
                        if (i == 0) firstRowZero = true;
                        if (k == 0) firstColZero = true;
                        matrix[i][0] = 0;
                        matrix[0][k] = 0;
                    }
                }
        }
        //Set rows to 0
        for (unsigned char i = 1; i < matrix.size(); i++) {
            if(matrix[i][0] == 0) {
                for (int k = 1; k < matrix[i].size(); k++) {
                    matrix[i][k] = 0;
                }
            }
        }
        //Set columns to 0
        for (unsigned char k = 1; k < matrix[0].size(); k++) {
            if(matrix[0][k] == 0) {
                for (int i = 1; i < matrix.size(); i++) {
                    matrix[i][k] = 0;
                }
            }
        }
        if(firstRowZero) {
            for (unsigned char k = 0; k < matrix[0].size(); k++) {
                matrix[0][k] = 0;
            }
        }
        if(firstColZero) {
            for (unsigned char i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};