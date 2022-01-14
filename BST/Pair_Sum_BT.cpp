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
vector<int> arr;
void fillvector(BinaryTreeNode<int> *root){
    if(root==NULL){
        return;
    }
    fillvector(root->left);
    fillvector(root->right);
    arr.push_back(root->data);
    return;
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    if(root==NULL){
        return;
    }
    
    fillvector(root);
    sort(arr.begin(),arr.end());
    int i=0,j=arr.size()-1;
    while(i<j){
        if(arr[i]+arr[j] > sum){
            j--;
        }else if(arr[i]+arr[j]<sum){
            i++;
        }else{
            cout<<arr[i]<<" "<<arr[j]<<endl;
            i++,j--;
        }
    }
    return;
    
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}