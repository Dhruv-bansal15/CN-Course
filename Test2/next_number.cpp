#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;


Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}
Node *reverse(Node *head) 
{ 
    Node * prev = NULL; 
    Node * current = head; 
    Node * next; 
    while (current != NULL) 
    { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    return prev; 
}
Node* NextLargeNumber(Node *head) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    head = reverse(head);
    Node *temp= head, *temper;
    int carry=1,sum;
    while(head!=NULL){
        sum = carry + head->data;
        carry = (sum>=10) ? 1 : 0;
        sum%=10;
        head->data = sum;
        temper = head;
        head= head->next;
    }
    if(carry==1){
        temper->next = new Node(carry);
    }
    head = reverse(temp);
    return head;
    
}
int main() {
    Node *head = takeinput();
    
    head = NextLargeNumber(head);
    print(head);
    return 0;
}



