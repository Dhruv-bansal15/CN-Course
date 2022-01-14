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
int length(Node *head)
{
    //Write your code here
    if(head==NULL){
        return 0;
    }
    int cnt=1;
    Node *temp = head;
    while(temp-> next != NULL){
        temp = temp-> next;
        cnt++;
    }
    return cnt;
}
Node *appendLastNToFirst(Node *head, int n)
{
    if(head==NULL | n==0){
        return head;
    }
    int len = length(head);
    if(n==len){
        return head;
    }
    Node* temp = head;
    int j = len-n;
    int cnt=0;
    while(cnt<j-1){
        temp = temp-> next;
        cnt++;
    }
    Node* temp3 = temp->next;
    Node* temp2 = temp->next;
    temp->next = NULL;
    while(temp2->next!=NULL){
        temp2 = temp2->next;
    }
    temp2->next = head;
    head= temp3;
    return head;
    
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}