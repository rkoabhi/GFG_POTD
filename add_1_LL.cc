// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
         vector<int> values;

    Node* temp = head;
    while (temp != nullptr) {
        values.push_back(temp->data);
        temp = temp->next;
    }

    /*
    now suppose 999
    values = [9,9,9]
    carry = 1
    i =2
    values[2] = 9
    values[2] = values[2] + carry will give values[2] = 9+1=10
    new carry will be
    carry = values[2]/10, that is 10/10 = 1
    values[2]%10 will be 1-%10 =0
    so now i have [9,9,0]
    now i =1
    */
    int carry = 1; 
    for (int i = values.size() - 1; i >= 0; --i) {
        values[i] += carry;
        carry = values[i] / 10; 
        values[i] %= 10; 
    }

    
    if (carry > 0) {
        values.insert(values.begin(), carry);
    }

    
    Node* newHead = new Node(values[0]);
    Node* current = newHead;
    for (int i = 1; i < values.size(); ++i) {
        current->next = new Node(values[i]);
        current = current->next;
    }

    return newHead;
    }
};
