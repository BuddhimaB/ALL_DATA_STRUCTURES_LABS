#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;

  node(int val){
      key=val;
      this->left= NULL;
      this-> right= NULL;

  }
};

// Inorder traversal
void traverseInOrder(struct node *root) {

    if(root== nullptr)
        return;
    traverseInOrder(root -> left);
    cout<< root->key<<" ";
    traverseInOrder(root-> right);
}

// Insert a node
struct node* insertNode(struct node* node, int key) {


    if(node==NULL) // check whether the node is null
        {
        return new struct node(key);}   // if the root is null then the new node is added to the node created
    if (key > node->key) {                  // if the key is greater than root node,
        node->right= insertNode(node->right,key);// key(value) is inserted to the right
    }
    else {                                 // if the key is less than or equal root node,
        node->left= insertNode(node->left,key);// key(value) is inserted to the right
    }
    return node;


}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {

 if(root==nullptr){

     cout<<"Tree is empty"<<endl;
     return root;
 }
 if(root->key<key){
     root->right= deleteNode(root->right,key);
 }
 else if(root->key>key){
     root->left= deleteNode(root->left,key);
 }
 else{
     if(root->right==NULL){
         struct node* temp= root->left;
         free(root);
         return temp;
     }
     else if(root->left==NULL){
         struct node* temp= root->right;
         free(root);
         return temp;
     }
     else{
         struct node* temp=root->right;
         while(temp->left != NULL)
             temp=temp->left;
         root->key=temp->key;
         root->right= deleteNode(root->right,temp->key);
     }
 }
    return root;
}

// Driver code
int main() {
  struct node* root=NULL;


  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }

  traverseInOrder(root);
  return 0;
}