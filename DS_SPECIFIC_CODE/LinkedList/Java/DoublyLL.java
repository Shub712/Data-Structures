// DOUBLY LINEAR LIKEDLIST

import org.w3c.dom.Node;

class node
{
    public int data;
    public node next;
    public node prev;

    public node(int No)
    {
        this.data = No;
        this.next = null;
        this.prev = null;
    }

}

class DoublyLL
{
    private node first;
    private int iCount;

   public DoublyLL()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void InsertFirst(int No)
    {
        node newn = null;
        newn = new node(No);

        if(this.first == null)
        {
            this.first = newn;
        }
        
        else
        {
            newn.next = this.first;
            this.first.prev = newn;
            this.first = newn;
        }

        iCount++;

    }

    public void InsertLast(int No)
    {
        node newn = null;
        newn = new node(No);
        node temp = null;
        
        if(this.first == null)
        {
            this.first = newn;
        }

        else if(this.first.next == null)
        {
            newn.next = this.first;
            this.first.prev = newn;
            this.first = newn;
        }

        else
        {
            temp = this.first;

            while (temp.next != null) 
            {
                temp = temp.next;
            }
            temp.next = newn;
            newn.prev = temp;
        }

        iCount++;
    }

    public void DeleteFirst()
    {
        if(this.first == null)
        {
            return;
        }

        else if(this.first.next == null)
        {
            this.first = null;
        }

        else
        {
            this.first = this.first.next;
            this.first.prev = null;
        }

        System.gc();
        iCount--;

    }

    public void DeleteLast()
    {
        node temp = null;

        if(this.first == null)
        {
            return;
        }

        else if(this.first.next == null)
        {
            this.first = this.first.next;
            this.first.prev = null;
        }
        else
        {
            temp = this.first;

            while(temp.next.next != null)
            {
                temp = temp.next;
            }

            temp.next = null;
        }

        System.gc();

        iCount--;
    }

    public void Display()
    {
        node temp = null;
        temp = this.first;

        System.out.print("NULL<=>");
        while (temp != null) 
        {
            System.out.print("| "+temp.data+"| <=>");
            temp = temp.next;   
        }
        System.out.println("NULL");
    }

    public int Count()
    {
        return this.iCount;
    }

    public void InsertAtPos(int No, int Pos)
    {
        node newn = null;
        node temp = null;

        int iCnt = 0;

        if(Pos<1 || Pos>iCount+1)
        {
            System.out.println("Invalid Position");
            return;
        }

        if(Pos == 1)
        {
            this.InsertFirst(No);
        }

        else if(Pos == iCount+1)
        {
            this.InsertLast(No);
        }

        else
        {
            newn = new node(No);
            temp = this.first;

            for(iCnt = 1; iCnt<Pos-1; iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next = newn;
            newn.prev = temp;

            iCount++;
        }
    }

    public void DeleteAtPos(int Pos)
    {
        node temp = null;
        node target = null;

        int iCnt = 0;

        if(Pos<1 || Pos>iCount)
        {
            System.out.println("Invalid Position");
            return;
        }

        if(Pos == 1)
        {
            this.DeleteFirst();
        }

        else if(Pos == iCount)
        {
            this.DeleteLast();
        }

        else
        {
            temp = this.first;

            for(iCnt = 1; iCnt<Pos-1; iCnt++)
            {
                temp = temp.next;
            }

            target = temp.next;
            temp.next= target.next;
            temp.next.prev = temp;

            target = null;

            System.gc();

            iCount--;
        }
    }

}

class program450
{
    public static void main(String A [])
    {
        DoublyLL obj = null;
        int iRet = 0;

        obj = new DoublyLL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.Display();
        
        iRet = obj.Count();
        System.out.println("The Number of nodes are :"+iRet);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);

        obj.Display();
        
        iRet = obj.Count();
        System.out.println("The Number of nodes are :"+iRet);

        obj.DeleteFirst();

        obj.Display();
        
        iRet = obj.Count();
        System.out.println("The Number of nodes are :"+iRet);

        obj.DeleteLast();

        obj.Display();
        
        iRet = obj.Count();
        System.out.println("The Number of nodes are :"+iRet);

        obj.InsertAtPos(105, 4);

        obj.Display();
        
        iRet = obj.Count();
        System.out.println("The Number of nodes are :"+iRet);

        obj.DeleteAtPos(4);

        obj.Display();
        
        iRet = obj.Count();
        System.out.println("The Number of nodes are :"+iRet);
        
        // Important for memory deallocation
        obj=null;
        System.gc();

    }
}