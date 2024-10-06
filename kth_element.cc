class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        std::vector<int> merged(arr1.size() + arr2.size());
        std::merge(arr1.begin(),arr1.end(),arr2.begin(),arr2.end(),merged.begin());
        std::sort(merged.begin(),merged.end());
        return merged[k-1];
        
    }
};
