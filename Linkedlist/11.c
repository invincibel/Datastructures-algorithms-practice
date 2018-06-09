#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node* next;
};
struct node *newNode(int key)
{
   struct node* new_node = (struct node*)malloc(sizeof(struct node));
   new_node->data=key;
   new_node->next = NULL;
   return new_node;
}
int main()
{
    struct node* head=NULL;
    head = newNode(20);
    head->next = newNode(10);
    head->next->next = newNode(5);
    head->next->next->next = newNode(6);
    head->next->next->next->next = newNode(4);
    head->next->next->next->next->next = newNode(80);
    head->next->next->next->next->next->next = head->next->next;
    detectLoop(head);
    show(head);
    return 0;
}
void detectLoop(struct node* head)
{
    struct node* slow_p = head;
    struct node* fast_p = head;
    while(slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p=fast_p->next->next;
        if(slow_p == fast_p)
        {
            removeLoop(slow_p,head);
            return;
        }
    }
    printf("NO loop found");
}
void removeLoop(struct node* ptr,struct node* head)
{
    struct node* pt = head;
    struct node* pt2;
    while(1)
    {
        pt2 = ptr;
        while(pt2->next!=ptr && pt2->next!=pt)
            pt2 = pt2->next;
        if(pt2->next==pt)
            break;
        pt = pt->next;
    }
    pt2->next = NULL;
}
void show(struct node* node)
{
    while(node!=NULL)
    {
        printf(" %d ",node->data);
        node = node->next;
    }
}
