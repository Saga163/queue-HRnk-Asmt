#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node {
    int no;
    int time;
    struct node * next;
} * e;

e f=NULL;
e r=NULL;

void read()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    e temp = (e)malloc(sizeof(struct node));
    
        scanf("%d%d",&temp->no,&temp->time);
        if(f==NULL){
            f=r=temp;
        }
        else{
            r->next = temp;
            r=temp;
        }
    }
    
}

void display(){
    int t,m;
    char T[5],M[5];
    scanf("%s%d%s%d",T,&t,M,&m);
    t=t*m;
    e cur=f;
    while(cur!=r->next){
        cur->time-=t;
        cur=cur->next;
    }

    int flag=0;
    cur=f;
    while(cur!=r->next)
    {
        if(cur->time>0){
            printf("%d %d\n",cur->no,cur->time);
            flag=1;
        }
        cur=cur->next;

    }
    if(flag==0)
        printf("Queue Empty\n");
    cur=f;
    flag=0;
    printf("Ready Queue\n");
    int a[50];
    int l=0;
    int cnt=0;
    while(cur!=r->next)
    {
        if(cur->time<=0){
            a[l]=cur->no;
            cnt++;
            l++;
            flag=1;
        }
        cur=cur->next;

    }
    if(flag==0)
        printf("Queue Empty");
    
    for(l=cnt-1;l>=0;l--){
        printf("%d 0\n",a[l]);
    }
}

int main(){
    read();
    display();
    return 0;
}
