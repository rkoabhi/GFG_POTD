class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int total = std::accumulate(arr.begin(),arr.end(),0);
        
        if(total % 2!=0 ){
            return false;
        }
        int iter_sum = 0;
        int half_sum = total/2;
        
        for(int i =0; i< arr.size();++i){
            iter_sum = iter_sum + arr[i];
            
            if(iter_sum == half_sum){
                return true;
            }
        }
        return false;
    }
};
