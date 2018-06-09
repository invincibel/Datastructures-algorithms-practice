#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node* next;
};
int main()
{
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    push(&head1,5);
    push(&head1,4);
    push(&head2,3);
    push(&head2,6);
    show(head1);
    show(head2);
    addNum(head1,head2);

    return 0;
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
    printf("\n");
}
void opposite(struct node** head)
{
    struct node* prev = NULL;
    struct node* curr = *head;
    struct node* next = NULL;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
  *head = prev;
}
void addNum(struct node* node1,struct node* node2)
{
    struct node* head3 = NULL;
    int a;
    int count = 0;
    while(node1!=NULL && node2!=NULL)
    {
        if(count==0)
        {
            a = node1->data+node2->data;
            count = a/10;
            a=a%10;
            push(&head3,a);
        }
        else{
            a = node1->data+node2->data+count;
            count = a/10;
            a= a%10;
            push(&head3,a);
        }


        node1 = node1->next;
        node2=  node2->next;
    }
   opposite(&head3);
    show(head3);
}
