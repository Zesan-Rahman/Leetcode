#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        auto hamDist = [](const string& l, const string& r) {
            if (l.size() != r.size()) return false; 
            int diff = 0;
            for(int i = 0; i < l.size(); ++i) { 
                if(l[i] != r[i]) diff++;
            }
            return diff == 1;
        };

        vector<vector<string>> table;
        vector<int> IDs;
        vector<string> result;
        table.push_back(result); //Put an entry in the table

        for (int i = 0; i < words.size(); i++) {
            if (i == 0) {
                table[0].push_back(words[i]);
                IDs.push_back(groups[i]);
            }
            else {
                bool inSubsequence = false;
                for (int k = 0; k < table.size(); k++) {
                    if(hamDist(words[i], table[k].back()) && IDs[k] != groups[i]) {
                        inSubsequence = true;
                        table[k].push_back(words[i]);
                        IDs[k] = groups[i];
                        break;
                    }
                }
                if(!inSubsequence) {
                    vector<string> temp;
                    temp.push_back(words[i]);
                    table.push_back(temp);
                    IDs.push_back(groups[i]);
                }
            }
        }

        result = table[0];
        for (int k = 0; k < table.size(); k++) {
            if(result.size() < table[k].size()) {
                result = table[k];
            }
        }
        return result;
    }
};