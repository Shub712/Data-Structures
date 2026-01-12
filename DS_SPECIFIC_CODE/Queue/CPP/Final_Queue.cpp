/////////////////////////////////////////////////////////////////
// FINAL CODE OF QUEUE 
/////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

#pragma pack(1)
class Queuenode
{
    public :
        int data;
        Queuenode *next;

        Queuenode(int no)
        {
            this -> data  = no;
            this -> next = NULL;
        }
};

class Queue
{
    private:
        Queuenode *first;
        Queuenode *last;
        int iCount;

        public:
            Queue();

            void Enqueue(int);    
            int Dequeue();          
            void Display();
            int Count();
};

Queue :: Queue()
{
    cout<<"Queue gets created successfully\n";
    this -> first = NULL;
    this -> last = NULL;
    this -> iCount = 0; 
}

void Queue :: Enqueue(int no)
{
    Queuenode *newn = NULL;

    newn = new Queuenode(no);

    if(this -> first == NULL && this -> last == NULL)
    {
        this -> first = newn;
        this -> last = newn;
    }
    else
    {
        this -> last -> next = newn;
        this -> last = newn;
    }

    this -> iCount++;
} 

int Queue :: Dequeue()
{
    int Value = 0;
    Queuenode *temp =  this -> first;

    if(this -> first== NULL && this -> last == NULL)
    {
        cout<<"Queue is empty\n";
        return -1;
    }

    Value = this -> first -> data;

    if(this -> first -> next == NULL)
    {
        delete this -> first;
        this -> first = NULL;
        this -> last = NULL;
    }
    
    else
    {
        this -> first = this -> first -> next;
        delete temp;
    }

    this -> iCount--;
    return Value;
}

void Queue :: Display()
{
    Queuenode *temp = this -> first;

    if(this -> first == NULL && this -> last == NULL)
    {
        cout<<"queue is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"| "<<temp ->data<<" | - ";
        temp = temp -> next;
    }
    cout<<"\n";
}

int Queue :: Count()
{
    return this -> iCount;
}

int main()
{
    Queue *qobj = new Queue();

    qobj -> Enqueue(11);
    qobj -> Enqueue(21);
    qobj -> Enqueue(51);
    qobj -> Enqueue(101);

    qobj -> Display();
    cout<<"Number of elements in queue are : "<<qobj->Count()<<"\n";

    cout<<"Removed elements is : "<<qobj->Dequeue()<<"\n";
    qobj -> Display();
    cout<<"Number of elements in queue  are : "<<qobj->Count()<<"\n";

    cout<<"Removed elements is : "<<qobj->Dequeue()<<"\n";
    qobj -> Display();
    cout<<"Number of elements in queue  are : "<<qobj->Count()<<"\n";

    qobj -> Enqueue(121);

    qobj -> Display();
    cout<<"Number of elements in queue  are : "<<qobj->Count()<<"\n";
    
    delete qobj;
    
    return 0;
}