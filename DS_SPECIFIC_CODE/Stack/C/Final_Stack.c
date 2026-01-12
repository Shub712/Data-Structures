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

void Push(PPNODE first, int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(PNODE));

    newn -> data = No;
    newn -> next = NULL;

    newn -> next = *first;
    *first = newn;
    
}

int Pop(PPNODE first)
{
    int Value = 0;
    PNODE temp = NULL;

    if(*first == NULL)
    {
        printf("The Stack is empty\n");
        return -1;
    }

    temp = *first;
    Value = (*first) -> data;
    *first = (*first) -> next;
    free(temp);

    return Value;
}

int Peep(PNODE first)
{
    int Value = 0;

    if(first == NULL)
    {
        printf("The Stack is Empty\n");
        return -1;
    }

    Value = first -> data;

    return Value;
}

void Display(PNODE first)
{
    if(first == NULL)
    {   
        printf("The Stack is Empty\n");
        return;
    }

    while (first != NULL)
    {
        printf("| %d |\n", first ->data);
        first = first -> next;
    }

    
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    Push(&head,51);
    Push(&head,21);
    Push(&head,11);

    Display(head);

    Pop(&head);
    printf("----------------------------\n");
    Display(head);

    iRet = Peep(head);

    printf("return value of peep is : %d\n", Peep(head));

    return 0;
}