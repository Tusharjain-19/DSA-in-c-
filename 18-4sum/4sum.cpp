class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                set<long long> hashset;
                for (int k = j + 1; k < n; k++) {
                    // Cast to long long before adding to prevent 32-bit integer overflow
                    long long sum = (long long)nums[i] + nums[j] + nums[k];
                    long long forth = (long long)target - sum;

                    if (hashset.find(forth) != hashset.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)forth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }
        return vector<vector<int>>(st.begin(), st.end());
    }
};