/////////////////////////////////////////////////////////////////
// FINAL CODE OF QUEUE USING GENERIC APPROACH
/////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

#pragma pack(1)

template <class T>
class Queuenode
{
    public :
        T data;
        Queuenode <T> *next;

        Queuenode(T no)
        {
            this -> data  = no;
            this -> next = NULL;
        }
};

template <class T>
class Queue
{
    private:
        Queuenode <T> *first;
        Queuenode <T> *last;
        int iCount;

        public:
            Queue();

            void Enqueue(T);     
            T Dequeue();          
            void Display();
            int Count();
};

template <class T>
Queue <T>:: Queue()
{
    cout<<"Queue gets created successfully\n";
    this -> first = NULL;
    this -> last = NULL;
    this -> iCount = 0; 
}

template <class T>
void Queue <T> :: Enqueue(T no)
{
    Queuenode <T> *newn = NULL;

    newn = new Queuenode<T>(no);

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

template <class T>
T Queue <T> :: Dequeue()
{
    T Value = 0;
    Queuenode <T> *temp =  this -> first;

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

template <class T>
void Queue <T> :: Display()
{
    Queuenode <T> *temp = this -> first;

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

template <class T>
int Queue <T> :: Count()
{
    return this -> iCount;
}

int main()
{
    Queue <int> *qobj = new Queue <int>();

    int iChoice = 0;
    int Value = 0;
    int iRet = 0;



    while(1)
    {
        cout<<"-------------------------------------------------\n";
        cout<<"----------Please Select The Option----------------\n";

        cout<<"1 : Insert new element into the queue\n";
        cout<<"2 : Remove new element into the queue\n";
        cout<<"3 : Display the elements of the queue\n";
        cout<<"4 : Count the number of elementsthe from the queue\n";
        cout<<"0 : Exit The Application\n";

        cin>>iChoice;
        cout<<"-------------------------------------------------\n";
        
        switch(iChoice)
        {
            case 1 : 
                cout<<"Enter the element That u want to insert : \n";
                cin>>Value;
                qobj->Enqueue(Value);
                cout<<"Elements gets inserted successfully\n";
                break;

            case 2 :
                iRet = qobj -> Dequeue();
                if(iRet != -1)
                {
                    cout<<"Element removed from queue is : "<<iRet<<"\n";
                }
                break;

            case 3 :
                cout<<"Elements of the queue are : \n";
                qobj->Display();
                break;

            case 4 :
                iRet = qobj->Count();
                cout<<"Number of elements in the queue are :"<<iRet<<"\n";
                break;
            case 0 :
                cout<<"Thank you for using our Application\n";
                delete qobj;
                return 0;

                default:
                    cout<<"Please Enter The valid option\n";

                    //End of switch
        }
    } // End of while;
    
    return 0;

    // end of main
}