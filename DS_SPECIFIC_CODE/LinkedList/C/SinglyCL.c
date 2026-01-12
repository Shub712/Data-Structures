// SINGLY CIRCULAR LINKEDLIST

#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first, PPNODE last, int No)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = No;
    newn -> next = NULL;

    if((*first == NULL) && (*last == NULL)) 
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn -> next = *first;
        *first = newn;
    }

    (*last) -> next = *first;    

}

void InsertLast(PPNODE first, PPNODE last, int No)
{

    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = No;
    newn -> next = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        (*last) -> next = newn; 
        *last = newn;           
    }

    (*last)-> next = *first;

}


void DeleteFirst(PPNODE first, PPNODE last)
{
    PNODE temp = NULL;

    if((*first == NULL) && (*last == NULL)) 
    {
        return;
    }

    else if(*first == *last)                
    {
        free(*first);

        *first = NULL;
        *last = NULL;
    }
    else                                    
    {
        temp = *first;

        *first = (*first) -> next;
        free(temp);
        (*last) -> next = *first;
    }

}

void DeleteLast(PPNODE first, PPNODE last)
{
    PNODE temp = NULL;

    if((*first == NULL) && (*last == NULL)) 
    {
        return;
    }

    else if(*first == *last)                
    {
        free(*first);

        *first = NULL;
        *last = NULL;
    }
    else                                   
    {
        temp = *first;
        
        while(temp -> next != *last)
        {
            temp = temp -> next;
        }

        free(*last);

        *last = temp;

        (*last)-> next = *first;
    }
}



void Display(PNODE first, PNODE last)
{
    do
    {
        printf("| %d | -> ",first -> data );
        first = first -> next;
    }while(first != last-> next);

    printf("\n");
}

int Count(PNODE first, PNODE last )
{
    int iCount = 0;

    do
    {
        iCount++;
        first = first -> next;
    }while(first != last-> next);

    printf("\n");
    return iCount;
}

void InsertAtPos(PPNODE first, PPNODE last, int No, int pos)
{
    int iSize = 0;
    int iCnt = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    iSize = Count(*first, *last);

    if((pos < 1) || (pos > iSize+1))
    {
        printf("Invalid position");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first,last,No);
    }

    else if(pos == iSize+1)
    {
        InsertLast(first, last, No);
    }

    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn -> data = No;
        newn -> next = NULL;

        temp = *first;

        for(iCnt =1; iCnt< (pos-1); iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;
    }


}

void DeleteAtPos(PPNODE first, PPNODE last, int pos)
{

    int iSize = 0;
    int iCnt = 0;

    PNODE temp = NULL;
    PNODE target = NULL;

    iSize = Count(*first, *last);

    if(pos<1 || pos>iSize)
    {
        printf("Invalid position");
        return;
    }

    if(pos ==1)
    {
        DeleteFirst(first,last);
    }

    else if(pos == iSize)
    {
        DeleteLast(first, last);
    }

    else
    {
       
        temp = *first;

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp-> next;
        }

        target = temp -> next;
        temp -> next = target -> next;
        free(target);
      
    }
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;  // @

    int iRet = 0;

    InsertFirst(&head, &tail, 51);
    InsertFirst(&head, &tail, 21);
    InsertFirst(&head, &tail, 11);

    InsertLast(&head, &tail, 101);
    InsertLast(&head, &tail, 111);
    InsertLast(&head, &tail, 121);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("The Number of nodes are :%d\n", iRet);

    DeleteFirst(&head, &tail);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("The Number of nodes are :%d\n", iRet);

    DeleteLast(&head, &tail);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("The Number of nodes are :%d\n", iRet);

    InsertAtPos(&head,&tail,334,3);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("The Number of nodes are :%d\n", iRet);

    DeleteAtPos(&head,&tail,3);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("The Number of nodes are :%d\n", iRet);

  
    return 0;
}