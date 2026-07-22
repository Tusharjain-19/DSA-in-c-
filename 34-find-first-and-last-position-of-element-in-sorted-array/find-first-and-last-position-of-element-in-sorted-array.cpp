class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n =nums.size();
        int first =firstocc(nums,n,target);
        if(first==-1) 
            return{-1,-1};
        int last=lastocc(nums,n,target);
        return {first,last};
    }

    int firstocc(vector<int>&arr,int n, int target){
        int low = 0;
        int high =n-1;
        int first =-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==target){
                first=mid;
                high=mid-1;
            }
            else if(arr[mid]<target){
                low=mid+1;
            }
            else{
                high =mid-1;
            }
        }
        return first;
    }

    int lastocc(vector<int>&arr,int n, int target ){
        int low = 0;
        int high = n-1;
        int last = - 1 ;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==target){
                last=mid;
                low=mid+1;
            }
            else if (arr[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return last;
    }
};