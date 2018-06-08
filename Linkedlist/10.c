#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node* next;
};
int main()
{
    struct node* head = NULL;
    push(&head,8);
    push(&head,9);
    push(&head,6);
    push(&head,5);
    push(&head,3);
    show(head);
    printf("\n");
    change(&head,3);
    show(head);
}
void push(struct node** head,int num)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = num;
    new_node->next = *head;
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
void change(struct node** head,int pos)
{
    int i;
    struct node *prev = NULL;
    struct node* curr = *head;
    struct node* next = NULL;
    for(i=0;i<pos;i++)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr=next;
    }
    *head = prev;
}
