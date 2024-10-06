// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        if (arr.empty() || arr[0].empty()) return -1; 
        int n = arr.size();       
        int m = arr[0].size();    

        int maxRowIndex = -1;     
        int maxCount = 0;         
        int row = 0;              
        int col = m - 1;          

        while (row < n && col >= 0) {
            
            while (col >= 0 && arr[row][col] == 1) {
                col--;
            }
            
            int count = m - (col + 1);
            if (count > maxCount) {
                maxCount = count;
                maxRowIndex = row;
            }
            
            row++;
        }

        return maxRowIndex; 
    
    }
};
