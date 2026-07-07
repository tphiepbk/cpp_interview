#include <iostream>
#include <vector>
#include <string>
#include "utils.hh"

using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";
        unsigned int wordWeight = 0, i = 0;
        for (string word: words) {
            wordWeight = 0;
            for (i = 0; i < word.size(); i++) {
                wordWeight += weights[(unsigned int)word[i] - 97];
            }
            wordWeight = wordWeight % 26;
            res += (char)(25 - wordWeight + 97);
        }
        return res;
    }
};

int main() {
    Solution* sol = new Solution();
    vector<string> words = {"abcd","def","xyz"};
    vector<int> weights = {5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2};
    string res = sol->mapWordWeights(words, weights);
    cout << res;
    delete sol;
}
