class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int result = firstocc(nums,n,target);
        return result;
    }
    int firstocc(vector<int>&arr,int n ,int k){
        int ans =n;
        for(int i = 0 ;i<n;i++){
            if(arr[i]>=k){
                ans = i;
                break;
            }
        }
        return ans;
    }
    int lowerbound(vector<int>&arr,int n ,int k){
        int low = 0,high = n-1;
        int ans = n;
        while(low<=high){
            int mid = (low+high)/2;
            if (arr[mid]>=k){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};