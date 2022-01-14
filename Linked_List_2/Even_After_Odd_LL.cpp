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
Node *evenAfterOdd(Node *head)
{
	//write your code here
    if(head==NULL){
        return head;
    }else if(head->next==NULL){
        return head;
    }
    
    Node* ehead=NULL;
    Node* etail=NULL;
    Node* ohead=NULL;
    Node* otail=NULL;
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data %2 == 0){
            if(ehead==NULL){
                ehead=temp,etail=temp;
            }else{
                etail->next=temp;
                etail=temp;
            }
        }else{
            if(ohead==NULL){
                ohead=temp,otail=temp;
            }else{
                otail->next=temp;
                otail=temp;
            }
        }
        temp= temp->next;
    }
    if(otail!=NULL){
        otail->next = ehead;
        return ohead;
    }else{
        return ehead;
    }
    
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}