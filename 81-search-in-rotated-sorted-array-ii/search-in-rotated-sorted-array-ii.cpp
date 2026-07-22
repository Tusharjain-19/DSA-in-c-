class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low =0;
        int high =nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if (nums[mid]==target) return true;
            // ye important hai 
            if(nums[mid]==nums[low]&&nums[high]==nums[mid]){
                high--;
                low++;
                continue;
            }


        //left array sorted hai kya ?
        if (nums[low]<=nums[mid]){
            // kya target mid and low ke bich mai hai ? if yes then high left mai aaega find krne
            if(target>=nums[low]&&target<=nums[mid]){
                high = mid-1;
            }
            //if not in left matalb right mai hai tho low right jaega 
            else{
                low = mid+1;
            }
        }
        //right array sorted hai else mai
        else{
            // kya target mid and high ke bich hai ? if yes then low rigth jaega
            if(target>=nums[mid]&&target<=nums[high]){
                low = mid+1;
            }
            //if not then high left aaega 
            else{
                high = mid -1;
            }
        }
        }
        return false;
    }
};