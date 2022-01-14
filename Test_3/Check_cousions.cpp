#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
		queue<BinaryTreeNode<int>*> q;
		q.push(root);
		q.push(NULL);
		while(!q.empty()) {
			BinaryTreeNode<int> *first = q.front();
			q.pop();
			if(first == NULL) {
				if(q.empty()) {
					break;
				}
				cout << endl;
				q.push(NULL);
				continue;
			}
			cout << first -> data << " ";
			if(first -> left != NULL) {
				q.push(first -> left);
			}
			if(first -> right != NULL) {
				q.push(first -> right);
			}
		}
}
int level(BinaryTreeNode<int> *root, BinaryTreeNode<int> *ptr, int lev)
{
    // base cases
    if (root == NULL) return 0;
    if (root == ptr)  return lev;
 
    // Return level if Node is present in left subtree
    int l = level(root->left, ptr, lev+1);
    if (l != 0)  return l;
 
    // Else search in right subtree
    return level(root->right, ptr, lev+1);
}

int isSibling(BinaryTreeNode<int> *root, BinaryTreeNode<int> *a, BinaryTreeNode<int> *b)
{
    // Base case
    if (root==NULL)  return 0;
 
    return ((root->left==a && root->right==b)||
            (root->left==b && root->right==a)||
            isSibling(root->left, a, b)||
            isSibling(root->right, a, b));
}
BinaryTreeNode<int>* find(BinaryTreeNode<int> *root, int a){
    if(root==NULL){
        return NULL;
    }else if(root->data==a){
        return root;
    }
    BinaryTreeNode<int> *small1 = find(root->left,a);
    if(small1!=NULL){
        return small1;
    }else{
        BinaryTreeNode<int> *small2 = find(root->right,a);
        return small2;
    }
}
bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    // Write your code here
    if(root==NULL){
        return true;
    }
    BinaryTreeNode<int> *node1 = find(root,p);
    BinaryTreeNode<int> *node2 = find(root,q);
    if ((level(root,node1,1) == level(root,node2,1)) && !(isSibling(root,node1,node2)))
        return true;
    else return false;
    

}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    int n1, n2;
    cin >> n1 >> n2;
    if(isCousin(root, n1, n2)) {
	    cout << "true" << endl;
    }
    else {
	    cout << "false" << endl;
    }
}
