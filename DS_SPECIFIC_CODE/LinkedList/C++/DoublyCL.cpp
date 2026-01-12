//  DOUBLY CIRCULAR LINKED LIST

#include<iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyCL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:
        DoublyCL()
        {
            cout<<"Object of DoublyCL gets created\n";
            this-> first = NULL;
            this-> last = NULL;
            this -> iCount = 0;
        }

        void InsertFirst(int No)
        {
            PNODE newn = NULL;
            newn = new NODE;

            newn -> data = No;
            newn -> next = NULL;
            newn -> prev = NULL;

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

        void InsertLast(int No)
        {
            PNODE newn = NULL;
            newn = new NODE;

            newn -> data = No;
            newn -> next = NULL;
            newn -> prev = NULL;

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

        void DeleteFirst()
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

        void DeleteLast()
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

        void Display()
        {
            PNODE temp = NULL;

            temp = this->first;

            cout<<" <=> ";
            do
            {
                cout<<"| "<<temp -> data<<"| <=>";
                temp = temp -> next;
            }while(temp != this->last -> next);

            cout<<"\n";
        }

        int Count()
        {
            return iCount;
        }

        void InsertAtPos(int No, int pos)
        {
            PNODE temp = NULL;
            PNODE newn = NULL;

            int iCnt = 0;

            if(pos<1 || pos> iCount+1)
            {
                cout<<"Invalid position";
                return;
            }

            if(pos == 1)
            {
                this -> InsertFirst(No);
            }

            else if(pos == iCount+1)
            {
                this -> InsertLast(No);
            }

            else
            {
                newn = new NODE;

                newn -> data = No;
                newn -> next = NULL;
                newn -> prev = NULL;
                
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

        void DeleteAtPos(int pos)
        {
            PNODE temp = NULL;

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

};

int main()
{

    DoublyCL obj;
    int iRet  = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj.DeleteFirst();

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj.InsertAtPos(105,4);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";
    
    obj.DeleteAtPos(4);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    return 0;
}