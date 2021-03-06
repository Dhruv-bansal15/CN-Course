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
Node *removeDuplicates(Node *head)
{
    //Write your code here
    if(head==NULL){
        return head;
    }
    Node*temp = head;
    while(temp->next!=NULL){
        if(temp-> data == temp->next->data){
            Node* temp2 = temp;
            while(temp2->data==temp->data & temp2!= NULL){
                temp2 = temp2->next;
            }
            temp->next = temp2;
        }
        temp = temp->next;
        if(temp==NULL){
            return head;
        }
    }
    return head;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = removeDuplicates(head);
		print(head);
	}
	return 0;
}