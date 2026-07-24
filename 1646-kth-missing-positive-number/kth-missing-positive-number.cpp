class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int missing = arr[mid] - (mid + 1);
            
            if (missing < k) {
                left = mid + 1; // Look to the right
            } else {
                right = mid - 1; // Look to the left
            }
        }
        
        // After binary search, 'left' is the insertion index.
        // The kth missing number can be derived as: left + k
        return left + k;
    }
};