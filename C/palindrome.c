#include<stdio.h>
#include<malloc.h>

struct node
{
  int data;
  struct node *next;
};

struct node *start=NULL;
struct node * create_ll(struct node *);
struct node * display(struct node *);
struct node * palin(struct node *);

void main()
{
 int option;

 do
 {
        printf("\n**MAIN MENU");
        printf("\n 1. Add node in link list : ");
        printf("\n 2. Display link list : ");
        printf("\n 3. Check palindrome : ");
        printf("\n 4. Exit");
        printf("\n Enter your option : ");
        scanf("%d",&option);

        switch(option)
        {

           case 1:

               start=create_ll(start);
               printf("\n link list created");
               break;


           case 2:

               start=display(start);

               break;

           case 3:
               start=palin(start);
               break;

        }

    }while(option !=4);

}

struct node * create_ll(struct node *start)
{

      struct node *new_node,*ptr;
      int num;
      printf("\n Enter -1 to end");
      printf("\n Enter the data :");
      scanf("%d",&num);
    
      while(num != -1)
      {
       new_node=(struct node *)malloc(sizeof(struct node));
       new_node->data=num;
       if(start==NULL)
       {
         new_node->next=NULL;
         start=new_node;
       }
       else
       {
            ptr=start;
        
            while(ptr->next != NULL)
                ptr=ptr->next;
        
            ptr->next=new_node;
            new_node->next=NULL;
        }
        printf("\n Enter the data :");
        scanf("%d",&num);
    }
    return start;
}

struct node * display(struct node *start)
{
  struct node *ptr;
  ptr=start;

  while(ptr != NULL)
  {

    printf("%d \t",ptr->data);
    ptr=ptr->next;
  }
  return start;
}
struct node * palin(struct node *start)
{
  struct node *ptr;
  ptr=start;
  int d;
  int s=0, s1=0;

  while(ptr != NULL)
  {

    d=ptr->data;
    s=(s*10)+d;
    ptr=ptr->next;
  }
  struct node *prev = NULL;
  struct node *current = start;
  struct node *next;
  while(current!=NULL)
  {
    next = current->next;
    current->next = prev;
    prev=current;
    current=next;
  }
  start = prev;
  ptr=start;

  while(ptr != NULL)
  {
    printf("%d \t",ptr->data);
    ptr=ptr->next;
  }
  ptr=start;
  int d1;

  while(ptr != NULL)
  {

    d1=ptr->data;
    s1=(s1*10)+d1;
    ptr=ptr->next;
  }
  printf("\n");
  if(s1==s)
  {
    printf("Linked list is palindrome\n");
  }
  else
  {
    printf("Linked list is not palindrome\n");
  }
  return start;
}

