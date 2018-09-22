<<<<<<< HEAD
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    struct Node* left, * right;
}; */
/* Should return true if tree represented by root is BST.
   For example, return  value should be true for following tree.
         20
     /      \
   10       30
  and return value should be false for following tree.
         10
     /      \
   20       30 */
bool checkBST(struct Node *root,int min,int max){
    if(root==NULL)
        return true;
    if(root->data<min or root->data>max){
        return false;
    }
    return checkBST(root->left,min,root->data-1) and checkBST(root->right,root->data+1,max);
}
bool isBST(struct Node* root) {

    // Your code here
    return checkBST(root,INT_MIN,INT_MAX);

}
=======
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    struct Node* left, * right;
}; */
/* Should return true if tree represented by root is BST.
   For example, return  value should be true for following tree.
         20
     /      \
   10       30
  and return value should be false for following tree.
         10
     /      \
   20       30 */
bool checkBST(struct Node *root,int min,int max){
    if(root==NULL)
        return true;
    if(root->data<min or root->data>max){
        return false;
    }
    return checkBST(root->left,min,root->data-1) and checkBST(root->right,root->data+1,max);
}
bool isBST(struct Node* root) {

    // Your code here
    return checkBST(root,INT_MIN,INT_MAX);

}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
