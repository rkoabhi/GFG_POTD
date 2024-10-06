// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        int n = nums.size();
        vector<long long int> left_side(n,1);
        vector<long long int> right_side(n,1);
        
        for(int i =1;i<n;i++){
            left_side[i] = left_side[i-1] * nums[i-1];
        }
        for(int i =n-2;i>=0;i--){
            right_side[i] = right_side[i+1] * nums[i+1];
        }
        
        vector<long long int> final(n);
        for(int i=0;i<n;i++){
            final[i] = left_side[i] * right_side[i];
        }
        return final;

    }
};
