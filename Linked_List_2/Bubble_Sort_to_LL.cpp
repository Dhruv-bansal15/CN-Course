//bubble sort iterative
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

Node *bubbleSort(Node *head)
{
    if(head==NULL){
        return head;
    }else if(head->next==NULL){
        return head;
    }
    Node* prev=NULL;
    Node* curr= head;
    Node* nex = head->next;
    while(curr!=NULL){
        curr->next = prev;
        prev=curr;
        curr=nex;
        if(curr==NULL){
            break;
        }
        nex= nex->next;
    }
    return prev;

}

int main()
{
	Node *head = takeinput();
	head = bubbleSort(head);
	print(head);
}