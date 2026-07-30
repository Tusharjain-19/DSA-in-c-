class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //list of list 
        vector<vector<int>> triangle;
        for(int i = 1 ; i <= numRows ;i++){
            triangle.push_back(generate_row(i));
        }
        return triangle;
    }
    //type 2 mai we generate row by its number so here we use it multiple type to print whole 
    vector<int>generate_row(int row){
        long long ans =1;
        vector<int>ansrow;
        ansrow.push_back(1);
        for(int col=1 ; col < row ; col++){
            ans = ans * (row-col);
            ans = ans/col;
            ansrow.push_back(ans);
        }
        return ansrow;
    }
};