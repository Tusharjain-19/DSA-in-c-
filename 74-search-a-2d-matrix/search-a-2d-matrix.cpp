class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ans = -1;
        for(int i =0 ;i<matrix.size();i++){
            for(int j = 0 ;j<matrix[i].size();j++){
                if(matrix[i][j]==target){
                    ans = 1;
                }
            }
        }
        if (ans ==1) return true;

        return false;   
    }
};