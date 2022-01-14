#include <iostream>
#include <queue>
#include <stack>
template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL){
        return;
    }
    stack<BinaryTreeNode<int> *> s1;
    stack<BinaryTreeNode<int> *> s2;
    s1.push(root);
    while(!s1.empty() | !s2.empty()){
        if(!s1.empty()){
            while(!s1.empty()){
                BinaryTreeNode<int> * ele = s1.top();
                s1.pop();
                cout<<ele->data<<" ";
                if(ele->left != NULL){
                    s2.push(ele->left);
                }
                if(ele->right != NULL){
                    s2.push(ele->right);
                }
            }
            cout<<endl;
        }else{
            while(!s2.empty()){
                BinaryTreeNode<int> * ele = s2.top();
                s2.pop();
                cout<<ele->data<<" ";
                if(ele->right != NULL){
                    s1.push(ele->right);
                }
                if(ele->left != NULL){
                    s1.push(ele->left);
                }
            }
            cout<<endl;
        }
    }
    
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
}