class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        
        if (numRows <= 0) return triangle;
        
        // The first row is always [1]
        triangle.push_back({1});
        
        for (int i = 1; i < numRows; ++i) {
            vector<int> prevRow = triangle.back();
            vector<int> currRow;
            
            // Each row starts with 1
            currRow.push_back(1);
            
            // Calculate the interior values
            for (int j = 1; j < i; ++j) {
                currRow.push_back(prevRow[j - 1] + prevRow[j]);
            }
            
            // Each row ends with 1
            currRow.push_back(1);
            
            triangle.push_back(currRow);
        }
        
        return triangle;
    }
};