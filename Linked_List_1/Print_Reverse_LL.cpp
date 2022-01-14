#include <iostream>
#include <bits/stdc++.h> 
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
void printReverse(Node *head)
{
    if(head==NULL){
        return;
    }
    //Write your code here
    vector<int> arr;
    while(head->next!=NULL){
        arr.push_back(head->data);
        head = head->next;
    }
    arr.push_back(head->data);
    int n = arr.size();
    for(int i=n-1;i>=0;i--){
        cout<<arr[i]<<" ";
    }
    return;
    
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		printReverse(head);
		cout << endl;
	}
	return 0;
}