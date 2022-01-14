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
Node *skipMdeleteN(Node *head, int M, int N)
{
	// Write your code here
    if(M==0 & N==0){
        return NULL;
    }else if(M==0){
        return NULL;
    }else if(N==0){
        return head;
    }
    
    Node *curr = head, *t;
    int count;
    while (curr)
    {
        for (count = 1; count < M && curr!= NULL; count++)
            curr = curr->next;
        if (curr == NULL)
            return head;
        t = curr->next;
        for (count = 1; count<=N && t!= NULL; count++)
        {
            Node *temp = t;
            t = t->next;
            free(temp);
        }
        curr->next = t;
        curr = t;
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
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}