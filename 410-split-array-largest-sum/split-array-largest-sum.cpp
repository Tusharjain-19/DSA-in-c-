class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = mini(nums);
        int high = sum(nums);
        int ans =-1;
        while(low<=high){
            int mid= (low + high)/2;
            if(possible(nums,mid,k)==1) {
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    int possible(vector<int>&arr,int bar,int k ){
        int allocted=1;
        int sum=0;//pages
        for (int i=0 ;i<arr.size();i++){
            if(arr[i]>bar) return -1;
            if (sum+arr[i]>bar){
                allocted++;
                sum=0;
                sum+=arr[i];
            }
            else{
                sum+=arr[i];
            }
        }
        if (allocted>k)return -1;
        else return 1;
    }
    int mini(vector<int>&arr){
        int mini = INT_MAX;
        for (int i =0 ;i<arr.size();i++){
            mini = min(mini,arr[i]);
        }
        return mini;
    } 
    int sum(vector<int>&arr){
        int sum =0 ;
        for (int i=0 ;i<arr.size();i++){
            sum = sum+arr[i];
        }
        return sum;
    }
};