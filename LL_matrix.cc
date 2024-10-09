/*structure of the node of the linked list is as

struct Node
{
    int data;
    Node* right, *down;

    Node(int x){
        data = x;
        right = NULL;
        down = NULL;
    }
};
*/

// function must return the pointer to the first element of the in linked list i.e. that
// should be the element at arr[0][0]
class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        // code Here
        int n = mat.size();
        
        vector<Node*> upper_row(n,NULL);
        
        Node *head = NULL;
        
        for (int i =0;i<n;i++){
            Node *previous = NULL;
            for (int j =0; j<n;j++){
                Node *new_node = new Node(mat[i][j]);
                
            if (i==0 && j==0){
                head = new_node;
            }
            
            if (previous!=NULL){
                previous->right=new_node;
            }
            previous=new_node;
            if (i>0){
                upper_row[j]->down = new_node;
            }
            upper_row[j]=new_node;
            }
        }
        return head;
    }
};
