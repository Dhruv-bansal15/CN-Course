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

    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};

using namespace std;

BinaryTreeNode<int>* takeInput() {
    int rootData;
    
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
        
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
void printkdistanceNodeDown(BinaryTreeNode<int> *root, int k){
    if (root== NULL | k<0)  return;
    if (k==0){
        cout << root->data << endl;
        return;
    }
    printkdistanceNodeDown(root->left, k-1);
    printkdistanceNodeDown(root->right, k-1);
}

BinaryTreeNode<int>* helper(BinaryTreeNode<int> *root, int k){
    if(root==NULL){
        return NULL;
    }else if(root->data== k){
        return root;
    }
    BinaryTreeNode<int> *small1 = helper(root->left,k);
    if(small1 != NULL){
        return small1;
    }else{
        BinaryTreeNode<int> * small2 = helper(root->right,k);
        return small2;
    }
    
}
int helper2(BinaryTreeNode<int> *root,BinaryTreeNode<int> *target, int k){
    if (root == NULL)
        return -1;
    if (root == target){
        printkdistanceNodeDown(root, k);
        return 0;
    }
 
    int dl = helper2(root->left, target, k);
 
    if (dl != -1)
    {
         if (dl + 1 == k)
            cout << root->data << endl;
         else
            printkdistanceNodeDown(root->right, k-dl-2);
         return 1 + dl;
    }

    int dr = helper2(root->right, target, k);
    if (dr != -1)
    {
         if (dr + 1 == k)
            cout << root->data << endl;
         else
            printkdistanceNodeDown(root->left, k-dr-2);
         return 1 + dr;
    }
    return -1;
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code here
    if(root==NULL){
        return;
    }
    BinaryTreeNode<int> * currNode = helper(root, node);
    int ans = helper2(root,currNode, k);
    return;
    
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}