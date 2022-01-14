#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

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

BinaryTreeNode<int> *takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}
int sumNodes(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return (root->data + sumNodes(root->left) + sumNodes(root->right));
}
void helper(BinaryTreeNode<int>* root, int* total){
    if(root==NULL){
        return;
    }
    helper(root->right, total);
    *total = *total + root->data;
    // int temp = root->data;
    root->data = *total;
    helper(root->left, total);
    return;
}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    // Write your code here
    int hihi=0;
    helper(root,&hihi);
    return;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    replaceWithLargerNodesSum(root);
    printLevelATNewLine(root);
    delete root;
}