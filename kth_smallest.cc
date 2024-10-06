// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
         set<int> sortedSet(arr.begin(), arr.end());
    
    auto it = sortedSet.begin();
    advance(it, k - 1);
    
    return *it;
    }
};
