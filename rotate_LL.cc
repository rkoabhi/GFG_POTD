// rotate a LL

/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to rotate a linked list.
       Node* rotate(Node* head, int k)
    {
        if(k == 0)
        {
            return head;
        }
        Node* cur = head;
        int count = 1;
        while(count < k && cur != NULL)
        {
            count++;
            cur = cur->next;
        }
        Node* kth = cur;
        while(cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = head;
        head = kth->next;
        kth->next = NULL;
        return head;
    }

};
