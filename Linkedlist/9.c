#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node* next;
};
int main()
{
    struct node* head1=NULL;
    struct node* head2=NULL;
    struct node* head3=NULL;
    push(&head1,9);
    push(&head1,5);
    push(&head1,2);
    push(&head2,8);
    push(&head2,4);
    push(&head2,3);
    show(head1);
    printf("\n");
    show(head2);
    printf("\n");
    mergeSortedList(&head3,head1,head2);
   show(head3);
    return 0;
}
void push(struct node** head,int num)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data=num;
    new_node->next=(*head);
    *head = new_node;
}
void show(struct node* node)
{
    while(node!=NULL)
    {
        printf(" %d ",node->data);
        node = node->next;
    }
}
void mergeSortedList(struct node** head,struct node* head1,struct node* head2)
{
    struct node* curr = *head;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1==NULL)
        {
            push(&curr,head2->data);
               head2 = head2->next;
        }
        else if(head2==NULL)
        {
            push(&curr,head1->data);
             head1 = head1->next;
        }
        if(head1->data>head2->data)
           {
               push(&curr,head2->data);
              head2=head2->next;
           }
        else if(head2->data>head1->data){
            push(&curr,head1->data);
            head1 = head1->next;
        }
        else{
                push(&curr,head1->data);
        head1 = head1->next;
        head2 = head2->next;
        }
    }
    show(curr);
}
