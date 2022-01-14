#include <iostream>
#include <queue>

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
class triplet{
public:
    bool ifyes;
    int minimum;
    int maximum;
};
triplet isBST2(BinaryTreeNode<int> *root){
    if(root==NULL){
        triplet output;
        output.ifyes=true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }
    triplet left = isBST2(root->left);
    triplet right = isBST2(root->right);
    int mini = min(root->data, min(left.minimum, right.minimum));
    int maxi = max(root->data, max(left.maximum, right.maximum));
    bool isBSTfinal = (root->data > left.maximum) & (root->data <= right.minimum) & (left.ifyes) & (right.ifyes);
    triplet output;
    output.minimum = mini;
    output.maximum = maxi;
    output.ifyes = isBSTfinal;
    return output;
}
bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root==NULL){
        return true;
    }
    triplet x = isBST2(root);
    return x.ifyes;
    
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBST(root) ? "true" : "false");
}