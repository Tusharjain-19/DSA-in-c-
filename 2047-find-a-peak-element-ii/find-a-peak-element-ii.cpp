class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0 , high = m-1;   
        while(low<=high){
            int mid = (low+high)/2;
            int max_row=0;
            for(int i =0 ;i<n;i++){
                if(mat[i][mid]>mat[max_row][mid])
                max_row = i;
            }
            int left = (mid > 0)? mat[max_row][mid-1] : -1;
            int right = (mid < m-1)? mat[max_row][mid+1]:-1;
            if(mat[max_row][mid]>left && mat[max_row][mid]>right){
                return {max_row,mid};
            }
            else if(mat[max_row][mid]<left){
                high = mid - 1;
            }
            else{
                low = mid + 1; 
            }
        }
        return {-1,-1};
    }
};