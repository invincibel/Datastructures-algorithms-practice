#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node* next;
};
struct node* push(struct node* last,int num)
{
   if(last==NULL)
        return addToBegin(last,num);
}
int main()
{
    struct node* last = NULL;
    last = push(last,5);
    show(last);
    return 0;
}
void show(struct node* last)
{
   struct node* p;
   if(last==NULL)
        return;
   p = last->next;
   do{
    printf(" %d ",p->data);
    p = p->next;
   }while(p!=last->next);
}
void addToBegin(struct node* last,int num)
{
    if(last!=NULL)
        return;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = num;
    last = temp;
    temp->next = last;
}

