#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> result = {};
        const unsigned int n = matrix[0].size();
        for (unsigned int i = 0; i < n; i++) {
            int sum = 0;
            for (unsigned int j = 0; j < n; j++) {
                sum += matrix[i][j];
            }
            result.push_back(sum);
        }
        return result;
    }
};

int main() {
    Solution* sol = new Solution();
    vector<vector<int>> matrix = {{0,1,1},{1,0,1},{1,1,0}};
    vector<int> result = sol->findDegrees(matrix);
    for (auto it: result) {
        cout << it << " ";
    }
    delete sol;
}
