#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node* next;
};
int main()
{
    struct node* last = NULL;
    addToBegin(&last,6);
    show(last);
    return 0;
}
void addToBegin(struct node** last,int num)
{
    if(*last!=NULL)
        return;
        struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = num;
     *last = temp;
     temp->next = *last;
}
void show(struct node* last)
{
    struct node* p =NULL;
    if(last==NULL)
        {printf("list is empty\n");
        return;
        }
        p = last->next;
        do{
            printf(" %d ",p->data);
            p = p->next;
        }while(p!=p->next);

}
