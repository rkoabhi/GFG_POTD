// User function Template for C++
/*
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.

Examples :

Input:  n = 5, k = 4, dict = {"baa","abcd","abca","cab","cad"}
Output: 1
Explanation: Here order of characters is 'b', 'd', 'a', 'c' Note that words are sorted and in the given language "baa" comes before "abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
*/
class Solution {
  public:
    string findOrder(string dict[], int n, int k) {
    // Create an adjacency list for the graph
    vector<int> adj[k];
    
    // Step 1: Build the graph
    for(int i = 0; i < n - 1; i++){
        string first_word = dict[i];
        string second_word = dict[i + 1];
        
        // Compare characters of both words
        for(int j = 0; j < min(first_word.length(), second_word.length()); j++){
            if(first_word[j] != second_word[j]){
                // Create a directed edge from first_word[j] to second_word[j]
                adj[first_word[j] - 'a'].push_back(second_word[j] - 'a');
                break;
            }
        }
    }
    
    // Step 2: Find in-degrees of all nodes
    vector<int> in_deg(k, 0);
    for(int i = 0; i < k; i++){
        for(int node : adj[i]){
            in_deg[node]++;
        }
    }
    
    // Step 3: Initialize queue with nodes having in-degree 0
    queue<int> q;
    for(int i = 0; i < k; i++){
        if(in_deg[i] == 0){
            q.push(i);
        }
    }
    
    // Step 4: Perform BFS to get the topological sort
    string order;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        order += (char)(node + 'a');
        
        // Decrease in-degree of adjacent nodes and add to queue if in-degree becomes 0
        for(int neighbour : adj[node]){
            in_deg[neighbour]--;
            if(in_deg[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
    
    // Step 5: If the order length is less than k, it means there was a cycle
    if(order.length() < k) {
        return "";
    }
    
    return order;
}
};
