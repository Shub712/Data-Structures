#include<iostream>

using namespace std;

template <class T>  
class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode<T> *next;
        DoublyCLLnode<T> *prev;

    DoublyCLLnode(T no)
    {
        this -> data = no;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

template <class T>
class DoublyCLL
{
    private:           
        struct DoublyCLLnode<T> *first;
        struct DoublyCLLnode<T> *last;
        int iCount;

    public:
        DoublyCLL();
        void InsertFirst(T No); 
        void InsertLast(T No);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T No, int pos);
        void DeleteAtPos(int pos);

};

template <class T>
DoublyCLL<T>::DoublyCLL()
{
    this->first = NULL;
    this->last = NULL;
    this-> iCount = 0;
}

template <class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    DoublyCLLnode<T> *newn = NULL;

    newn = new DoublyCLLnode<T>(no);
    
    if(this -> first == NULL && this -> last == NULL)
    {
        this -> first = newn;
        this -> last = newn;
    }

    else
    {
        newn -> next = this ->first;
        this -> first -> prev = newn;
        this -> first = newn; 
    }

    this -> last -> next = this -> first;
    this -> first -> prev = this -> last;

    iCount ++;
}

template <class T>
void  DoublyCLL<T>::InsertLast(T no)
{
    DoublyCLLnode<T> *newn = NULL;
    DoublyCLLnode<T> *temp = NULL;

    newn = new DoublyCLLnode<T>(no);

    if(this -> first == NULL && this -> last == NULL)
    {
        this -> first = newn;
        this -> last = newn;
    }

    else
    {
        this -> last -> next = newn;
        newn -> prev = this -> last;
        this ->last = newn;
    }

    this -> last -> next = this -> first;
    this -> first ->prev = this -> last;

    iCount++;
            
}

template <class T>
void  DoublyCLL<T>::DeleteFirst()
{
    if(this -> first == NULL && this -> last == NULL)
    {
        return;
    }

    else if(this -> first == this -> last)
    {
        delete this -> first;
        this -> first = NULL;
        this -> last = NULL;
    }

    else
    {
        this -> first = this -> first -> next;
        delete this -> first -> prev;

        this -> last -> next = this -> first;
        this -> first -> prev =  this -> last;
    }

    iCount --;
}

template <class T>
void  DoublyCLL<T>::DeleteLast()
{
    if(this -> first == NULL && this -> last == NULL)
    {
        return;
    }

    else if(this -> first == this -> last)
    {
        delete this -> first;
        this -> first = NULL;
        this -> last = NULL;
    }

    else
    {
        this -> last = this -> last -> prev;
        delete this -> last -> next;
    }

    this -> first -> prev = this -> last;
    this -> last -> next = this -> first;

    iCount --;
}

template <class T>
void  DoublyCLL<T>::Display()
{
    DoublyCLLnode<T> *temp = NULL;
    temp = this -> first;

    temp = this->first;

    cout<<" <=> ";
    do
    {
        cout<<"| "<<temp -> data<<"| <=>";
        temp = temp -> next;
    }while(temp != this->last -> next);

    cout<<"\n";
}

template <class T>
int DoublyCLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCLL<T>::InsertAtPos(T no, int pos)
{
    DoublyCLLnode<T> *temp = NULL;
    DoublyCLLnode<T> *newn = NULL;

    int iCnt = 0;

    if(pos<1 || pos> iCount+1)
    {
        cout<<"Invalid position";
        return;
    }

    if(pos == 1)
    {
        this -> InsertFirst(no);
    }

    else if(pos == iCount+1)
    {
        this -> InsertLast(no);
    }

    else
    {
        newn = new DoublyCLLnode<T>(no);
        
        temp = this -> first;

        for(iCnt = 1; iCnt<pos-1; iCnt ++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        newn -> prev = temp;
        
        temp -> next -> prev  = newn;
        temp -> next = newn;

        iCount ++;
    }
}

template <class T>
void  DoublyCLL<T>::DeleteAtPos(int pos)
{
    DoublyCLLnode<T> *temp = NULL;

    int iCnt = 0;

    if(pos<1 || pos> iCount)
    {
        cout<<"Invalid position";
        return;
    }

    if(pos == 1)
    {
        this -> DeleteFirst();
    }

    else if(pos == iCount)
    {
        this -> DeleteLast();
    }

    else
    {
        temp = this -> first;

        for(iCnt = 1; iCnt<pos-1; iCnt ++)
        {
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        delete temp -> next -> prev;
        temp -> next -> prev = temp;

        iCount --;
    }
        
}

int main()
{

    DoublyCLL<int> *obj = new DoublyCLL<int>();
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

