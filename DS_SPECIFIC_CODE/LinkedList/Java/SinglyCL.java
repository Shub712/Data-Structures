// SINGLY CIRCULAR LIKEDLIST

class node
{
    public int data;
    public node next;

    public node(int No)
    {
        this.data = No;
        this.next = null;
    }

}

class SinglyCL
{
    private node first;
    private node last;
    private int iCount;

    public SinglyCL()
    {

        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    public void InsertFirst(int No)
    {
        node newn = null;
        newn = new node(No);

        if(this.first == null && this.last == null)
        {
            this.first = newn;
            this.last = newn;
        }

        else
        {
            newn.next = this.first;
            this.first = newn;
            this.last.next = this.first;
        }
        
        this.iCount++;
    }

    public void InsertLast(int No)
    {
        node newn = null;

        newn = new node(No);

        if(this.first == null && this.last == null)
        {
            this.first = newn;
            this.last = newn;
        }

        else
        {
            this.last.next = newn;
            this.last = newn;
        }

        this.last.next = this.first;
        this.iCount++;
    }

    public void DeleteFirst()
    {
        if(this.first == null && this.last==null)
        {
            return;
        }
        else if(this.first == this.last)
        {
            this.first = null;
            this.last = null;
        }

        else
        {
            this.first = this.first.next;
            this.last.next = this.first;
        }

        System.gc();

        this.iCount--;
    }

    public void DeleteLast()
    {
        node temp = null;
        if(this.first == null && this.last == null)
        {
            return;
        }

        else if(this.first == this.last)
        {
            this.first = null;
            this.last = null;
        }

        else
        {
            temp = this.first;

            while(temp.next != this.last)
            {
                temp = temp.next;
            }

            this.last = null;
            this.last = temp;
        }

        this.last.next = this.first;

        System.gc();

        this.iCount--;

    }

    public void Display()
    {
        node temp = null;

        temp = this.first;

        do
        {
            System.out.print("| "+temp.data+"| ->");
            temp = temp.next;
        }while(temp != this.last.next);

        System.out.println();
    }

    public int Count()
    {
        return this.iCount;
    }

    public void InsertAtPos(int No, int Pos)
    {
        int iCnt = 0;
        node newn = null;
        node temp = null;

        if(Pos<1 || Pos>this.iCount+1)
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

           newn.next= temp.next;
           temp.next = newn;

           this.iCount++;
        }
    }

    public void DeleteAtPos(int Pos)
    {
        int iCnt = 0;
        node temp = null;
        node target = null;

        if(Pos<1 || Pos>this.iCount)
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
           temp.next = target.next;

           target = null;
           System.gc();
           this.iCount--;
        }
    }

}

class program447
{
    public static void main(String A [])
    {
        SinglyCL obj = null;
        int iRet = 0;

        obj = new SinglyCL();

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