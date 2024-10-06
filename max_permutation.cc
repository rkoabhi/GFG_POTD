class Solution {
  public:
    int Maximize(vector<int> &arr) {
        // Complete the function
        const int MOD = 1e9 + 7;
        std::sort(arr.begin(),arr.end());
        long long sum=0;
        
        for (int i=0;i<arr.size();i++){
            sum = (sum +(long long)arr[i] * i) % MOD;
        }
        return sum;
        
    }
};
