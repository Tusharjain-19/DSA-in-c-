class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>neg;
        vector<int>pos;
        for(int i = 0 ;i < n ; i++){
            if(nums[i]<0)
                neg.push_back(nums[i]);
            else
                pos.push_back(nums[i]);
        }
        int a = neg.size(); 
        int b = pos.size();
        if(a==0) //no negative 
        {
            for(int i = 0 ; i < b ; i++){
                pos[i]=pos[i]*pos[i];
            }
            return pos;
        }
        if(b==0) // no positive 
        {
            for(int i = 0 ;i < a ; i++){
                neg[i]=neg[i]*neg[i];
            }
            reverse(neg.begin(),neg.end());
            return neg;
        }
        int i = 0 , j = 0;
        int id = 0;
        vector<int> res(a+b);
        for(int i=0;i<a;i++){
            neg[i]=neg[i]*neg[i];
        } 
        reverse(neg.begin(),neg.end());
        for(int i = 0 ; i < b ; i++){
                pos[i]=pos[i]*pos[i];
        }
        while( i<a && j<b ){
            if(neg[i]<=pos[j]){
                res[id]=neg[i];
                i++;
                id++;
            }
            else{
                res[id]=pos[j];
                j++;
                id++;
            }
        }
        while (i<a){
            res[id]=neg[i];
            i++;
            id++;
        }
        while (j<b){
            res[id]=pos[j];
            j++;
            id++;
        }
        return res;
    }
};