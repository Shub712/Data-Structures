// DOUBLY CIRCULAR LIKEDLIST

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

class DoublyCL
{
    private node first;
    private node last;
    private int iCount;

   public DoublyCL()
    {
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    public void InsertFirst(int No)
    {
        node newn = null;
        newn = new node(No);

        if(this.first == null && this.last==null)
        {
            this.first = newn;
            this.last = newn;
        }

        else 
        {
            newn.next = this.first;
            this.first = newn;
        }

        this.last.next = this.first;
        this.first.prev = this.last;

        iCount++;
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
            newn.prev = this.last;
            newn.next = this.first;
            this.last.next = newn;
            this.last = newn;
        }

        this.last.next = this.first;
        this.first.prev = this.last;

        iCount++;
    }

    public void DeleteFirst()
    {
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
            this.first = this.first.next;
            this.first.prev = null;
        }
        this.last.next = this.first;
        this.first.prev = this.last;

        iCount--;
        System.gc();
    }

    public void DeleteLast()
    {
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
            this.last = this.last.prev;
            this.last.next = null;
        }

        this.last.next = this. first;
        this.first.prev = this.last;

        iCount--;
        System.gc();
    }

    public void Display()
    {
        node temp = null;

        temp = this.first;

        System.out.print("<=>");
        do
        {
            System.out.print("| "+temp.data+"| <=>");
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
        node newn = null;
        node temp =  null;
        int iCnt = 0;

        if(Pos<1 || Pos>iCount+1)
        {
            System.out.println("Invalid Position");
            return;
        }

        if(Pos == 1)
        {
            this.InsertLast(No);
        }

        else if(Pos == iCount+1)
        {
            this.InsertLast(No);
        }

        else
        {
            newn = new node(No);
            temp = this.first;

            for(iCnt =1 ; iCnt<Pos-1; iCnt++)
            {
                temp = temp .next;
            }

            newn.next = temp.next;
            newn.next.prev = newn;
            temp.next = newn;

            iCount++;
        }
    }

    public void DeleteAtPos(int Pos)
    {
        node temp =  null;
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

            for(iCnt =1 ; iCnt<Pos-1; iCnt++)
            {
                temp = temp .next;
            }

            temp.next = temp.next.next;
            temp.next.prev = null;
            System.gc();
            temp.next.prev = temp;

            iCount--;
        }
    }

}

class program449
{
    public static void main(String A [])
    {
        DoublyCL obj = null;
        int iRet = 0;

        obj = new DoublyCL();

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
        
        obj=null;
        System.gc();

    }
}