<<<<<<< HEAD
/* The structure of a BST node is as follows:
struct node
{
    int data;
    struct node * right, * left;
}; */

void printNearNodes(node *root, int l, int h)
{
  // your code goes here
  if(!root)
    return ;

  int d=root->data;
  //cout<<d<<" "<<l<<" "<<h<<endl;
  if(d>l){
      printNearNodes(root->left,l,h);
  }
  if(d>=l and d<=h){
      cout<<d<<" ";
      //printNearNodes(root->left,l,d-1);
      //printNearNodes(root->right,d+1,h);
  }
  if(d<h){
      printNearNodes(root->right,l,h);
  }


}
=======
/* The structure of a BST node is as follows:
struct node
{
    int data;
    struct node * right, * left;
}; */

void printNearNodes(node *root, int l, int h)
{
  // your code goes here
  if(!root)
    return ;

  int d=root->data;
  //cout<<d<<" "<<l<<" "<<h<<endl;
  if(d>l){
      printNearNodes(root->left,l,h);
  }
  if(d>=l and d<=h){
      cout<<d<<" ";
      //printNearNodes(root->left,l,d-1);
      //printNearNodes(root->right,d+1,h);
  }
  if(d<h){
      printNearNodes(root->right,l,h);
  }


}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
