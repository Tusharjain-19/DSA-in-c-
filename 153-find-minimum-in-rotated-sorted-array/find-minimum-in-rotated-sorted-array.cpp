class Solution {
public:
    int findMin(vector<int>& nums) {
        int low =0;
        int high = nums.size()-1;
        int ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            //left side arra is sorted then low wala min hoga usme 
            if(nums[low]<=nums[mid]){
                ans = min(ans , nums[low]);
                //left ho gaya ab right mai dhekte hai 
                low=mid+1;
            }
            //if left nhi sorted then right hoga na 
            else{
                //rigth array sorted hai tho 
                ans = min(ans,nums[mid]);
                //right ho gaya ab left jaega 
                high = mid-1;
            }
        }
        return ans;
    }
};