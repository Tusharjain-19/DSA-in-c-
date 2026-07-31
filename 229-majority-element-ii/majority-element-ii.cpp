class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> list;
        
        for (int i = 0; i < n; i++) {
            // Check if nums[i] is already in our list
            bool alreadyExists = false;
            for (int val : list) {
                if (val == nums[i]) {
                    alreadyExists = true;
                    break;
                }
            }
            // If it's not already in the list, count its occurrences
            if (alreadyExists == false) {
                int count = 0;
                for (int j = 0; j < n; j++) {
                    if (nums[j] == nums[i]) {
                        count++;
                    }
                }
                if (count > n / 3) {
                    list.push_back(nums[i]);
                }
            }
        } 
        return list;    
    }
};