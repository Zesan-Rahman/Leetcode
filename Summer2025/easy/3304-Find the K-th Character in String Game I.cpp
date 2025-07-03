#include <string>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        int operations = ceil(log2(k));
        string word = "a";
        for(int i = 0; i < operations; i++) {
            string addition = "";
            for(int j = 0; j < word.size(); j++) {
                if(word[j] == 'z') {
                    addition.push_back('a');
                }
                else {
                    addition.push_back(word[j] + 1);
                }
            }
            word.append(addition);
        }
        return word[k - 1];
    }
};