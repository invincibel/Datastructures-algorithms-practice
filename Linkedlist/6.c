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
    delete_node(&head,1);
    show(head);
    return 0;
}
void push(struct node** head,int num)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* nxt = *head;
    new_node->data= num;
     new_node->next=NULL;
    if(*head==NULL)
    {
        *head = new_node;
        return;
    }

    while(nxt->next!=NULL)
         nxt=nxt->next;

        nxt->next=new_node;
}
void show(struct node* node)
{
    while(node!=NULL)
    {
        printf(" %d ",node->data);
        node = node->next;
    }
}
void delete_node(struct node** head,int pos)
{
   if(*head==NULL)
        return;
   struct node* temp = *head;
   if(pos==0)
   {
       *head = temp->next;
       free(temp);
       return;
   }
   int i;
   for(i=0;temp!=NULL && i<pos-1;i++)
    temp=temp->next;

   if(temp==NULL || temp->next==NULL)
      return;
   struct node* nxt = temp->next->next;
   free(temp->next);
   temp->next = nxt;
}




