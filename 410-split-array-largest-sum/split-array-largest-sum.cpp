class Solution {
public:

//optimal solution 
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
    // we check at perticular value of our search space let say test cae 1 we get mid / bar = 19  and sum =0 
    //now for 19 we check arr[i] is > bar here no then arr[i o add kro sum mai ]and check left side 
    //now say we get 6  so bar / mid = 6  we get arr[i] (first element is 7)  so we cannot allocate so increase mid / bar 
    // we get bar/mid 10 , now here 10 is greater then 7(fisrt) so add in sum ;
    //sum = 7, now arr[2]=2  which is {7+2=9}<10 so yes , sum = 9 ;
    //now as we add 5 it say no 14>10 so allocated{check k} ++ so now we slipt aary to 2nd half and try
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