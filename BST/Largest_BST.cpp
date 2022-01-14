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
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
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
class ds{
public:
    int minimum;
    int maximum;
    bool isBST;
    int height;
};

ds helper(BinaryTreeNode<int>* root){
    if(root==NULL){
        ds output;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        output.isBST = true;
        output.height = 0;
        return output;
    }else if(root->left==NULL & root->right==NULL){
        ds output;
        output.minimum = root->data;
        output.maximum = root->data;
        output.isBST = true;
        output.height = 1;
        return output;
    }
    ds small1 = helper(root->left);
    ds small2 = helper(root->right);
    if(small1.isBST == true & small2.isBST == true){
        if(root->data > small1.maximum & root->data < small2.minimum){
            ds output;
        	output.minimum = min(small1.minimum,root->data);
        	output.maximum = max(small2.maximum,root->data);
        	output.isBST = true;
        	output.height = max(small1.height,small2.height)+1;
        	return output;
        }else{
            ds output;
        	output.minimum = min(small1.minimum,root->data);
        	output.maximum = max(small2.maximum,root->data);
        	output.isBST = false;
        	output.height = max(small1.height,small2.height);
        	return output;
        }
    }else if(small1.isBST==true){
        ds output;
        output.minimum = min(small1.minimum,min(small2.minimum,root->data));
        output.maximum = max(small2.maximum,max(small1.maximum, root->data));
        output.isBST = false;
        output.height = max(small2.height,small1.height);
        return output;
    }else if(small2.isBST==true){
        ds output;
        output.minimum = min(small1.minimum,min(small2.minimum,root->data));
        output.maximum = max(small2.maximum,max(small1.maximum, root->data));
        output.isBST = false;
        output.height = max(small2.height,small1.height);
        return output;
    }else{
        ds output;
        output.minimum = root->data;
        output.maximum = root->data;
        output.isBST = false;
        output.height = max(1, max(small1.height,small2.height));
        return output;
    }
}
int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL){
        return 0;
    }
    ds ans = helper(root);
    return ans.height;
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}