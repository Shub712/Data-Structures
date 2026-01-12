
#include<iostream>
using namespace std;

template <class T>  
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode<T> *next;
        DoublyLLLnode<T> *prev;

        DoublyLLLnode(T no)
        {
            this -> data = no;
            this -> next = NULL;
            this -> prev = NULL;
        }
};

template <class T>
class DoublyLLL
{
    private:           
        struct DoublyLLLnode<T> *first;
        int iCount;

    public:
        DoublyLLL();
        void InsertFirst(T); 
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T , int);
        void DeleteAtPos(int pos);

};

template <class T>
DoublyLLL<T>::DoublyLLL()
{
    this->first = NULL;
    this-> iCount = 0;
}

template <class T>
void DoublyLLL<T>::InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;

    newn = new DoublyLLLnode<T>(no);;
    
    if(this -> first == NULL)
    {
        this -> first = newn;
    }

    else 
    {
        newn -> next = this->first;
        this-> first ->prev = newn;
        this -> first = newn;
    }

    iCount ++;
}

template <class T>
void  DoublyLLL<T>::InsertLast(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }

    else if(this->first -> next == NULL)
    {
        newn -> next = this -> first;
        this -> first -> prev = newn;
        this -> first = newn;
    }

    else
    {
        temp = this -> first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
        newn -> prev = temp;
    }

    iCount++;
            
}

template <class T>
void  DoublyLLL<T>::DeleteFirst()
{
    if(this -> first == NULL)
    {
        return;
    }

    else if(this -> first -> next == NULL)
    {
        delete this -> first;
        this -> first = NULL;
    }

    else 
    {
        this -> first = this -> first -> next;
        delete this -> first -> prev;
        this -> first -> prev = NULL;
    }

    iCount --;
}

template <class T>
void  DoublyLLL<T>::DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;

    if(this -> first == NULL)
    {
        return;
    }

    else if(this -> first -> next == NULL)
    {
        delete this -> first;
        this -> first = NULL;
    }

    else
    {
        temp = this -> first;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        delete temp -> next;
        temp -> next = NULL;
    }

    iCount --;
}

template <class T>
void  DoublyLLL<T>::Display()
{
    DoublyLLLnode<T> *temp = NULL;
    temp = this -> first;

    cout<<"NULL";
    while(temp != NULL)
    {
        cout<<"| "<<temp -> data<<" | -> ";
        temp =temp -> next;
    }
    cout<<"NULL\n";
}

template <class T>
int DoublyLLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLLL<T>::InsertAtPos(T no, int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *newn = NULL;

    int iCnt = 0;

    if(pos<1 || pos> this ->iCount + 1)
    {
        cout<<"Invalid Postion\n";
        return;
    }

    if(pos == 1)
    {
        this -> InsertFirst(no);
    }

    else if(pos == iCount + 1)
    {
        this -> InsertLast(no);
    }

    else
    {
        newn = new DoublyLLLnode<T>(no);

        temp = this-> first;

        for(iCnt =1 ; iCnt< pos -1; iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;
        newn -> prev = temp;

        iCount ++;
    }
}

template <class T>
void  DoublyLLL<T>::DeleteAtPos( int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *target = NULL;

    int iCnt = 0;

    if(pos<1 || pos > this ->iCount )
    {
        cout<<"Invalid Postion\n";
        return;
    }

    if(pos == 1)
    {
        this -> DeleteFirst();
    }

    else if(pos == iCount + 1)
    {
        this -> DeleteLast();
    }

    else
    {
        temp = this-> first;

        for(iCnt =1 ; iCnt< pos -1; iCnt++)
        {
            temp = temp -> next;
        }

        target = temp -> next;
        temp -> next = target -> next;
        temp -> next -> prev = temp;

        delete target;

        iCount--;
    }
        
}

int main()
{

    DoublyLLL<int> *obj = new DoublyLLL<int>();
    int iRet  = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj->InsertAtPos(105,4);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";
    
    obj->DeleteFirst();

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj->DeleteLast();

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj->DeleteAtPos(4);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    return 0;
}