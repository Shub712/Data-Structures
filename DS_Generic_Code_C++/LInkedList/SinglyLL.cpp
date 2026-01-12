#include<iostream>

using namespace std;

template <class T>  
struct SinglyLLnode
{
    T data;
    struct SinglyLLnode<T> *next;
};

template <class T>
class SinglyLL
{
    private:           
        struct SinglyLLnode<T> *first;
        int iCount;

    public:
        SinglyLL();
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
SinglyLL<T>::SinglyLL()
{
    this->first = NULL;
    this-> iCount = 0;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct SinglyLLnode<T> *newn = NULL;

    newn = new struct SinglyLLnode<T>;

    newn -> data = No;
    newn -> next = NULL;
    
    newn -> next = this->first;
    this->first = newn;

    this->iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct SinglyLLnode<T> *newn = NULL;
    struct SinglyLLnode<T> *temp = NULL;

    newn = new struct SinglyLLnode<T>;

    newn->data = No;
    newn->next = NULL;

    if(this->iCount == 0)  
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
    }

    this->iCount++;
            
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct SinglyLLnode<T> *temp = NULL;

    if(this->first == NULL)
    {
        return;
    }

    else if(this->first -> next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }

    else
    {
        temp = this->first;
        this->first = this->first -> next;
        delete temp;
    }

    this->iCount --;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct SinglyLLnode<T> *temp = NULL;

    if(this->first == NULL)
    {
        return;
    }

    else if(this->first -> next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }

    else
    {
        temp = this->first;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        delete temp -> next;
        temp -> next = NULL;
    }

    this->iCount--;
}

template <class T>
void SinglyLL<T>::Display()
{
    struct SinglyLLnode<T> *temp = NULL;
    int iCnt = 0;

    temp = this->first;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)   
    {
        cout<<"|"<<temp -> data<<"|->";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int pos)
{
    struct SinglyLLnode<T> *temp = NULL;
    struct SinglyLLnode<T> *newn = NULL;

    int iCnt = 0;

    if(pos<1 || pos > this->iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos==1)
    {
        this->InsertFirst(No);
    }

    else if(pos == this->iCount+1)
    {
        this->InsertLast(No);
    }

    else 
    {
        newn = new struct SinglyLLnode<T>;
        temp = this->first;

        newn->data = No;
        newn -> next = NULL;

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;

        this->iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteAtPos( int pos)
{
    struct SinglyLLnode<T> *temp = NULL;
    struct SinglyLLnode<T> *target = NULL;

    int iCnt = 0;

    if(pos<1 || pos>this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }

    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }

    else 
    {
        temp = this->first;

        for(iCnt = 1; iCnt<pos-1; iCnt++)
        {
            temp = temp -> next;
        }
        
        target = temp -> next;
        temp->next = target -> next;
        delete target;

        this->iCount--;
    }
}

int main()
{

    SinglyLL<int> obj;
    int iRet  = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.InsertAtPos(105,4);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj.DeleteFirst();

    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj.DeleteAtPos(4);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    return 0;
}