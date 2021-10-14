
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        for( int row = 0; row < N/2; ++row ) {
            for( int col = row; col < N - row - 1; ++col ) {
                int tmp = matrix[row][col];
                matrix[row][col]         = matrix[N-col-1][row];
                matrix[N-col-1][row]     = matrix[N-row-1][N-col-1];
                matrix[N-row-1][N-col-1] = matrix[col][N-row-1];
                matrix[col][N-row-1]     = tmp;               
            }
        }
        return;
    }
};

