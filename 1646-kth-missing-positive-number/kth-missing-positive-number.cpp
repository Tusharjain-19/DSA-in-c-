class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {



        //brute force  agar merko array wala number k se chota ya equal hai tho k++ as we find bigger then it we break
        for( int i = 0 ; i < arr.size() ; i++ ){
            if(arr[i]<=k) k++;
            else break;
        }
        return k;
    }
};