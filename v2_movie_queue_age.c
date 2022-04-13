#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int x=0,p=0;

typedef struct sll
{
    char name[20];
    int n;
    struct sll *next;
}  *node;
 node insert(node head);
node getnode ();
 node pos(node head);
 void display(node head);


int main()
{
   
   node head =NULL;
    int N,K;
    scanf("%d %d",&N,&K);
    if(N==0)
    {
        printf("N should be greater than 0");
        exit(0);
    }
    
    
  for(int j=0;j<N;j++)
  {
       head=insert(head);
  }    
        display(head);
        head=pos(head);
    
    printf("%d\n%d",(N-x)*300,x*300);
    return 0;
}

node getnode ()
 {
     node new1;
     new1=(node) malloc(sizeof (struct sll));
     new1->next=NULL;
     scanf("%s %d",new1->name,&new1->n);
    if(new1->n>=18&&new1->n<=25)
    {
        x+=1;
        return new1;
    }
     else{
         return 0;
     }
 }
  node insert(node head)
 {
     node cur=head;
     node new1=getnode();
     if(new1==0){
         return head;
     }
     if(head==NULL)
     return new1;
      
     while(cur->next!=NULL)
     {
         cur=cur->next;
     }
     cur->next=new1;
     new1->next=NULL;
     return head;
 }
 node pos(node head)
 {
     char h[20];
     int flag=0;
     scanf("%s",h);
 node cur=head;
     node new1=getnode();
     if(head==NULL)
     return new1;
     while(cur!=NULL)
      { 
         p++;
         if((strcmp(h,cur->name))==0)
         {
             printf("%d\n",p);
             flag=1;
         }
         cur=cur->next; 
     }
     if(flag==0)
     {
         printf("%d\n",flag);
     }
     return head;
 }
 void display(node head)
{
    node cur;
    if(head==NULL)
    printf("list is empty\n");
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            printf("%s %d\n",cur->name,cur->n);
            cur=cur->next;
        }
    }
}
