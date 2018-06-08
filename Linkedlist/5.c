#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node* next;
};
int main()
{
    struct node* head=NULL;
    push(&head,7);
    push(&head,6);
    push(&head,8);
     delete_node(&head,6);
    show(head);
    return 0;
}
void push(struct node** head,int num)
{
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=num;
    new_node->next=(*head);
    (*head)=new_node;
}
void show(struct node* node)
{
    while(node!=NULL)
    {
        printf(" %d ",node->data);
        node = node->next;
    }
}
void delete_node(struct node** head,int key)
{
    struct node* temp = *head;
    struct node* prev;
    if(temp!=NULL && temp->data==key)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=key)
    {
        prev = temp;
        temp=temp->next;
    }
    if(temp==NULL)
        return;
    prev->next=temp->next;
    free(temp);
}
