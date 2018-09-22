<<<<<<< HEAD
/* struct Node
{
  int data;
  struct Node *left,  *right;
  struct Node *nextRight;  // This has garbage value in input trees
}; */
struct Node *getNextRight(struct Node *root){
    struct Node *temp=root->nextRight;
    while(temp!=NULL){
        if(temp->left)
            return temp->left;
        if(temp->right)
            return temp->right;
        temp=temp->nextRight;
    }
    return NULL;
}
void connectMore(struct Node *root){
    if(root==NULL)
        return;
    if(root->nextRight)
        connectMore(root->nextRight);
    if(root->left){
        if(root->right){
            root->left->nextRight=root->right;
            root->right->nextRight=getNextRight(root);
        }
        else
            root->left->nextRight=getNextRight(root);
        connectMore(root->left);
    }
    else if (root->right){
        root->right->nextRight=getNextRight(root);
        connectMore(root->right);
    }
    else
        connectMore(getNextRight(root));

}

// Should set the nextRight for all nodes
void connect(struct Node *p)
{
    p->nextRight=NULL;

    connectMore(p);
   // Your Code Here
}


=======
/* struct Node
{
  int data;
  struct Node *left,  *right;
  struct Node *nextRight;  // This has garbage value in input trees
}; */
struct Node *getNextRight(struct Node *root){
    struct Node *temp=root->nextRight;
    while(temp!=NULL){
        if(temp->left)
            return temp->left;
        if(temp->right)
            return temp->right;
        temp=temp->nextRight;
    }
    return NULL;
}
void connectMore(struct Node *root){
    if(root==NULL)
        return;
    if(root->nextRight)
        connectMore(root->nextRight);
    if(root->left){
        if(root->right){
            root->left->nextRight=root->right;
            root->right->nextRight=getNextRight(root);
        }
        else
            root->left->nextRight=getNextRight(root);
        connectMore(root->left);
    }
    else if (root->right){
        root->right->nextRight=getNextRight(root);
        connectMore(root->right);
    }
    else
        connectMore(getNextRight(root));

}

// Should set the nextRight for all nodes
void connect(struct Node *p)
{
    p->nextRight=NULL;

    connectMore(p);
   // Your Code Here
}


>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
