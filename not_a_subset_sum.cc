// User function template for C++

class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        // Your code goes here.
        long long sum = 1;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]>sum){
                break;
            }
            sum = sum + arr[i];
        }
        return sum;
    }
};
