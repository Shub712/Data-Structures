#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Enqueue(PPNODE first,PPNODE last, int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = No;
    newn -> next = NULL;

    if((*first) == NULL && (*last) == NULL)
    {
        *first = newn;
        *last = newn;
    }

    else
    {
        (*last) -> next = newn;
        (*last) = newn;
    }

}

int Dequeue(PPNODE first, PPNODE last)
{
    int iValue = 0;
    PNODE temp = NULL;

    if(*first == NULL && *last == NULL)
    {
        printf("The Queue is empty\n");
        return-1;
    }

    iValue = (*first) -> data;

    if((*first) -> next == NULL)
    {
        free((*first));
        *first = NULL;
        *last = NULL;  
    }

    else
    {
        temp = (*first);
        *first = (*first) -> next;
        free(temp);
    }

    return iValue;
}

void Display(PNODE first, PNODE last)
{
    if(first == NULL && last == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    while(first!= NULL)
    {
        printf("| %d | -",first -> data);
        first = first -> next;
    }
    printf("\n");
}

int Count(PPNODE first, PPNODE last)
{
    PNODE temp = NULL;
    int iCount = 0;

    temp = *first;  

    while (temp != NULL)
    {
        iCount ++;
        temp = temp -> next;
    }
    
    return iCount;
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    int iRet = 0;

    Enqueue(&head,&tail,51);
    Enqueue(&head,&tail,21);
    Enqueue(&head,&tail,11);
    Enqueue(&head,&tail,10);

    Display(head,tail);

    Dequeue(&head,&tail);

    Display(head,tail);

    printf("The Number of nodes are in the queue is : %d\n", Count(&head, &tail));

    return 0;
}