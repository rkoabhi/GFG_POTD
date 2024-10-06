class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
        
    /*
    Insert all the rope lengths into the min-heap.
While there are more than one rope in the heap:
Extract the two smallest ropes from the heap.
Compute the cost of connecting them.
Add the cost to the total cost.
Insert the resulting new rope back into the heap.
The total cost will be the sum of all the connection cost
    */
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    
    for(long long rope : arr){
        minHeap.push(rope);
    }
    
    long long total = 0;
    
    while(minHeap.size() > 1){
        long long first = minHeap.top();
        minHeap.pop();
        long long second = minHeap.top();
        minHeap.pop();
        long long cost = first + second;
        total = total + cost;
        
        minHeap.push(cost);
    }
    return total;
    
    }
};
