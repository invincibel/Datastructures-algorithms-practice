#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node* next;
};
int main()
{
    struct node* head = NULL;

    push(&head,4);
    push(&head,5);
    push(&head,6);
    push(&head,7);
     swap(&head,6,5);
    show(head);
}
void push(struct node** head,int num)
{
   struct node* new_node = (struct node*)malloc(sizeof(struct node));
   new_node->data = num;
   new_node->next = NULL;
   new_node->next= (*head);
   (*head) = new_node;
}
void show(struct node* node)
{
    while(node!=NULL)
    {
        printf(" %d ",node->data);
        node= node->next;
    }
}
void swap(struct node** head,int x,int y)
{
    if(x==y)
        return;
    struct node* temp = *head;
    while(temp!=NULL)
    {
        if(temp->data==x)
            temp->data = y;
       else if(temp->data==y)
            temp->data = x;
        temp = temp->next;
    }
}
