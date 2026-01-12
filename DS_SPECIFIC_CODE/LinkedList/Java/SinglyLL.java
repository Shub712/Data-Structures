// complete singly LL

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


class SinglyLL
{
    private node first;
    private int iCount;

    SinglyLL()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void InsertFirst(int No)
    {
        node newn = null;

        newn = new node(No);

        newn.next = first;
        first = newn;

        this.iCount++;
    }

    public void InsertLast(int No)
    {
        node newn = null;
        newn = new node(No);

        if(this.first==null)
        {
            this.first = newn;
        }

        else
        {
            node temp  = null;

            temp = first;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.next = newn;
        }

        this.iCount++;
    }

    public void DeleteFirst()
    {
        node temp = null;
        if(this.first == null)
        {
            return;
        }

        else
        {
            this.first = first.next;
        }
        System.gc();

        this.iCount --;

    }

    public void DeleteLast()
    {
        if(this.first == null)
        {
            return;
        }
        else if(this.first.next == null)
        {
            this.first = this.first.next;

        }

        else
        {
            node temp = null;
            temp = this.first;

            while(temp.next.next != null)
            {
                temp = temp.next;
            }
            temp.next = null;
            System.gc();
        }
        this.iCount --;
    }

    public void Display()
    {
        node temp = null;

        temp = this.first;

        while(temp!=null)
        {
            System.out.print("! "+temp.data+" |->");
            temp= temp.next;
        }
        System.out.println("null");
    }

    public int Count()
    {
        return this.iCount;
    }

    public void InsertAtPos(int No,int pos)
    {
        node newn = null;
        node temp = null;

        int iCnt = 0;

        if(pos<1 || pos>this.iCount+1)
        {
            System.out.println("Inavalid postition");
            return;
        }

        if(pos == 1)
        {
            this.InsertFirst(No);
        }

        else if(pos == iCount+1)
        {
            this.InsertLast(No);
        }

        else
        {
            newn = new node(No);

            temp = this.first;

            for(iCnt =1; iCnt<pos-1; iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next = newn;
           this. iCount++;
        }
    }

    public void DeleteAtPos(int pos)
    {
        node temp = null;
        int iCnt = 0;

        if(pos<1 || pos>this.iCount)
        {
            System.out.println("Inavalid postition");
            return;
        }

        if(pos == 1)
        {
            this.DeleteFirst();
        }

        else if(pos == iCount)
        {
            this.DeleteLast();
        }

        else
        {
            temp = this.first;

            for(iCnt =1; iCnt< (pos-1); iCnt++)
            {
                temp = temp.next;
            }
            
            temp.next= temp.next.next;

            System.gc();
            this.iCount--;
        }
    }

}

class practiceds5
{
    public static void main(String A[])
    {
        SinglyLL obj = null;
        int iRet = 0;
        obj = new SinglyLL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        iRet = obj.Count();
        System.out.println("The number od nodes are :"+iRet);
        obj.Display();

        obj.InsertLast(111);
        obj.InsertLast(121);
        obj.InsertLast(151);

        iRet = obj.Count();
        System.out.println("The number od nodes are :"+iRet);
        obj.Display();

        obj.DeleteFirst();

        iRet = obj.Count();
        System.out.println("The number od nodes are :"+iRet);
        obj.Display();

        obj.DeleteLast();

        iRet = obj.Count();
        System.out.println("The number od nodes are :"+iRet);
        obj.Display();

        obj.InsertAtPos(105, 3);

        iRet = obj.Count();
        System.out.println("The number od nodes are :"+iRet);
        obj.Display();

        obj.DeleteAtPos(3);

        iRet = obj.Count();
        System.out.println("The number od nodes are :"+iRet);
        obj.Display();

        obj=null;
        System.gc();

    }
}