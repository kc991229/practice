
//给定一个 n × n 的二维矩阵表示一个图像。
//
//将图像顺时针旋转 90 度。不允许使用额外数组
class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int n = matrix.size();
            for (int i = 0; i < n / 2; ++i) {
                for (int j = 0; j < n; ++j) {
                    swap(matrix[i][j], matrix[n - i - 1][j]);

                }

            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < i; ++j) {
                    swap(matrix[i][j], matrix[j][i]);

                }

            }

        }

};


