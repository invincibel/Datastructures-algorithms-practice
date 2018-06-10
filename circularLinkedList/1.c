#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node* next;
};
int main()
{
    struct node* last = NULL;
    push(&last,6);
}
void push(struct node** last,int num)
{
  if(*last==NULL)
     addToBegin(&last,num);

}
