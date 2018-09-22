<<<<<<< HEAD
/* node structure  used in the program
 struct Node
 {
     int data;
     struct node* left, *right;
}; */

/*  Function which returns the  root of
    the constructed binary tree. */
void makeTreeNode(Node **root,int i,int parent[],Node *created[]){
    if(created[i]!=NULL)
        return ;
    created[i]=newNode(i);
    if(parent[i]==-1){
        *root=created[i];
        return ;
    }

    if(created[parent[i]]==NULL)
        makeTreeNode(root,parent[i],parent,created);

    Node *parentNode=created[parent[i]];
    if(parentNode->left==NULL)
        parentNode->left=created[i];
    else
        parentNode->right=created[i];

}
Node *createTree(int parent[], int n)
{
// Your code here
    Node *created[n];
    for(int i=0;i<n;++i)
        created[i]=NULL;
    Node *root=NULL;
    for(int i=0;i<n;++i){
        makeTreeNode(&root,i,parent,created);
    }
    return root;

}
=======
/* node structure  used in the program
 struct Node
 {
     int data;
     struct node* left, *right;
}; */

/*  Function which returns the  root of
    the constructed binary tree. */
void makeTreeNode(Node **root,int i,int parent[],Node *created[]){
    if(created[i]!=NULL)
        return ;
    created[i]=newNode(i);
    if(parent[i]==-1){
        *root=created[i];
        return ;
    }

    if(created[parent[i]]==NULL)
        makeTreeNode(root,parent[i],parent,created);

    Node *parentNode=created[parent[i]];
    if(parentNode->left==NULL)
        parentNode->left=created[i];
    else
        parentNode->right=created[i];

}
Node *createTree(int parent[], int n)
{
// Your code here
    Node *created[n];
    for(int i=0;i<n;++i)
        created[i]=NULL;
    Node *root=NULL;
    for(int i=0;i<n;++i){
        makeTreeNode(&root,i,parent,created);
    }
    return root;

}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
