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
    push(&head,8);
    push(&head,9);
    append(head,6);
    show(head);
    return 0;
}
void push(struct node** head,int num )
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* last = *head;
    new_node->data=num;
    new_node->next=NULL;
    if(*head==NULL)
    {
        *head=new_node;
        return;
    }
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next= new_node;
    return;
}
void show(struct node* node){
 while(node!=NULL){
    printf(" %d ",node->data);
    node = node->next;
 }
}
void append(struct node* prev,int num)
{
 struct node* nxt=NULL;
 if(prev==NULL)
        return;
 struct node* new_node= (struct node*)malloc(sizeof(struct node));
 new_node->data = num;
 nxt=prev->next;
 prev->next=new_node;
 new_node->next=nxt;
}




