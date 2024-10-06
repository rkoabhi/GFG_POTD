
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        int n = arr1.size();
        vector<int> merged(2 * n);
        int i = 0, j = 0, k = 0;
        
        // Merge the two sorted arrays
        while (i < n && j < n) {
            if (arr1[i] < arr2[j]) {
                merged[k++] = arr1[i++];
            } else {
                merged[k++] = arr2[j++];
            }
        }
        
        // Copy remaining elements
        while (i < n) {
            merged[k++] = arr1[i++];
        }
        while (j < n) {
            merged[k++] = arr2[j++];
        }
        
        // Find the sum of the middle elements
        int mid1 = n - 1;
        int mid2 = n;
        return merged[mid1] + merged[mid2];
    }
};
