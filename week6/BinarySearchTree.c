

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct Node *left;
    struct Node *right;
}Node；
typedef Node *NodePtr;

void insert(NodePtr *,int data);

void inorder(NodePtr);

int main(){
	
    NodePtr start=NULL;
    int data;

    while(scanf("%d",&data)!=EOF)
         insert(&start,data);
    

    inorder(start);
}

void insert(NodePtr *sPtr,int data)
{
    if(*sPtr==NULL)
    {
        *sPtr=malloc(sizeof(Node));
        (*sPtr)->data=data;
        (*sPtr)->left=NULL;
        (*sPtr)->right=NULL;
    }

    else
    {
        if(data<(*sPtr)->data)
        {
            insert(&((*sPtr)->left),data);
        }
        else if(data>(*sPtr)->data)
        {
            insert(&((*sPtr)->right),data);
        }
    }
}

void inorder(NodePtr start)
{
    if(start!=NULL)
    {
        inorder(start->left);
        printf("%d\n",start->data);
        inorder(start->right);
    }
}



