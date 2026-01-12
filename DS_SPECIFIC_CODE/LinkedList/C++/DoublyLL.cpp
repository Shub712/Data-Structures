//  DOUBY LINEAR LINKED LIST

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

class DoublyLL
{
    private:
        PNODE first;
        int iCount;

    public:
        DoublyLL()
        {
            cout<<"Object of DoublyCL gets created\n";
            this-> first = NULL;
            this -> iCount = 0;
        }

        void InsertFirst(int No)
        {
            PNODE newn = NULL;
            newn = new NODE;

            newn -> data = No;
            newn -> next = NULL;
            newn -> prev = NULL;

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

        void InsertLast(int No)
        {
            PNODE temp = NULL;

            PNODE newn = NULL;
            newn = new NODE;
            
            newn -> data = No;
            newn -> next = NULL;
            newn -> prev = NULL;

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

        void DeleteFirst()
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

        void DeleteLast()
        {
            PNODE temp = NULL;

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

        void Display()
        {
            PNODE temp = NULL;

            temp = this -> first;

            cout<<"NULL";
            while(temp != NULL)
            {
                cout<<"| "<<temp -> data<<" | -> ";
                temp =temp -> next;
            }
            cout<<"NULL\n";
        }

        int Count()
        {
            return iCount;
        }

        void InsertAtPos(int No, int pos)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            int iCnt = 0;

            if(pos<1 || pos> this ->iCount + 1)
            {
                cout<<"Invalid Postion\n";
                return;
            }

            if(pos == 1)
            {
                this -> InsertFirst(No);
            }

            else if(pos == iCount + 1)
            {
                this -> InsertLast(No);
            }

            else
            {
                newn = new NODE;

                temp = this-> first;

                newn -> data = No;
                newn -> next = NULL;
                newn -> prev = NULL;

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

        void DeleteAtPos(int pos)
        {
            
            PNODE target = NULL;
            PNODE temp = NULL;

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

};

int main()
{

    DoublyLL obj;
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