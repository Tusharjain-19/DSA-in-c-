class Solution {
public:
    int findmax(vector<int>&arr ){
        int maxi = INT_MIN;
        for(int i=0;i<arr.size();i++){
            maxi=max(maxi,arr[i]);
        }
        return maxi;
        }
        
    long long calculatetotalhours(vector<int>&arr,int hourly){
        long long totalhour = 0;
        for(int i=0;i<arr.size();i++){
            // here 7/2 must we need 4 not 3 .
            totalhour+=ceil((double)arr[i]/(double)hourly);
        }
        return totalhour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findmax(piles);
        int ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            //long long because total hour may be of big size and also our function return long long not integer 
            long long total_hour = calculatetotalhours(piles,mid);
            if(total_hour<=h){
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