<<<<<<< HEAD
/* Link list Node
struct Node {
    int data;
    struct Node* next;
}; */


/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(struct Node* head1, struct Node* head2)
{
    // Your Code Here
    int length1=0,length2=0;
    struct Node *head=head1;
    while(head!=NULL){
        length1++;
        head=head->next;
    }
    head=head2;
    while(head!=NULL){
        length2++;
        head=head->next;
    }
    int dif=abs(length1-length2);
    if(length1>=length2){
        while(dif--)
            head1=head1->next;
    }
    else
        while(dif--)
            head2=head2->next;
    while(head1!=head2 and head1 and head2){
        head1=head1->next;
        head2=head2->next;
    }
    if(!head1 or !head2)
        return -1;
    return head1->data;
}
=======
/* Link list Node
struct Node {
    int data;
    struct Node* next;
}; */


/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(struct Node* head1, struct Node* head2)
{
    // Your Code Here
    int length1=0,length2=0;
    struct Node *head=head1;
    while(head!=NULL){
        length1++;
        head=head->next;
    }
    head=head2;
    while(head!=NULL){
        length2++;
        head=head->next;
    }
    int dif=abs(length1-length2);
    if(length1>=length2){
        while(dif--)
            head1=head1->next;
    }
    else
        while(dif--)
            head2=head2->next;
    while(head1!=head2 and head1 and head2){
        head1=head1->next;
        head2=head2->next;
    }
    if(!head1 or !head2)
        return -1;
    return head1->data;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
