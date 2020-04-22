// https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/777/
// WARNING! This solution doesn't pass all tests. Fails on very large numbers ~ MAXINT/4.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        auto m = matrix.size();
        auto n = matrix[0].size();

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                matrix[i][j] *= 4;

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(matrix[i][j] / 4 == 0) {
                    matrix[i][0] |= 1;
                    matrix[0][j] |= 1;
                }

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if((matrix[i][0] & 1) || (matrix[0][j] & 1))
                    matrix[i][j] |= 2;

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(matrix[i][j] & 2)
                    matrix[i][j] = 0;
                else
                    matrix[i][j] /= 4;
    }
};
