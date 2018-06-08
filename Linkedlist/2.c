#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node* next;
};
void push(struct node** head,int num)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data=num;

    new_node->next= (*head);
    (*head) = new_node;

}
void show(struct node *head)
{
    while(head!=NULL)
    {
        printf(" %d ",head->data);
        head=head->next;
    }
}
int main()
{
    struct node* head=NULL;
    push(&head,4);
    push(&head,9);
    show(head);
    return 0;
}
