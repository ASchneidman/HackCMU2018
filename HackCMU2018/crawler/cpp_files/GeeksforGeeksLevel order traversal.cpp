<<<<<<< HEAD
//You are required to complete this method
void levelOrder(struct Node* node)
{
 //Your code here
    queue<Node*>q;
    queue<Node*>ans;
    q.push(node);
    while(true){
        int noOfNodes=q.size();
        if(noOfNodes==0)
            break;
        while(noOfNodes){
            Node *cur=q.front();
            q.pop();
            ans.push(cur);
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
            noOfNodes--;
        }
        ans.push(NULL);

    }
    while(ans.size()){
        node=ans.front();
        if(node==NULL)
            cout<<"$ ";
        else
            cout<<node->data<<" ";
        ans.pop();
    }
}


=======
//You are required to complete this method
void levelOrder(struct Node* node)
{
 //Your code here
    queue<Node*>q;
    queue<Node*>ans;
    q.push(node);
    while(true){
        int noOfNodes=q.size();
        if(noOfNodes==0)
            break;
        while(noOfNodes){
            Node *cur=q.front();
            q.pop();
            ans.push(cur);
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
            noOfNodes--;
        }
        ans.push(NULL);

    }
    while(ans.size()){
        node=ans.front();
        if(node==NULL)
            cout<<"$ ";
        else
            cout<<node->data<<" ";
        ans.pop();
    }
}


>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
