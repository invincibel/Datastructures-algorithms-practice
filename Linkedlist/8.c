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
    show(head);
    printf("\n");
    reverse(&head);
    show(head);
    return 0;
}
void push(struct node** head,int num)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    new_node->next = (*head);
    (*head) = new_node;
}
void show(struct node* node)
{
    while(node!=NULL)
    {
        printf(" %d ",node->data);
        node = node->next;
    }
}
void reverse(struct node** start)
{
    struct node* prev =NULL;
    struct node* curr= *start;
    struct node* next = NULL;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev=curr;
        curr=next;
    }
    *start = prev;
}
