// sum tree
/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
    int first_sum(Node *root){
        if (root ==nullptr){
            return 0;
        }
        return root->data + first_sum(root->left) + first_sum(root->right);
    }
    bool isSumTree(Node* root) {
        // Your code here
        if ( root == nullptr){
            return true;
        }
        if(root->left == nullptr && root->right == nullptr){
            return true;
        }
        bool left_sum_exists = isSumTree(root->left);
        bool right_sum_exists = isSumTree(root->right);
        
        int left_sum = first_sum(root->left);
        int right_sum = first_sum(root->right);
        
        return left_sum_exists && right_sum_exists && root->data == left_sum + right_sum;
    }
};
