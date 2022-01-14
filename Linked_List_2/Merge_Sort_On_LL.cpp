#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
Node *mergeSort(Node *head)
{
	//Write your code here
    if(head==NULL){
        return head;
    }else if(head->next==NULL){
        return head;
    }
    Node* slow= head;
    Node* fast = head->next;
    while(fast!=NULL && (fast->next !=NULL)){
        slow= slow->next;
        fast= fast->next;
        fast= fast->next;
        if(fast==NULL){
            break;
        }
    }
    Node *temp = slow->next;
    slow->next = NULL;
    Node* head1 = mergeSort(head);
    Node* head2 = mergeSort(temp);
    
    Node* newhead=NULL;
    Node *newtail=NULL;
    if(head1->data < head2->data){
        newhead=head1;
        newtail=head1;
        head1= head1->next;
    }else{
        newhead=head2;
        newtail=head2;
        head2= head2->next;
    }
    while(head1!=NULL && head2!=NULL){
        if(head1->data < head2->data){
            newtail->next = head1;
            head1= head1->next;
            newtail = newtail->next;
            
        }else{
            newtail->next = head2;
            head2= head2->next;
            newtail = newtail->next;
        }
    }
    if(head1!=NULL){
        newtail->next = head1;
    }else if(head2!=NULL){
        newtail->next= head2;
    }
    return newhead;
    
}
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}