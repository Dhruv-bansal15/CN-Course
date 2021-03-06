#include <iostream>
#include <vector>
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
vector<int>* helper(BinaryTreeNode<int>* root, vector<int>* v){
    if(root==NULL){
        return v;
    }
    
}
vector<int>* longestPath(BinaryTreeNode<int>* root) {
	// Write your code here
    if(root==NULL){
        vector<int>* v = new vector<int>();
        return v;
    }
    vector<int>* rightvect
        = longestPath(root->right);
 
    // Recursive call on root->left
    vector<int>* leftvect
        = longestPath(root->left);
 
    // Compare the size of the two vectors
    // and insert current node accordingly
    if (leftvect->size() > rightvect->size())
        leftvect->push_back(root->data);
 
    else
        rightvect->push_back(root->data);
 
    // Return the appropriate vector
    return (leftvect->size() > rightvect->size()
                ? leftvect
                : rightvect);

}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    vector<int> *output = longestPath(root);
    vector<int> :: iterator i = output -> begin();
    while(i != output -> end()) {
    	cout << *i << endl;
    	i++;
    }
}
