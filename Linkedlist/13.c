#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node* next;
};
int main()
{
    struct node* head = NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);
    push(&head,6);
    show(head);
    rotateList(&head,2);
    show(head);
    return 0;
}
void push(struct node** head,int num)
{
    struct node* pt = *head;
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    if(*head==NULL)
    {
        *head = new_node;
        return;
    }
    while(pt->next!=NULL)
        pt = pt->next;
    pt->next = new_node;
}
void show(struct node* node)
{
    while(node!=NULL)
    {
        printf(" %d ",node->data);
        node = node->next;
    }
    printf("\n");
}
void rotateList(struct node** head,int pos)
{
    int i=0;
    struct node* curr = *head;
    while(i<pos && curr!=NULL)
    {
       curr= curr->next;
       i++;
    }
    struct node* front = curr;
    while(front->next!=NULL)
        front = front->next;
    front->next = *head;
    *head = curr->next;
    curr->next = NULL;

}
