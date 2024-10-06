// Burning Tree
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        if (!root) return 0;

    unordered_map<Node*, Node*> parent_map;
    Node* target_node = nullptr;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current->data == target) {
            target_node = current;
        }

        if (current->left) {
            parent_map[current->left] = current;
            q.push(current->left);
        }

        if (current->right) {
            parent_map[current->right] = current;
            q.push(current->right);
        }
    }

    q.push(target_node);
    set<Node*> visited;
    visited.insert(target_node);

    int time = 0;

    while (!q.empty()) {
        int size = q.size();
        bool burned = false;

        for (int i = 0; i < size; i++) {
            Node* current = q.front();
            q.pop();

            if (current->left && visited.find(current->left) == visited.end()) {
                burned = true;
                visited.insert(current->left);
                q.push(current->left);
            }

            if (current->right && visited.find(current->right) == visited.end()) {
                burned = true;
                visited.insert(current->right);
                q.push(current->right);
            }

            if (parent_map[current] && visited.find(parent_map[current]) == visited.end()) {
                burned = true;
                visited.insert(parent_map[current]);
                q.push(parent_map[current]);
            }
        }

        if (burned) {
            time++;
        }
    }
    
    return time;
}
    
};
