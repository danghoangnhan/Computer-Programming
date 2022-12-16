
#include <stdlib.h>
#include<stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node,*NodePtr,*Stack;

void push(Stack *,int);
void pop(Stack *);

int main(){
    Stack st=NULL;
    int data;

    while(scanf("%d",&data)!=EOF)
    {
        push(&st,data);
    }

    while(st!=NULL)
    {
        printf("%d\n",st->data);
        pop(&st);
    }

}

void push(Stack *st,int data)
{
    NodePtr newPtr;

    newPtr=malloc(sizeof(Node));

    newPtr->data=data;

    newPtr->next=*st;

    *st=newPtr;
}

void pop(Stack *st)
{
    if(st==NULL) return ;

    NodePtr currentPtr=NULL;

    currentPtr=*st;

    *st=(*st)->next;
    printf("%d\n",currentPtr->data);

    free(currentPtr);
}
