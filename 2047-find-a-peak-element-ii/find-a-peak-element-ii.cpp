class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        //it say we take mid column then check max elemt in that column and find it's row on which the max elemnt with column mid and then we check with its right and left because as it is max in cloumn it is already peak so no up down check need
        //why max soch lala max element ki probility jayda hai max niklne ki as max se pata lg gaya column mai tho max hai vo 
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