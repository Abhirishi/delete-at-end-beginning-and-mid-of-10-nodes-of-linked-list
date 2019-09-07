#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
   int data;
   struct node* next;

};
void print(struct node *head);
struct node* deletel(struct node *head);
struct node* deletef(struct node *head);
struct node* deletem(struct node *head);
void print(struct node *head){

struct node *ptr=head;
while(ptr)
{
    printf("%d  ",ptr->data);
    ptr=ptr->next;

}
printf("\n");
}
struct node* deletel(struct node *head)
{
    struct node *ptr1,*ptr=head;

      while(ptr->next)
      {
         ptr1=ptr;
         ptr=ptr->next;
      }

    ptr1->next=NULL;
    free(ptr);
    return head;
}
struct node* deletef(struct node *head)
{
    struct node *ptr;
     if(head&&head->next)
      {
        ptr=head->next;
         free(head);
         head=ptr;
      }
      return head;

}
struct node *deletem(struct node *head)
{
    struct node *ptr1,*ptr2,*pre1;
    ptr1=head;
    ptr2=ptr1;
    while(ptr2->next)
    {
        ptr2=ptr2->next;
        if(ptr2->next)
        {
            pre1=ptr1;
            ptr2=ptr2->next;
            ptr1=ptr1->next;


        }
    }
    pre1->next=ptr1->next;
    free(ptr1);
    return head;

};
int main()
{
    struct node *head,*ptr1,*ptr2;
    int n=9,d;

    head=(struct node*)malloc(sizeof(struct node*));
    scanf("%d",&d);
      head->data=d;
          ptr1=head;
    while(n--)

    {
       scanf("%d",&d);
        ptr2=(struct node*)malloc(sizeof(struct node*));
       ptr1->next=ptr2;
       ptr2->next=NULL;
       ptr2->data=d;
       ptr1=ptr2;
    }
    print(head);
    head=deletel(head);
    print(head);
    head=deletef(head);
    print(head);
    head=deletem(head);
    print(head);
    return 0;
}
