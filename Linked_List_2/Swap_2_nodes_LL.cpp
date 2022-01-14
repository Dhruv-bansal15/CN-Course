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
Node *swapNodes(Node *head, int i, int j)
{
	//Write your code here
    if(i==j){
        return head;
    }
    Node* cool = head->next;
    Node* t1= head;
    Node* t2= head;
    int count=0;
    while(count<i-1){
        t1 = t1->next;
        count++;
    }
    count=0;
    while(count<j-1){
        t2 = t2->next;
        count++;
    }
    if(i==0 & t2==head){
        Node *temp = head->next;
        head->next = t2->next->next;
        head = temp;
        head->next = t1;
        return head;
        
    }else if(t1->next == t2 & t2->next->next==NULL){
        Node *temp = t2->next->next;
        t1->next = t2->next;
        t2->next->next = t2;
        t2->next = temp;
        return head;
        
    }else if(i==0 & t2->next->next==NULL){
        Node* temp=head;
        head= t2->next;
        head->next = cool;
        t2->next = temp;
        temp->next=NULL;
        return head;
    }else if(i==0){
        Node *temp=t2->next->next;
        head = t2->next;
        head->next= cool;
        t1->next = temp;
        t2->next = t1;
        return head;
    }else if(t2->next->next==NULL){
        Node* temp = t1->next->next;
        Node* temp2 = t1->next;
        t1->next = t2->next;
        t1->next->next = temp;
        t2->next = temp2;
        temp2->next=NULL;
        return head;
    }else{
        Node *temp1 = t1->next->next;
        Node *temp2 = t2->next->next;
        Node* temp = t1->next;
        t1->next = t2->next;
        t2->next->next = temp1;
        t2->next = temp;
        temp->next = temp2;
        return head;
    }   
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}