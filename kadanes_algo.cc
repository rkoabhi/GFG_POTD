// User function Template for C++
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        int max = arr[0];
        int curr_max = arr[0];
        
        for(size_t i =1 ; i<arr.size();i++){
            
            curr_max = std::max(arr[i],curr_max+arr[i]);
            max = std::max(max,curr_max);
        }
        return max;
    }
};
