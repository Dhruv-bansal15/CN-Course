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
void helper(BinaryTreeNode<int>* curr_node, int sum,int sum_so_far, vector<int> &path){
    if (curr_node == NULL)
        return;

    sum_so_far += curr_node->data;
 
    path.push_back(curr_node->data);
 
    if (sum_so_far == sum ){
        for (int i=0; i<path.size(); i++)
            cout << path[i] << " ";
        cout << endl;
    }
 
    if (curr_node->left != NULL)
        helper(curr_node->left, sum, sum_so_far, path);
 
    if (curr_node->right != NULL)
        helper(curr_node->right, sum, sum_so_far, path);
    
    path.pop_back();
    return;
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    vector<int> path;
    helper(root, k, 0, path);
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    int k;
    cin >> k;
    rootToLeafPathsSumToK(root, k);
    delete root;
}