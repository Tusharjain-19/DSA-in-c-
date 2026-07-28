class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = -1;
        for(int i =0 ;i<n;i++){
            // for(int j = 0 ;j<matrix[i].size();j++){
            //     if(matrix[i][j]==target){
            //         ans = 1;
            //     }
            // }
            int low = 0 , high = m-1;
            while(low<=high){
                int mid = (low+high)/2;
                if(matrix[i][mid]==target){
                    ans = 1;
                    break;
                }
                else if(matrix[i][mid]>target){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
        }
        if (ans ==1) return true;

        return false;   
    }
};