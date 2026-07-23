class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = findmax(weights);
        int high = sumofarray(weights);
        int ans = high;
        while(low<=high){
            int mid = (low+high)/2;
            int req_day = requiredday(weights,mid); 
            if(req_day<=days){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    int requiredday(vector<int>&arr,int cap){
        int day =1 ;
        int load =0;
        for ( int i =0 ;i<arr.size();i++){
            if( load+arr[i]>cap){
                day ++;
                load = arr[i];
            }
            else{
                load+=arr[i];
            }
        }
        return day;
    }
    int findmax(vector<int>&arr){
        int maxi = INT_MIN;
        for (int i =0 ; i<arr.size();i++){
            maxi= max(maxi, arr[i]);
        }
        return maxi;
    }
    int sumofarray(vector<int>&arr){
        int sum =0;
        for (int i =0 ;i <arr.size();i++){
            sum += arr[i];
        }
        return sum;
    }
};